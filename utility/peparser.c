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
			printf("\t%s\n", characteristicsNames[iter]);
		characteristics >>= 1;
	}
}

void print_image_optional_file_header(void)
{
    int iter;
    const char *dataDirectoryNames[] = { "Export Directory", "Import Directory", "Resource Directory", "Exception Directory", "Certificates Directory",	"Base Relocation Directory", 
                                         "Debug Directory", "Architecture Directory", "Global Pointer Directory", "Thread Storage Directory", "Load Configuration Directory",
                                         "Bound Import Directory", "Import Address Table Directory", "Delay Import Directory", "COM Descriptor Directory", "Reserved Directory" 
                                       };
	
		
	printf("\n--------------------------------------------------\n");
	printf("\t\tIMAGE_OPTINAL_HEADER\n");
	printf("--------------------------------------------------\n\n");

	printf("Magic: 0x%04X\n", g_imageOptionalHeader->Magic);
	printf("MajorLinkerVersion: %02d\n", g_imageOptionalHeader->MajorLinkerVersion);
	printf("MinorLinkerVersion: %02d\n", g_imageOptionalHeader->MinorLinkerVersion);
	printf("SizeOfCode: %lu (0x%08lX)\n", g_imageOptionalHeader->SizeOfCode, g_imageOptionalHeader->SizeOfCode);
	printf("SizeofInitializedData: %lu (0x%08lX)\n", g_imageOptionalHeader->SizeOfInitializedData, g_imageOptionalHeader->SizeOfInitializedData);
	printf("SizeofUninitializedData: %lu (0x%08lX)\n", g_imageOptionalHeader->SizeOfUninitializedData, g_imageOptionalHeader->SizeOfUninitializedData);
	printf("AddressOfEntryPoint: 0x%08lX\n", g_imageOptionalHeader->AddressOfEntryPoint);
	printf("BaseOfCode: 0x%08lX\n", g_imageOptionalHeader->BaseOfCode);
	printf("BaseOfData: 0x%08lX\n", g_imageOptionalHeader->BaseOfData);
	printf("ImageBase: 0x%08lX\n", g_imageOptionalHeader->ImageBase);
	printf("SectionAlignment: %lu (0x%08lX)\n", g_imageOptionalHeader->SectionAlignment, g_imageOptionalHeader->SectionAlignment); 
	printf("FileAlignment: %lu (0x%08lX)\n", g_imageOptionalHeader->FileAlignment, g_imageOptionalHeader->FileAlignment);
	printf("MajorOperatingSystemVersion: %02d\n", g_imageOptionalHeader->MajorOperatingSystemVersion);
	printf("MinorOperatingSystemVersion: %02d\n", g_imageOptionalHeader->MinorOperatingSystemVersion);
	printf("MajorImageVersion: %d\n", g_imageOptionalHeader->MajorImageVersion);
	printf("MinorImageVersion: %d\n", g_imageOptionalHeader->MinorImageVersion);
	printf("MajorSubsystemVersion: %d\n", g_imageOptionalHeader->MajorSubsystemVersion);
	printf("MinorSubsystemVersion: %d\n", g_imageOptionalHeader->MinorSubsystemVersion);
	printf("Win32VersionValue: %lu\n", g_imageOptionalHeader->Win32VersionValue);
	printf("SizeofImage: %lu (0x%lX)\n", g_imageOptionalHeader->SizeOfImage, g_imageOptionalHeader->SizeOfImage);
	printf("SizeofHeaders: %lu (0x%lX)\n", g_imageOptionalHeader->SizeOfHeaders, g_imageOptionalHeader->SizeOfHeaders);
	printf("Checksum: %lu (0x%lX)\n", g_imageOptionalHeader->CheckSum, g_imageOptionalHeader->CheckSum);
	printf("Subsystem: %lu\n", g_imageOptionalHeader->Subsystem);
	printf("SizeOfStackReserve: %lu (0x%lX)\n", g_imageOptionalHeader->SizeOfStackReserve, g_imageOptionalHeader->SizeOfStackReserve);
	printf("SizeOfStackCommit: %lu (0x%lX)\n", g_imageOptionalHeader->SizeOfStackCommit, g_imageOptionalHeader->SizeOfStackCommit);
	printf("SizeOfHeapReserve: %lu (0x%lX)\n", g_imageOptionalHeader->SizeOfHeapReserve, g_imageOptionalHeader->SizeOfHeapReserve);
	printf("SizeOfHeapCommit: %lu (0x%lX)\n", g_imageOptionalHeader->SizeOfHeapCommit, g_imageOptionalHeader->SizeOfHeapCommit);
	printf("NumberOfRvaAndSizes: %lu\n", g_imageOptionalHeader->NumberOfRvaAndSizes);

	printf("\n--------------------\n");
	printf("\tData Directories\n");
	printf("--------------------\n");
	for (iter = 0; iter < (int)g_imageOptionalHeader->NumberOfRvaAndSizes; ++iter) 
		printf("%s:\n\tRVA: 0x%08X, Size: 0x%08lX\n", dataDirectoryNames[iter], g_imageOptionalHeader->DataDirectory[iter].VirtualAddress, g_imageOptionalHeader->DataDirectory[iter].Size);
}

