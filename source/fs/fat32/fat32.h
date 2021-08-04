#ifndef FAT32_h
#define FAT32_h

#include <type.h>
#include <tystatus.h>


typedef struct fat32
{
	BYTE diskNumber;
	BYTE partNumber;

	WORD bytesPerSector;
	BYTE sectorsPerCluster;
	WORD reservedSector;
	BYTE numOfFAT;

	BYTE typeOfDisk;

} HANDLE_FAT32;

#endif // !FAT32_h
