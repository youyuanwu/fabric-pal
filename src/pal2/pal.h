#pragma once

#include<stddef.h>

typedef void VOID;
typedef VOID *HANDLE;
#define PALAPI      __attribute__((stdcall))

#define CONST const
#define IN
#define OUT
#define OPTIONAL
#define FAR

#define _W64
#define __int32     int
#define __int16     short int
#define __int8      char        // assumes char is signed
typedef void *PVOID;
typedef void *LPVOID;
typedef CONST void *LPCVOID;
typedef _W64 __int32 LONG_PTR;
typedef _W64 __int32 INT_PTR;
//typedef _W64 unsigned __int32 UINT_PTR;

typedef _W64 __int32 LONG_PTR;
// typedef _W64 unsigned __int32 ULONG_PTR, *PULONG_PTR;
// typedef _W64 unsigned __int32 DWORD_PTR, *PDWORD_PTR;

// typedef _W64 unsigned __int32 ULONG_PTR, *PULONG_PTR;
// typedef _W64 unsigned __int32 DWORD_PTR, *PDWORD_PTR;
//typedef ULONG_PTR SIZE_T, *PSIZE_T;
typedef unsigned int SIZE_T;

typedef LONG_PTR SSIZE_T, *PSSIZE_T;
//typedef ULONG_PTR SIZE_T, *PSIZE_T;
typedef LONG_PTR SSIZE_T, *PSSIZE_T;
typedef unsigned int DWORD; // NOTE: diff from  windows.h, for LP64 compat
typedef int LONG; 
typedef LONG HRESULT;
typedef unsigned int ULONG; // NOTE: diff from windows.h, for LP64 compat
typedef int BOOL;

typedef char CHAR;
typedef CHAR *PCHAR;
typedef CHAR *LPCH, *PCH;
typedef CONST CHAR *LPCCH, *PCCH;
typedef CHAR *NPSTR;
typedef CHAR *LPSTR, *PSTR;
typedef CONST CHAR *LPCSTR, *PCSTR;

typedef wchar_t WCHAR;
typedef WCHAR *PWCHAR;
typedef WCHAR *LPWCH, *PWCH;
typedef CONST WCHAR *LPCWCH, *PCWCH;
typedef WCHAR *NWPSTR;
typedef WCHAR *LPWSTR, *PWSTR;

typedef CONST WCHAR *LPCWSTR, *PCWSTR;

typedef int INT;
typedef unsigned int UINT;
typedef unsigned int *PUINT;
//typedef BYTE BOOLEAN;
//typedef BOOLEAN *PBOOLEAN;
typedef HANDLE HMODULE;

typedef __builtin_va_list va_list;

#define _HRESULT_TYPEDEF_(_sc) ((HRESULT)_sc)
#define S_OK                             _HRESULT_TYPEDEF_(0x00000000L)
#define S_FALSE                          _HRESULT_TYPEDEF_(0x00000001L)

HANDLE
GetProcessHeap();

LPVOID
HeapAlloc(
      IN HANDLE hHeap,
      IN DWORD dwFlags,
      IN SIZE_T dwBytes);

BOOL
HeapFree(
     IN HANDLE hHeap,
     IN DWORD dwFlags,
     IN LPVOID lpMem);

DWORD
GetLastError(
         VOID);


VOID
SetLastError(
         IN DWORD dwErrCode);

HRESULT GetErrorInfo(
  IN  ULONG      dwReserved,
  OUT void **pperrinfo //IErrorInfo
);

HRESULT SetErrorInfo(
  IN           ULONG      dwReserved,
  OUT OPTIONAL void *perrinfo //IErrorInfo
);

HANDLE LoadLibraryA(
  IN LPCSTR lpLibFileName
);


UINT SysStringLen(
  IN PCSTR pbstr
);

typedef INT_PTR (*FARPROC)();

FARPROC
GetProcAddress(
    IN HMODULE hModule,
    IN LPCSTR lpProcName);

void SysFreeString(
  IN PCSTR bstrString
);

BOOL
FreeLibrary(
    IN OUT HMODULE hLibModule);

DWORD
FormatMessageW(
           IN DWORD dwFlags,
           IN LPCVOID lpSource,
           IN DWORD dwMessageId,
           IN DWORD dwLanguageId,
           OUT LPWSTR lpBffer,
           IN DWORD nSize,
           IN va_list *Arguments);
