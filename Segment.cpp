#include "Segment.h"
//#include "Opcodes.h"


Segment::Segment()
{
	((BYTE*)this)[0] = 0xCD;//int 20 exit
	((BYTE*)this)[1] = 0x20;

	for (int i = 2; i < SEGMENT_SIZE; i++)
		((BYTE*)this)[i] = 0;
}


Segment::~Segment()
{
	
}


BYTE* Segment::GetBaseAddr()
{
	return memory;
}

BYTE* Segment::GetProgramAddr()
{
	return memory + PROGRAM_BASE_OFFSET;
}
/*
WORD Segment::GetWordByAddr(WORD addr)
{
	WORD result = *(WORD*)(GetBaseAddr() + addr);
	return result;
}

BYTE Segment::GetByteByAddr(WORD addr)
{
	BYTE result = *(BYTE*)(GetBaseAddr() + addr);
	return result;
}
*/