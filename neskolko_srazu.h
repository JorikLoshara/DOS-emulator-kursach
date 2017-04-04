#pragma once
#include"CPUState.h"

namespace Instructions
{
	const int op81ADD = 0;
	const int op81OR =  1;
	const int op81ADC = 2;
	const int op81SBB = 3;
	const int op81AND = 4;
	const int op81SUB = 5;
	const int op81XOR = 6;
	const int op81CMP = 7;

	


	asmResult op0x81_rmbib(CPUState* cpu, BYTE* instruction);
	asmResult op0x81_rmwiw(CPUState* cpu, BYTE* instruction);
	asmResult op0x81_rmwib(CPUState* cpu, BYTE* instruction);

	asmResult inc_dec_rmb(CPUState* cpu, BYTE* instruction);
	asmResult inc_dec_rmw(CPUState* cpu, BYTE* instruction);
}