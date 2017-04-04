#pragma once
#include"CPUState.h"

namespace Instructions
{
	asmResult xor_ALib(CPUState* cpu, BYTE* instruction);
	asmResult xor_AXiw(CPUState* cpu, BYTE* instruction);
	asmResult xor_rbrmb(CPUState* cpu, BYTE* instruction);
	asmResult xor_rwrmw(CPUState* cpu, BYTE* instruction);
	asmResult xor_rmbrb(CPUState* cpu, BYTE* instruction);
	asmResult xor_rmwrw(CPUState* cpu, BYTE* instruction);
}