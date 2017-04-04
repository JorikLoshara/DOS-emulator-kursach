#pragma once
#include"CPUState.h"

namespace Instructions
{
	asmResult int_ib(CPUState* cpu, BYTE* instruction);

	asmResult int21h(CPUState* cpu, BYTE* instruction);

	asmResult int20h(CPUState* cpu, BYTE* instruction);
}