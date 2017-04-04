#pragma once
#include"CPUState.h"

namespace Instructions
{
	asmResult dec_AX(CPUState* cpu, BYTE* instruction);
	asmResult dec_CX(CPUState* cpu, BYTE* instruction);
	asmResult dec_DX(CPUState* cpu, BYTE* instruction);
	asmResult dec_BX(CPUState* cpu, BYTE* instruction);
	asmResult dec_SP(CPUState* cpu, BYTE* instruction);
	asmResult dec_BP(CPUState* cpu, BYTE* instruction);
	asmResult dec_SI(CPUState* cpu, BYTE* instruction);
	asmResult dec_DI(CPUState* cpu, BYTE* instruction);
}