#pragma once
#include"CPUState.h"

namespace Instructions
{
	asmResult add_ALib(CPUState* cpu, BYTE* instruction);
	asmResult add_AXiw(CPUState* cpu, BYTE* instruction);
	asmResult add_rbrmb(CPUState* cpu, BYTE* instruction);
	asmResult add_rwrmw(CPUState* cpu, BYTE* instruction);
	asmResult add_rmbrb(CPUState* cpu, BYTE* instruction);
	asmResult add_rmwrw(CPUState* cpu, BYTE* instruction);
}