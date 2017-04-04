#pragma once
#include"CPUState.h"

namespace Instructions
{
	asmResult stos_b(CPUState* cpu, BYTE* instruction);
	asmResult stos_w(CPUState* cpu, BYTE* instruction);

	asmResult ret(CPUState* cpu, BYTE* instruction);
	asmResult ret_iw(CPUState * cpu, BYTE * instruction);
	asmResult retf(CPUState * cpu, BYTE * instruction);
	asmResult retf_iw(CPUState * cpu, BYTE * instruction);

	asmResult int_3(CPUState* cpu, BYTE* instruction);
	asmResult int_ib(CPUState* cpu, BYTE* instruction);

	asmResult nop(CPUState* cpu, BYTE* instruction);
}