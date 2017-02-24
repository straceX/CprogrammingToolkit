#include <peparser.h>

void print_image_file_header(void)
{
    time_t time;
	struct tm *ptime;
	int i;
	DWORD characteristics;
	static const char *characteristicsNames[] = { "IMAGE_FILE_RELOCS_STRIPPED", "IMAGE_FILE_EXECUTABLE_IMAGE", "IMAGE_FILE_LINE_NUMS_STRIPPED", "IMAGE_FILE_LOCAL_SYMS_STRIPPED",
	"IMAGE_FILE_AGGRESSIVE_WS_TRIM", "IMAGE_FILE_LARGE_ADDRESS_ AWARE", "", "IMAGE_FILE_BYTES_REVERSED_LO", "IMAGE_FILE_32BIT_MACHINE", "IMAGE_FILE_DEBUG_STRIPPED",
	"IMAGE_FILE_REMOVABLE_RUN_ FROM_SWAP", "IMAGE_FILE_NET_RUN_FROM_SWAP", "IMAGE_FILE_SYSTEM", "IMAGE_FILE_DLL", "IMAGE_FILE_UP_SYSTEM_ONLY", "IMAGE_FILE_BYTES_REVERSED_HI" };

	printf("\n--------------------------------------------------\n");
	printf("\t\tIMAGE_FILE_HEADER\n");
	printf("--------------------------------------------------\n");

	printf("Machine: 0x%04X\n", g_imageFileHeader->Machine);
	printf("NumberOfSections: %d (0x%04X)\n", g_imageFileHeader->NumberOfSections, g_imageFileHeader->NumberOfSections);
	
	time = g_imageFileHeader->TimeDateStamp;
	ptime = localtime(&time);
	
	printf("Time Date Stamp: %02d/%02d/%4d %02d:%02d:%02d\n", ptime->tm_mday, ptime->tm_mon + 1, ptime->tm_year + 1900,ptime->tm_hour, ptime->tm_min, ptime->tm_sec);

	printf("Pointer To Symbol Table: 0x%08X\n", g_imageFileHeader->PointerToSymbolTable);
	printf("Number Of Symbols: 0x%08X\n", g_imageFileHeader->NumberOfSymbols);
	printf("Sizeof Image Optional Header: %lu (0x%08X)\n", g_imageFileHeader->SizeOfOptionalHeader, g_imageFileHeader->SizeOfOptionalHeader);

	characteristics = g_imageFileHeader->Characteristics;
	printf("Characteristics (0x%08X):\n", characteristics);
	for (i = 0; characteristics; ++i) {
		if (characteristics & 1) 
			printf("\t%s\n", characteristicsNames[i]);
		characteristics >>= 1;
	}
}

void print_image_optional_file_header(void)
{

}

void print_image_section_headers(void)
{

}

void print_export_directory(void)
{

}

void print_import_directory(void);
{

}

DWORD RVA_to_file_offset(DWORD rva)
{

}
void exit_sys(LPCSTR lpszMsg, int status)
{
    DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(status);
}

void exit_usr(LPCSTR lpszMsg, int status)
{
    fprintf(stderr, "%s\n", lpszMsg);
	exit(status);
}

int test_pe_parser_functions(const char *fname)
{
	HANDLE hFile, hFileMapping;
	DWORD *magicPE;
	
	if (fname || *fname == NULL )
		exit_usr("wrong input!..\n", EXIT_FAILURE);

	if ((hFile = CreateFile(fname, GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL)) == INVALID_HANDLE_VALUE)
		exit_sys("Cannot open file", EXIT_FAILURE);

	hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 0, NULL);
	if (hFileMapping == NULL)
		exit_sys("CreateFileMapping", EXIT_FAILURE);

	g_imageAddr = MapViewOfFile(hFileMapping, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
	if (g_imageAddr == NULL)
		exit_sys("MapViewOfFile", EXIT_FAILURE);

	g_dosHeader = (IMAGE_DOS_HEADER *)g_imageAddr;
	if (g_dosHeader->e_magic != MZ_MAGIC)           /* MZ_MAGIC = 0x5A4D */
		exit_usr("invalid PE file!", EXIT_FAILURE);

	magicPE = (DWORD *)((BYTE *)g_imageAddr + g_dosHeader->e_lfanew);
	if (*magicPE != 0x00004550)       /* PE\0\0 */
		exit_usr("Invalid PE file!", EXIT_FAILURE);

	g_imageFileHeader = (IMAGE_FILE_HEADER *)(magicPE + 1);
	print_image_file_header();

	g_imageOptionalHeader = (IMAGE_OPTIONAL_HEADER32 *)(g_imageFileHeader + 1);
    print_image_optional_file_header();
	
	g_sectionHeaders = (IMAGE_SECTION_HEADER *)((BYTE *)g_imageOptionalHeader + g_imageFileHeader->SizeOfOptionalHeader);
    print_image_section_headers();

	if (g_imageOptionalHeader->DataDirectory[0].VirtualAddress != 0) {
		g_exportDirectory = (IMAGE_EXPORT_DIRECTORY *)((BYTE *)g_imageAddr + RVAToFileOffset(g_imageOptionalHeader->DataDirectory[0].VirtualAddress));
        print_export_directory();
	}

	if (g_imageOptionalHeader->DataDirectory[1].VirtualAddress != 0) {
		g_importDirectoryEntries = (IMAGE_IMPORT_DESCRIPTOR *)((BYTE *)g_imageAddr + RVAToFileOffset(g_imageOptionalHeader->DataDirectory[1].VirtualAddress));
        print_import_directory();
	}
	
	UnmapViewOfFile(g_imageAddr);
	CloseHandle(hFileMapping);
	CloseHandle(hFile);

	return 0;
}