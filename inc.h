#pragma once
#include"CPUState.h"


namespace Instructions
{
	asmResult inc_AX(CPUState* cpu, BYTE* instruction);
	asmResult inc_CX(CPUState* cpu, BYTE* instruction);
	asmResult inc_DX(CPUState* cpu, BYTE* instruction);
	asmResult inc_BX(CPUState* cpu, BYTE* instruction);
	asmResult inc_SP(CPUState* cpu, BYTE* instruction);
	asmResult inc_BP(CPUState* cpu, BYTE* instruction);
	asmResult inc_SI(CPUState* cpu, BYTE* instruction);
	asmResult inc_DI(CPUState* cpu, BYTE* instruction);
}