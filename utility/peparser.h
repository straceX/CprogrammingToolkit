#ifndef PEPARSER_H
#define PEPARSER_H

#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_image_file_header(void);
void print_image_optional_file_header(void);
void print_image_section_headers(void);
void exit_sys(LPCSTR lpszMsg, int status);
void exit_usr(LPCSTR lpszMsg, int status);

/* Global Data Definitions */

void *g_imageAddr;
IMAGE_DOS_HEADER *g_dosHeader;
IMAGE_FILE_HEADER *g_imageFileHeader;
IMAGE_OPTIONAL_HEADER32 *g_imageOptionalHeader;
IMAGE_SECTION_HEADER *g_sectionHeaders;

#endif // PEPARSER_H
