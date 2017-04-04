#pragma once
#include"CPUState.h"

namespace Instructions
{
	asmResult pop_AX(CPUState* cpu, BYTE* instruction);
	asmResult pop_CX(CPUState* cpu, BYTE* instruction);
	asmResult pop_DX(CPUState* cpu, BYTE* instruction);
	asmResult pop_BX(CPUState* cpu, BYTE* instruction);
	asmResult pop_SP(CPUState* cpu, BYTE* instruction);
	asmResult pop_BP(CPUState* cpu, BYTE* instruction);
	asmResult pop_SI(CPUState* cpu, BYTE* instruction);
	asmResult pop_DI(CPUState* cpu, BYTE* instruction);
}