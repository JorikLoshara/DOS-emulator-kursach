#include "inc.h"


asmResult Instructions::inc_AX(CPUState * cpu, BYTE * instruction)
{
	cpu->SetAX(cpu->GetAX() + 1);
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::inc_CX(CPUState * cpu, BYTE * instruction)
{
	cpu->SetCX(cpu->GetCX() + 1);
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::inc_DX(CPUState * cpu, BYTE * instruction)
{
	cpu->SetDX(cpu->GetDX() + 1);
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::inc_BX(CPUState * cpu, BYTE * instruction)
{
	cpu->SetBX(cpu->GetBX() + 1);
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::inc_SP(CPUState * cpu, BYTE * instruction)
{
	cpu->SetSP(cpu->GetSP() + 1);
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::inc_BP(CPUState * cpu, BYTE * instruction)
{
	cpu->SetBP(cpu->GetBP() + 1);
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::inc_SI(CPUState * cpu, BYTE * instruction)
{
	cpu->SetSI(cpu->GetSI() + 1);
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::inc_DI(CPUState * cpu, BYTE * instruction)
{
	cpu->SetDI(cpu->GetDI() + 1);
	cpu->IncreaseIP(1);
	return resultOK;
}
