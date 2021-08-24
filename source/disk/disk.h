#ifndef DISK_H
#define DISK_H

#include <type.h>
#include <tystatus.h>

typedef TYSTATUS(*DIP)(_IN_ BYTE diskNumber, _IN_ BYTE partNumber, _OUT_ char* moreInfo, _OUT_ HANDLE hDisk);
typedef TYSTATUS(*DRF)(_IN_ HANDLE hDisk, _IN_ DWORD LBAStart, _OUT_ PVOID buffer, _IN_ ULONG64 numOfBytesOfBuffer, _IN_OUT_ PULONG64 wannaAndActualReadNumOfSector);
typedef TYSTATUS(*DWF)(_IN_ HANDLE hDisk, _IN_ PVOID buffer, _IN_ ULONG64 numOfBytesOfBuffer, _OUT_ PULONG64 ActualWriteNumOfBytes);
typedef TYSTATUS(*DGI)(_IN_ HANDLE hDisk, _OUT_ PVOID buffer, _IN_ ULONG64 numOfBytesOfBuffer, _IN_ DWORD mode);
typedef TYSTATUS(*DSI)(_IN_ HANDLE hDisk, _OUT_ PVOID buffer, _IN_ ULONG64 numOfBytesOfBuffer, _IN_ DWORD mode);

typedef struct Ddisk
{
	BYTE diskNumber;
	BYTE diskType;

	DIP DiskInit;
	DRF DiskReadSector;
	DWF DiskWriteSector;
	DGI DiskGetDiskInfo;
	DSI DiskSetDiskInfo;
} Ddisk, *PDdisk;


#define diskType_IDE 1


#endif // !DISK_H
