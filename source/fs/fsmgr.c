#include <type.h>
#include <tystatus.h>

typedef TYSTATUS (* FSIP)(BYTE diskNumber, BYTE partNumber);	

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

	FSIP FSInitPartition;
} FSpartition;
