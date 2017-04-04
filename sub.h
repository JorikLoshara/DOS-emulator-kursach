#pragma once
#include"CPUState.h"

namespace Instructions
{
	asmResult sub_ALib(CPUState* cpu, BYTE* instruction);
	asmResult sub_AXiw(CPUState* cpu, BYTE* instruction);
	asmResult sub_rbrmb(CPUState* cpu, BYTE* instruction);
	asmResult sub_rwrmw(CPUState* cpu, BYTE* instruction);
	asmResult sub_rmbrb(CPUState* cpu, BYTE* instruction);
	asmResult sub_rmwrw(CPUState* cpu, BYTE* instruction);
}
