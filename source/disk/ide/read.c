#include <type.h>
#include <tystatus.h>
#include "..\disk.h"

TYSTATUS IDEReadSector(_IN_ HANDLE hDisk, _IN_ DWORD LBAStart, _OUT_ PVOID buffer, _IN_ ULONG64 numOfBytesOfBuffer, _IN_OUT_ PULONG64 wannaAndActualReadNumOfSector)
{
	PDdisk = hDisk;
	
	if (hDisk->diskType != diskType_IDE)
	{
		return STATUS_DiskMethodUnmatchDiskType;
	}
}