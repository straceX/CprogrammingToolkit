#ifndef PEPARSER_H
#define PEPARSER_H

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MZ_MAGIC	0x5A4D

void print_image_file_header(void);
void print_image_optional_file_header(void);
void print_image_section_headers(void);
void print_export_directory(void);
void print_import_directory(void);

DWORD RVA_to_file_offset(DWORD rva);

void exit_sys(LPCSTR lpszMsg, int status);
void exit_usr(LPCSTR lpszMsg, int status);



void *g_imageAddr;
IMAGE_DOS_HEADER        *g_dosHeader;
IMAGE_FILE_HEADER       *g_imageFileHeader;
IMAGE_OPTIONAL_HEADER32 *g_imageOptionalHeader;
IMAGE_SECTION_HEADER    *g_sectionHeaders;
IMAGE_EXPORT_DIRECTORY  *g_exportDirectory;
IMAGE_IMPORT_DESCRIPTOR *g_importDirectoryEntries;

#endif // PEPARSER_H
