#include "push.h"


asmResult Instructions::push_AX(CPUState * cpu, BYTE * instruction)
{
	cpu->Push(cpu->GetAX());
	cpu->IncreaseIP(1);
	return memChanged;
}

asmResult Instructions::push_CX(CPUState * cpu, BYTE * instruction)
{
	cpu->Push(cpu->GetCX());
	cpu->IncreaseIP(1);
	return memChanged;
}

asmResult Instructions::push_DX(CPUState * cpu, BYTE * instruction)
{
	cpu->Push(cpu->GetDX());
	cpu->IncreaseIP(1);
	return memChanged;
}

asmResult Instructions::push_BX(CPUState * cpu, BYTE * instruction)
{
	cpu->Push(cpu->GetBX());
	cpu->IncreaseIP(1);
	return memChanged;
}

asmResult Instructions::push_SP(CPUState * cpu, BYTE * instruction)
{
	cpu->Push(cpu->GetSP());
	cpu->IncreaseIP(1);
	return memChanged;
}

asmResult Instructions::push_BP(CPUState * cpu, BYTE * instruction)
{
	cpu->Push(cpu->GetBP());
	cpu->IncreaseIP(1);
	return memChanged;
}

asmResult Instructions::push_SI(CPUState * cpu, BYTE * instruction)
{
	cpu->Push(cpu->GetSI());
	cpu->IncreaseIP(1);
	return memChanged;
}

asmResult Instructions::push_DI(CPUState * cpu, BYTE * instruction)
{
	cpu->Push(cpu->GetDI());
	cpu->IncreaseIP(1);
	return memChanged;
}

asmResult Instructions::push_ES(CPUState * cpu, BYTE * instruction)
{
	cpu->Push(cpu->GetES());
	cpu->IncreaseIP(1);
	return memChanged;
}

asmResult Instructions::push_CS(CPUState * cpu, BYTE * instruction)
{
	cpu->Push(cpu->GetCS());
	cpu->IncreaseIP(1);
	return memChanged;
}

asmResult Instructions::push_SS(CPUState * cpu, BYTE * instruction)
{
	cpu->Push(cpu->GetSS());
	cpu->IncreaseIP(1);
	return memChanged;
}

asmResult Instructions::push_DS(CPUState * cpu, BYTE * instruction)
{
	cpu->Push(cpu->GetDS());
	cpu->IncreaseIP(1);
	return memChanged;
}

asmResult Instructions::push_iw(CPUState * cpu, BYTE * instruction)
{
	WORD operand = *(WORD*)(instruction + 1);
	cpu->Push(operand);
	cpu->IncreaseIP(3);
	return memChanged;
}
