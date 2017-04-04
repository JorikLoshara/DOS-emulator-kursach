#pragma once
#include"CPUState.h"

namespace Instructions
{
	asmResult mov_ALrmb(CPUState* cpu, BYTE* instruction);
	asmResult mov_AXrmw(CPUState* cpu, BYTE* instruction);
	asmResult mov_ALib(CPUState* cpu, BYTE* instruction);
	asmResult mov_AHib(CPUState* cpu, BYTE* instruction);
	asmResult mov_AXiw(CPUState* cpu, BYTE* instruction);
	asmResult mov_CLib(CPUState* cpu, BYTE* instruction);
	asmResult mov_CHib(CPUState* cpu, BYTE* instruction);
	asmResult mov_CXiw(CPUState* cpu, BYTE* instruction);
	asmResult mov_DLib(CPUState* cpu, BYTE* instruction);
	asmResult mov_DHib(CPUState* cpu, BYTE* instruction);
	asmResult mov_DXiw(CPUState* cpu, BYTE* instruction);
	asmResult mov_BLib(CPUState* cpu, BYTE* instruction);
	asmResult mov_BXiw(CPUState* cpu, BYTE* instruction);
	asmResult mov_SPiw(CPUState* cpu, BYTE* instruction);
	asmResult mov_BPiw(CPUState* cpu, BYTE* instruction);
	asmResult mov_SIiw(CPUState* cpu, BYTE* instruction);
	asmResult mov_DIiw(CPUState* cpu, BYTE* instruction);

	asmResult mov_rbrmb(CPUState* cpu, BYTE* instruction);
	asmResult mov_rmbrb(CPUState* cpu, BYTE* instruction);
	asmResult mov_rmbAL(CPUState* cpu, BYTE* instruction);
	asmResult mov_rmwAX(CPUState* cpu, BYTE* instruction);
	asmResult mov_rmbib(CPUState* cpu, BYTE* instruction);
	asmResult mov_rmwiw(CPUState* cpu, BYTE* instruction);
	asmResult mov_rmwrw(CPUState* cpu, BYTE* instruction);
	asmResult mov_rwrmw(CPUState* cpu, BYTE* instruction);
	asmResult mov_rwrmw(CPUState* cpu, BYTE* instruction);
	asmResult mov_rmwsr(CPUState* cpu, BYTE* instruction);
	asmResult mov_srrmw(CPUState* cpu, BYTE* instruction);
}