void print_image_section_headers(void)
{
    int iter, jiter;
	const char *flagNames[32] = {"", "", "", "", "", "IMAGE_SCN_CNT_CODE", "IMAGE_SCN_CNT_INITIALIZED_DATA", "IMAGE_SCN_CNT_UNINITIALIZED_ DATA",
		"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "IMAGE_SCN_MEM_DISCARDABLE", "", "", "", 
		"IMAGE_SCN_MEM_EXECUTE", "IMAGE_SCN_MEM_READ", "IMAGE_SCN_MEM_WRITE" };

	printf("\n--------------------\n");
	printf("\tSection Headers\n");
	printf("--------------------\n");

	for (iter = 0; iter < g_imageFileHeader->NumberOfSections; ++iter)
    {
		printf("Name: %s\n", g_sectionHeaders[iter].Name);
		printf("VirtualSize: %lu (0x%08lX)\n", g_sectionHeaders[iter].Misc.VirtualSize, g_sectionHeaders[iter].Misc.VirtualSize);
		printf("VirtualAddress: 0x%08lX\n", g_sectionHeaders[iter].VirtualAddress); 
		printf("SizeOfRawData: %lu (0x%08lX)\n", g_sectionHeaders[iter].SizeOfRawData, g_sectionHeaders[iter].SizeOfRawData);
		printf("PointerToRawData: 0x%08lX (%lu)\n", g_sectionHeaders[iter].PointerToRawData, g_sectionHeaders[iter].PointerToRawData);
		printf("PointerToRelocations: 0x%08lX (%lu)\n", g_sectionHeaders[iter].PointerToRelocations, g_sectionHeaders[iter].PointerToRelocations);
		printf("PointerToLinenumbers: 0x%08lX (%lu)\n", g_sectionHeaders[iter].PointerToLinenumbers, g_sectionHeaders[iter].PointerToLinenumbers);
		printf("NumberOfRelocations: 0x%08lX (%lu)\n", g_sectionHeaders[iter].NumberOfRelocations, g_sectionHeaders[iter].NumberOfRelocations);
		printf("NumberOfLinenumbers: 0x%08lX (%lu)\n", g_sectionHeaders[iter].PointerToLinenumbers, g_sectionHeaders[iter].PointerToLinenumbers);
		printf("Characteristics: 0x%08lX\n", g_sectionHeaders[iter].Characteristics);

		for (jiter = 0; jiter < 32; ++jiter)
			if (g_sectionHeaders[iter].Characteristics >> jiter & 1)
				printf("\t%s\n", flagNames[jiter]);
	}
}

