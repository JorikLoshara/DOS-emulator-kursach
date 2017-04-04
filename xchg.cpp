#include "xchg.h"


asmResult Instructions::xchg_AXCX(CPUState * cpu, BYTE * instruction)
{
	WORD temp = cpu->GetAX();
	cpu->SetAX(cpu->GetCX());
	cpu->SetCX(temp);
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::xchg_AXDX(CPUState * cpu, BYTE * instruction)
{
	WORD temp = cpu->GetAX();
	cpu->SetAX(cpu->GetDX());
	cpu->SetDX(temp);
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::xchg_AXBX(CPUState * cpu, BYTE * instruction)
{
	WORD temp = cpu->GetAX();
	cpu->SetAX(cpu->GetBX());
	cpu->SetBX(temp);
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::xchg_AXSP(CPUState * cpu, BYTE * instruction)
{
	WORD temp = cpu->GetAX();
	cpu->SetAX(cpu->GetSP());
	cpu->SetSP(temp);
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::xchg_AXBP(CPUState * cpu, BYTE * instruction)
{
	WORD temp = cpu->GetAX();
	cpu->SetAX(cpu->GetBP());
	cpu->SetBP(temp);
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::xchg_AXSI(CPUState * cpu, BYTE * instruction)
{
	WORD temp = cpu->GetAX();
	cpu->SetAX(cpu->GetSI());
	cpu->SetSI(temp);
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::xchg_AXDI(CPUState * cpu, BYTE * instruction)
{
	WORD temp = cpu->GetAX();
	cpu->SetAX(cpu->GetDI());
	cpu->SetDI(temp);
	cpu->IncreaseIP(1);
	return resultOK;
}

asmResult Instructions::xchg_rbrmb(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}

asmResult Instructions::xchg_rwrmw(CPUState * cpu, BYTE * instruction)
{
	BYTE rm = *(BYTE*)(instruction + 1);
	int mod = (rm & (3 << 6)) >> 6;

	if (mod == mod11)
	{
		int reg1 = rm & 7;
		int reg2 = (rm & (7 << 3)) >> 3;

		WORD temp = cpu->GetRegistersAsArray()[reg1];
		cpu->GetRegistersAsArray()[reg1] = cpu->GetRegistersAsArray()[reg2];
		cpu->GetRegistersAsArray()[reg2] = temp;
		cpu->IncreaseIP(2);
		return resultOK;
	}
	else
	{
		return notImplemented;
	}
}
