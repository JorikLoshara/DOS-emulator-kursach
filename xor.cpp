#include "xor.h"

asmResult Instructions::xor_ALib(CPUState * cpu, BYTE * instruction)
{
	BYTE operand = *(BYTE*)(instruction + 1);
	cpu->SetAL(cpu->GetAL() ^ operand);
	return resultOK;
}

asmResult Instructions::xor_AXiw(CPUState * cpu, BYTE * instruction)
{
	WORD operand = *(WORD*)(instruction + 1);
	cpu->SetAX(cpu->GetAX() ^ operand);
	return resultOK;
}

asmResult Instructions::xor_rbrmb(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}

asmResult Instructions::xor_rwrmw(CPUState * cpu, BYTE * instruction)
{
	BYTE rm = *(BYTE*)(instruction + 1);
	int mod = (rm & (3 << 6)) >> 6;

	if (mod == mod11)
	{
		int reg1 = (rm & (7 << 3)) >> 3;
		int reg2 = rm & 7;
		cpu->GetRegistersAsArray()[reg1] ^= cpu->GetRegistersAsArray()[reg2];
		cpu->IncreaseIP(2);
		return resultOK;
	}
	else
	{
		return notImplemented;
	}
}

asmResult Instructions::xor_rmbrb(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}

asmResult Instructions::xor_rmwrw(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}
