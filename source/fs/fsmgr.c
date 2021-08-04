#include <type.h>
#include <tystatus.h>

typedef TYSTATUS(*FSIP)(_IN_ BYTE diskNumber, _IN_ BYTE partNumber, _OUT_ PHANDLE hInit);
typedef TYSTATUS(*FSCF)(_IN_ HANDLE hInit, _IN_ WCHAR path, _IN_ DWORD mode, _OUT_ PHANDLE hCreate);
typedef TYSTATUS(*FSRF)(_IN_ HANDLE hCreate, _OUT_ PVOID buffer, _IN_ ULONG64 numOfBytesOfBuffer, _IN_OUT_ PULONG64 wannaAndActualReadNumOfBytes);
typedef TYSTATUS(*FSWF)(_IN_ HANDLE hCreate, _IN_ PVOID buffer, _IN_ ULONG64 numOfBytesOfBuffer, _OUT_ PULONG64 ActualWriteNumOfBytes);
typedef TYSTATUS(*FSQF)(_IN_ HANDLE hCreate, _OUT_ PVOID buffer, _IN_ ULONG64 numOfBytesOfBuffer, _IN_ DWORD mode);
typedef TYSTATUS(*FSIF)(_IN_ HANDLE hCreate, _OUT_ PVOID buffer, _IN_ ULONG64 numOfBytesOfBuffer, _IN_ DWORD mode);

typedef struct disk
{
	BYTE diskNumber;
	BYTE partTotalNum;
	FSpartition* partition;
} FSdisk;

typedef struct partition
{
	BYTE fsType;
	DWORD startLBA;
	DWORD LBATotalNum;
	HANDLE hInit;

	FSIP FSInitPartition;
	FSCF FSCreateFile;
	FSRF FSReadFile;
	FSWF FSWriteFile;
	FSQF FSQueryFile;
	FSIF FSGetFileInfo;
} FSpartition;
