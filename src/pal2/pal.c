#include "pal.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
// #include <stdbool.h>

#define DUMMY_HEAP  0x01020304
#define ERROR_NOT_ENOUGH_MEMORY 8L
#define HEAP_ZERO_MEMORY 0x00000008

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define STATUS_INVALID_DISPOSITION       ((DWORD   )0xC0000026L)

HANDLE
GetProcessHeap(
           VOID)
{
    return (HANDLE)DUMMY_HEAP;
}


LPVOID
HeapAlloc(
      IN HANDLE hHeap,
      IN DWORD dwFlags,
      IN SIZE_T numberOfBytes)
{
    char* mem;
    mem = (char *) malloc(numberOfBytes);
    if (mem == NULL)
    {
        SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        return NULL;
    }
    if (dwFlags == HEAP_ZERO_MEMORY)
    {
        memset(mem, 0, numberOfBytes);
    }
    return (mem);
}


BOOL
HeapFree(
     IN HANDLE hHeap,
     IN DWORD dwFlags,
     IN LPVOID lpMem)
{
    if (lpMem)
    {
        free (lpMem);
    }
    return TRUE;
}

DWORD
GetLastError(
         VOID)
{
    return errno;
}

VOID
SetLastError(
         IN DWORD dwErrCode)
{
    errno = dwErrCode;
}

HRESULT GetErrorInfo(
  IN  ULONG      dwReserved,
  OUT void **pperrinfo //IErrorInfo
){
  return S_FALSE;
}

HANDLE LoadLibraryA(
  IN LPCSTR lpLibFileName
){
  // fail always
  return NULL;
}

UINT SysStringLen(
  IN PCSTR pbstr
){
  return strlen(pbstr);
}

FARPROC
GetProcAddress(
    IN HMODULE hModule,
    IN LPCSTR lpProcName){
  SetLastError(STATUS_INVALID_DISPOSITION);
  return NULL; // fail
}

void SysFreeString(
  IN PCSTR bstrString
){
  // nothing
  SetLastError(STATUS_INVALID_DISPOSITION);
  return;
}

BOOL
FreeLibrary(
    IN OUT HMODULE hLibModule){
  SetLastError(STATUS_INVALID_DISPOSITION);
  return FALSE;
}

DWORD
FormatMessageW(
           IN DWORD dwFlags,
           IN LPCVOID lpSource,
           IN DWORD dwMessageId,
           IN DWORD dwLanguageId,
           OUT LPWSTR lpBffer,
           IN DWORD nSize,
           IN va_list *Arguments)
{
  SetLastError(STATUS_INVALID_DISPOSITION);
  return 0; //fail
}