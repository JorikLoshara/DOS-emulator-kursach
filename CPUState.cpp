#include "CPUState.h"



CPUState::CPUState()
{
	IP = PROGRAM_BASE_OFFSET;
	SP = 0xFFF5;
}

CPUState::~CPUState()
{
	for (auto iter = segmentTable.begin(); iter != segmentTable.end(); iter++)
		delete iter->second;
}

void CPUState::SetSegmentAndSelectorAsTinyMemoryModelSpecialForDOSDUDOSBecauseItUsesOnlyThis(Segment * seg, WORD sel)
{
	CS = DS = SS = FS = GS = ES = sel;
	segmentTable[sel] = seg;
}

Segment * CPUState::GetSegment(WORD sel)
{
	return segmentTable[sel];
}

void CPUState::AddSegment(Segment* seg, WORD sel)
{
	segmentTable[sel] = seg;
}

WORD * CPUState::GetRegistersAsArray()
{
	return &AX;
}

BYTE* CPUState::GetCurrentInstructionAddr()
{
	return segmentTable[CS]->memory + IP;
}

void CPUState::Push(WORD word)
{
	SP -= 2;
	*(WORD*)(segmentTable[SS]->memory + SP) = word;
}

WORD CPUState::Pop()
{
	WORD ret = *(WORD*)(segmentTable[SS]->memory + SP);
	SP += 2;
	return ret;
}

WORD CPUState::GetWordByAddr(WORD addr)
{
	return *(WORD*)(segmentTable[DS]->memory + addr);
}

BYTE CPUState::GetByteByAddr(WORD addr)
{
	return *(BYTE*)(segmentTable[DS]->memory + addr);
}

BYTE* CPUState::GetNextInstruction()
{
	return segmentTable[CS]->GetBaseAddr() + IP;
}

void CPUState::IncreaseIP(int offset)
{
	IP += offset;
}

void CPUState::SetAX(WORD iw)
{
	AX = iw;
}

void CPUState::SetBX(WORD iw)
{
	BX = iw;
}

void CPUState::SetCX(WORD iw)
{
	CX = iw;
}

void CPUState::SetDX(WORD iw)
{
	DX = iw;
}

void CPUState::SetSI(WORD iw)
{
	SI = iw;
}

void CPUState::SetDI(WORD iw)
{
	DI = iw;
}

void CPUState::SetSP(WORD iw)
{
	SP = iw;
}

void CPUState::SetBP(WORD iw)
{
	BP = iw;
}

void CPUState::SetIP(WORD iw)
{
	IP = iw;
}

void CPUState::SetCS(WORD iw)
{
	CS = iw;
}

void CPUState::SetDS(WORD iw)
{
	DS = iw;
}

void CPUState::SetSS(WORD iw)
{
	SS = iw;
}

void CPUState::SetES(WORD iw)
{
	ES = iw;
}

void CPUState::SetFS(WORD iw)
{
	FS = iw;
}

void CPUState::SetGS(WORD iw)
{
	GS = iw;
}

void CPUState::SetAH(BYTE ib)
{
	*((BYTE*)&AX + 1) = ib;
}

void CPUState::SetAL(BYTE ib)
{
	*((BYTE*)&AX) = ib;
}

void CPUState::SetBH(BYTE ib)
{
	*((BYTE*)&BX + 1) = ib;
}

void CPUState::SetBL(BYTE ib)
{
	*((BYTE*)&BX) = ib;
}

void CPUState::SetCH(BYTE ib)
{
	*((BYTE*)&CX + 1) = ib;
}

void CPUState::SetCL(BYTE ib)
{
	*((BYTE*)&CX) = ib;
}

void CPUState::SetDH(BYTE ib)
{
	*((BYTE*)&DX + 1) = ib;
}

void CPUState::SetDL(BYTE ib)
{
	*((BYTE*)&DX) = ib;
}

WORD CPUState::GetAX()
{
	return AX;
}

WORD CPUState::GetBX()
{
	return BX;
}

WORD CPUState::GetCX()
{
	return CX;
}

WORD CPUState::GetDX()
{
	return DX;
}

WORD CPUState::GetSI()
{
	return SI;
}

WORD CPUState::GetDI()
{
	return DI;
}

WORD CPUState::GetSP()
{
	return SP;
}

WORD CPUState::GetBP()
{
	return BP;
}

WORD CPUState::GetIP()
{
	return IP;
}

WORD CPUState::GetCS()
{
	return CS;
}

WORD CPUState::GetDS()
{
	return DS;
}

WORD CPUState::GetSS()
{
	return SS;
}

WORD CPUState::GetES()
{
	return ES;
}

WORD CPUState::GetFS()
{
	return FS;
}

WORD CPUState::GetGS()
{
	return GS;
}

BYTE CPUState::GetAH()
{
	return *((BYTE*)&AX + 1);
}

BYTE CPUState::GetAL()
{
	return *((BYTE*)&AX);
}

BYTE CPUState::GetBH()
{
	return *((BYTE*)&BX + 1);
}

BYTE CPUState::GetBL()
{
	return *((BYTE*)&BX);
}

BYTE CPUState::GetCH()
{
	return *((BYTE*)&CX + 1);
}

BYTE CPUState::GetCL()
{
	return *((BYTE*)&CX);
}

BYTE CPUState::GetDH()
{
	return *((BYTE*)&DX + 1);
}

BYTE CPUState::GetDL()
{
	return *((BYTE*)&DX);
}



bool CPUState::GetZeroFlag()
{
	return (bool) (flags & (1 << 6));
}

bool CPUState::GetCarryFlag()
{
	return (bool)(flags & (1 << 0));
}

bool CPUState::GetOverflowFlag()
{
	return (bool)(flags & (1 << 11));
}

bool CPUState::GetParityFlag()
{
	return (bool)(flags & (1 << 2));
}

bool CPUState::GetSignFlag()
{
	return (bool)(flags & (1 << 7));
}

bool CPUState::GetDirectionFlag()
{
	return (bool)(flags & (1 << 10));
}

void CPUState::SetZeroFlag(bool state)
{
}

void CPUState::SetCarryFlag(bool state)
{
}

void CPUState::SetOverflowFlag(bool state)
{
}

void CPUState::SetParityFlag(bool state)
{
}

void CPUState::SetSignFlag(bool state)
{
}

void CPUState::SetDirectionFlag(bool state)
{
}

