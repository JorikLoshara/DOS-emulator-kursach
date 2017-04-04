#include "sub.h"

asmResult Instructions::sub_ALib(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}

asmResult Instructions::sub_AXiw(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}

asmResult Instructions::sub_rbrmb(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}

asmResult Instructions::sub_rwrmw(CPUState * cpu, BYTE * instruction)
{
	BYTE rm = *(BYTE*)(instruction + 1);
	int mod = (rm & (3 << 6)) >> 6;

	if (mod == mod11)
	{
		int reg1 = (rm & (7 << 3)) >> 3;
		int reg2 = rm & 7;
		cpu->GetRegistersAsArray()[reg1] -= cpu->GetRegistersAsArray()[reg2];
		cpu->IncreaseIP(2);
		return resultOK;
	}
	else
	{
		return notImplemented;
	}
}

asmResult Instructions::sub_rmbrb(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}

asmResult Instructions::sub_rmwrw(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}
