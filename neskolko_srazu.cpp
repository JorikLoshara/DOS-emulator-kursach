#include "neskolko_srazu.h"

asmResult Instructions::op0x81_rmbib(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}

asmResult Instructions::op0x81_rmwiw(CPUState * cpu, BYTE * instruction)
{
	BYTE rm = *(BYTE*)(instruction + 1);
	WORD operand = *(WORD*)(instruction + 2);
	int regIndex = rm & 7; // 00000111
	int opCodeExt = (rm & (7 << 3)) >> 3;
	int mod = (rm & (3 << 6)) >> 6;

	if (mod == mod11)
	{
		switch (opCodeExt)
		{
		case op81ADD:
			cpu->GetRegistersAsArray()[regIndex] += operand;
			break;
		case op81SUB:
			cpu->GetRegistersAsArray()[regIndex] -= operand;
			break;
		case op81XOR:
			cpu->GetRegistersAsArray()[regIndex] ^= operand;
			break;
		}

		cpu->IncreaseIP(4);
		return resultOK;
	}
	else
	{
		return notImplemented;
	}
}

asmResult Instructions::op0x81_rmwib(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}

asmResult Instructions::inc_dec_rmb(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}

asmResult Instructions::inc_dec_rmw(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}
