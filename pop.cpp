#include "pop.h"


asmResult Instructions::pop_AX(CPUState * cpu, BYTE * instruction)
{
	cpu->SetAX(cpu->Pop());
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::pop_CX(CPUState * cpu, BYTE * instruction)
{
	cpu->SetCX(cpu->Pop());
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::pop_DX(CPUState * cpu, BYTE * instruction)
{
	cpu->SetDX(cpu->Pop());
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::pop_BX(CPUState * cpu, BYTE * instruction)
{
	cpu->SetBX(cpu->Pop());
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::pop_SP(CPUState * cpu, BYTE * instruction)
{
	cpu->SetSP(cpu->Pop());
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::pop_BP(CPUState * cpu, BYTE * instruction)
{
	cpu->SetBP(cpu->Pop());
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::pop_SI(CPUState * cpu, BYTE * instruction)
{
	cpu->SetSI(cpu->Pop());
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::pop_DI(CPUState * cpu, BYTE * instruction)
{
	cpu->SetDI(cpu->Pop());
	cpu->IncreaseIP(1);
	return resultOK;
}
