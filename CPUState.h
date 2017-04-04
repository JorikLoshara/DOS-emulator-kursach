#pragma once
#include<map>
#include<iostream>
#include"Segment.h"
typedef unsigned char BYTE;
typedef unsigned short WORD;

const int mod00 = 0;
const int mod01 = 1;
const int mod10 = 2;
const int mod11 = 3;

enum asmResult{
	memChanged,
	notImplemented,
	resultOK,
	programExit
};

class CPUState
{
public:
	CPUState();
	~CPUState();
	void SetSegmentAndSelectorAsTinyMemoryModelSpecialForDOSDUDOSBecauseItUsesOnlyThis(Segment* seg, WORD sel);
	
	BYTE* GetCurrentInstructionAddr();
	void Push(WORD word);
	WORD Pop();
	WORD GetWordByAddr(WORD addr);
	BYTE GetByteByAddr(WORD addr);
	BYTE* GetNextInstruction();
	void IncreaseIP(int offset);

	///////////////////////////////////////
	void SetAX(WORD iw);
	void SetBX(WORD iw);
	void SetCX(WORD iw);
	void SetDX(WORD iw);
	void SetSI(WORD iw);
	void SetDI(WORD iw);
	void SetSP(WORD iw);
	void SetBP(WORD iw);

	void SetIP(WORD iw);

	void SetCS(WORD iw);
	void SetDS(WORD iw);
	void SetSS(WORD iw);
	void SetES(WORD iw);
	void SetFS(WORD iw);
	void SetGS(WORD iw);

	void SetAH(BYTE ib);
	void SetAL(BYTE ib);
	void SetBH(BYTE ib);
	void SetBL(BYTE ib);
	void SetCH(BYTE ib);
	void SetCL(BYTE ib);
	void SetDH(BYTE ib);
	void SetDL(BYTE ib);


	////////////////////////////////////////////////////////////
	WORD GetAX();
	WORD GetBX();
	WORD GetCX();
	WORD GetDX();
	WORD GetSI();
	WORD GetDI();
	WORD GetSP();
	WORD GetBP();

	WORD GetIP();

	WORD GetCS();
	WORD GetDS();
	WORD GetSS();
	WORD GetES();
	WORD GetFS();
	WORD GetGS();

	BYTE GetAH();
	BYTE GetAL();
	BYTE GetBH();
	BYTE GetBL();
	BYTE GetCH();
	BYTE GetCL();
	BYTE GetDH();
	BYTE GetDL();
	/////////////////////////////////////////////////


	bool GetZeroFlag();
	bool GetCarryFlag();
	bool GetOverflowFlag();
	bool GetParityFlag();
	bool GetSignFlag();
	bool GetDirectionFlag();

	void SetZeroFlag(bool state);
	void SetCarryFlag(bool state);
	void SetOverflowFlag(bool state);
	void SetParityFlag(bool state);
	void SetSignFlag(bool state);
	void SetDirectionFlag(bool state);



	Segment* GetSegment(WORD seg);
	void AddSegment(Segment* seg, WORD sel);
	WORD* GetRegistersAsArray();

private:
	WORD AX, CX, DX, BX, SP, BP, SI, DI;
	WORD IP;
	WORD CS, DS, SS, ES, FS, GS;
	WORD flags; 

	std::map<WORD, Segment*> segmentTable;
};

