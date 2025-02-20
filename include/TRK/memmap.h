#ifndef METROTRK_MEM_TRK_H
#define METROTRK_MEM_TRK_H
#include "TRK/dstypes.h"
#include "TRK/trk.h"

typedef struct memRange {
	u8* start;
	u8* end;
	BOOL readable;
	BOOL writeable;
} memRange;

const memRange gTRKMemMap[1] = { { (u8*)0, (u8*)-1, TRUE, TRUE } };

#endif