void print_export_directory(void)
{
    time_t time;
	struct tm *ptime;
	char *str;
	DWORD iter;
	DWORD *names,*functions;
	WORD *ordinals;
	char *exportName;
		
	printf("\n--------------------\n");
	printf("\tExport Directory\n");
	printf("---------------------\n");
	printf("Characteristics: 0x%08x\n", g_exportDirectory->Characteristics);

	time = g_exportDirectory->TimeDateStamp;
	ptime = localtime(&time);

	printf("TimeDateStamp: %02d/%02d/%4d %02d:%02d:%02d\n", ptime->tm_mday, ptime->tm_mon + 1, ptime->tm_year + 1900,
		ptime->tm_hour, ptime->tm_min, ptime->tm_sec);

	printf("MajorVersion: %d\n", g_exportDirectory->MajorVersion);
	printf("MinorVersion: %d\n", g_exportDirectory->MinorVersion);
	
    str = ((char *)g_imageAddr + RVAToFileOffset(g_exportDirectory->Name));
	
    printf("Name: RVA=0x%08lx (%s)\n", g_exportDirectory->Name, str);
	printf("Base: %ld\n", g_exportDirectory->Base);
	printf("NumberOfFunctions: %ld\n", g_exportDirectory->NumberOfFunctions);
	printf("NumberOfNames: %ld\n", g_exportDirectory->NumberOfNames);
	printf("AddressOfFunctions: 0x%08lx\n", g_exportDirectory->AddressOfFunctions);
	printf("AddressOfNames: 0x%08lx\n", g_exportDirectory->AddressOfNames);
	printf("AddressOfNameOrdinals: 0x%08lx\n\n", g_exportDirectory->AddressOfNameOrdinals);

	names = (DWORD *)((BYTE *)g_imageAddr + RVAToFileOffset(g_exportDirectory->AddressOfNames));
	ordinals = (WORD *)((BYTE *)g_imageAddr + RVAToFileOffset(g_exportDirectory->AddressOfNameOrdinals));
	functions = (DWORD *)((BYTE *)g_imageAddr + RVAToFileOffset(g_exportDirectory->AddressOfFunctions));
	
	for (iter = 0; i < g_exportDirectory->NumberOfFunctions; ++iter) {
		exportName = (char *)g_imageAddr + RVAToFileOffset(names[iter]);
		printf("Hint: %lu, Ordinal: %lu, Name: %s (RVA: 0x%08lX), Exported RVA: 0x%08lX\n",
			i, ordinals[iter] + g_exportDirectory->Base, exportName, names[iter], 
			functions[ordinals[iter]]);
	}
}

void print_import_directory(void);
{
    time_t time;
	struct tm *ptime;
	char *moduleName;
	int iter, jiter;
	DWORD *addressTableRVA;
	BYTE *lookupTableEntry;
	DWORD *addressTable;
		
	printf("\n--------------------\n");
	printf("\tImport Directory Entries\n");
	printf("--------------------\n");

	for (iter = 0; g_importDirectoryEntries[iter].Name != 0; ++iter) {
		printf("Import Lookup Table RVA: 0x%08lX\n", g_importDirectoryEntries[iter].OriginalFirstThunk);

		time = g_importDirectoryEntries[iter].TimeDateStamp;
		ptime = localtime(&time);
		printf("TimeDateStamp: %02d/%02d/%4d %02d:%02d:%02d\n", ptime->tm_mday, ptime->tm_mon + 1, ptime->tm_year + 1900,
			ptime->tm_hour, ptime->tm_min, ptime->tm_sec);
		printf("ForwardChain: %lu (0x%08lX)\n", g_importDirectoryEntries[iter].ForwarderChain, g_importDirectoryEntries[iter].ForwarderChain);
		moduleName = (char *)g_imageAddr + RVAToFileOffset(g_importDirectoryEntries[iter].Name);
		printf("Name: %s (RVA: 0x%08lX)\n", moduleName, g_importDirectoryEntries[iter].Name);
		printf("Import Address Table RVA: 0x%08lX\n", g_importDirectoryEntries[iter].FirstThunk);
		printf("\n");
		printf("Imported Symbols:\n");
		
		addressTableRVA = (DWORD *)g_importDirectoryEntries[iter].FirstThunk;
		addressTable = (DWORD *)((BYTE *)g_imageAddr + RVAToFileOffset(g_importDirectoryEntries[iter].FirstThunk));
		for (jiter = 0; addressTable[jiter] != 0; ++jiter) {
			if (addressTable[jiter] & 0x80000000)
				printf("\tSlot Address: 0x%08lX, Slot Value: 0x%08X, Ordinal: %d\n", addressTableRVA + k, addressTable[jiter], LOWORD(addressTable[jiter]));
			else {
				lookupTableEntry = (BYTE *)g_imageAddr + RVAToFileOffset(addressTable[jiter]);
				printf("\tSlot Address: 0x%08lX, Slot Value: 0x%08lX, Hint: %lu (0x%04lX), %s\n", addressTableRVA + jiter, addressTable[jiter], *(WORD *)lookupTableEntry, *(WORD *)lookupTableEntry, lookupTableEntry + 2);
			}
		}
	
		printf("\n");
	}
}

DWORD RVA_to_file_offset(DWORD rva)
{
    int iter;
	for (iter = 0; iter < g_imageFileHeader->NumberOfSections; ++iter) 
		if (rva >= g_sectionHeaders[iter].VirtualAddress && rva < g_sectionHeaders[iter].VirtualAddress + g_sectionHeaders[iter].Misc.VirtualSize)
			return rva - g_sectionHeaders[iter].VirtualAddress + g_sectionHeaders[iter].PointerToRawData;

	return 0;
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