#include "short.h"

asmResult Instructions::stos_b(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}

asmResult Instructions::stos_w(CPUState * cpu, BYTE * instruction)
{
	*(WORD*)(cpu->GetSegment(cpu->GetES())->memory + cpu->GetDI()) = cpu->GetAX();
	cpu->SetDI(cpu->GetDI() + 2);
	cpu->IncreaseIP(1);
	return memChanged;
}

asmResult Instructions::ret(CPUState * cpu, BYTE * instruction)
{
	WORD retAddr = cpu->Pop();
	cpu->SetIP(retAddr);
	return resultOK;
}

asmResult Instructions::ret_iw(CPUState * cpu, BYTE * instruction)
{
	WORD retAddr = cpu->Pop();
	cpu->SetIP(retAddr);
	WORD operand = *(WORD*)(instruction + 1);
	cpu->SetSP(cpu->GetSP() + operand);
	return resultOK;
}

asmResult Instructions::retf(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}

asmResult Instructions::retf_iw(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}

asmResult Instructions::nop(CPUState * cpu, BYTE * instruction)
{
	cpu->IncreaseIP(1);
	return resultOK;
}

