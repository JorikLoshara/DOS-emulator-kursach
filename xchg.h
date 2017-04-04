#pragma once
#include"CPUState.h"

namespace Instructions
{
	asmResult xchg_AXCX(CPUState* cpu, BYTE* instruction);
	asmResult xchg_AXDX(CPUState* cpu, BYTE* instruction);
	asmResult xchg_AXBX(CPUState* cpu, BYTE* instruction);
	asmResult xchg_AXSP(CPUState* cpu, BYTE* instruction);
	asmResult xchg_AXBP(CPUState* cpu, BYTE* instruction);
	asmResult xchg_AXSI(CPUState* cpu, BYTE* instruction);
	asmResult xchg_AXDI(CPUState* cpu, BYTE* instruction);
	asmResult xchg_rbrmb(CPUState* cpu, BYTE* instruction);
	asmResult xchg_rwrmw(CPUState* cpu, BYTE* instruction);
}