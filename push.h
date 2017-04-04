#pragma once
#include"CPUState.h"

namespace Instructions
{
	asmResult push_AX(CPUState* cpu, BYTE* instruction);
	asmResult push_CX(CPUState* cpu, BYTE* instruction);
	asmResult push_DX(CPUState* cpu, BYTE* instruction);
	asmResult push_BX(CPUState* cpu, BYTE* instruction);
	asmResult push_SP(CPUState* cpu, BYTE* instruction);
	asmResult push_BP(CPUState* cpu, BYTE* instruction);
	asmResult push_SI(CPUState* cpu, BYTE* instruction);
	asmResult push_DI(CPUState* cpu, BYTE* instruction);
	asmResult push_ES(CPUState* cpu, BYTE* instruction);
	asmResult push_CS(CPUState* cpu, BYTE* instruction);
	asmResult push_SS(CPUState* cpu, BYTE* instruction);
	asmResult push_DS(CPUState* cpu, BYTE* instruction);
	asmResult push_iw(CPUState* cpu, BYTE* instruction);
}