#ifndef type_h
#define type_h

typedef unsigned char		BYTE;
typedef unsigned short		WORD;
typedef unsigned long		DWORD;
typedef BYTE				*PBYTE;
typedef WORD				*PWORD;
typedef DWORD				*PDWORD;

typedef unsigned int		ULONG32, *PULONG32;
typedef unsigned __int64	ULONG64, *PULONG64;
typedef unsigned long		ULONG;
typedef ULONG				*PULONG;
typedef unsigned short		USHORT;
typedef USHORT				*PUSHORT;
typedef unsigned char		UCHAR;
typedef UCHAR				*PUCHAR;
typedef void				VOID;
typedef void				*PVOID;

typedef wchar_t				WCHAR;

#define _OUT_  
#define _IN_  
#define _IN_OUT_  

typedef PVOID				HANDLE;
typedef HANDLE				*PHANDLE;

#endif // !type_h
