#include <type.h>
#include <tystatus.h>

typedef TYSTATUS(*DIP)(_IN_ BYTE diskNumber, _IN_ BYTE partNumber, _OUT_ char* moreInfo);
typedef TYSTATUS(*DCF)(_IN_ WCHAR* path, _IN_ DWORD mode, _OUT_ PHANDLE hCreate);
typedef TYSTATUS(*DRF)(_IN_ HANDLE hCreate, _OUT_ PVOID buffer, _IN_ ULONG64 numOfBytesOfBuffer, _IN_OUT_ PULONG64 wannaAndActualReadNumOfBytes);
typedef TYSTATUS(*DWF)(_IN_ HANDLE hCreate, _IN_ PVOID buffer, _IN_ ULONG64 numOfBytesOfBuffer, _OUT_ PULONG64 ActualWriteNumOfBytes);
typedef TYSTATUS(*DGI)(_IN_ HANDLE hCreate, _OUT_ PVOID buffer, _IN_ ULONG64 numOfBytesOfBuffer, _IN_ DWORD mode);
typedef TYSTATUS(*DSI)(_IN_ HANDLE hCreate, _OUT_ PVOID buffer, _IN_ ULONG64 numOfBytesOfBuffer, _IN_ DWORD mode);

typedef struct Ddisk
{
	BYTE diskNumber;
	BYTE DiskType;

	FSIP FSInitPartition;
	FSCF FSCreateFile;
	FSRF FSReadFile;
	FSWF FSWriteFile;
	FSQF FSQueryFile;
	FSIF FSGetFileInfo;
} Ddisk;
