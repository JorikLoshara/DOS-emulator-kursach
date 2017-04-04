#pragma once

typedef unsigned char BYTE;
typedef unsigned short WORD;
const size_t SEGMENT_SIZE = 65536;
const int PROGRAM_BASE_OFFSET = 0x100;


class Segment
{
public:
	BYTE memory[SEGMENT_SIZE];
	Segment();
	~Segment();
	BYTE* GetBaseAddr();
	BYTE* GetProgramAddr();
	WORD GetWordByAddr(WORD addr);
	BYTE GetByteByAddr(WORD addr);
};

