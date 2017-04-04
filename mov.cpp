#include "mov.h"

namespace Instructions
{
	asmResult mov_ALrmb(CPUState * cpu, BYTE * instruction)
	{
		WORD addr = *(WORD*)(instruction + 1);
		BYTE b = cpu->GetByteByAddr(addr);
		cpu->SetAL(b);
		cpu->IncreaseIP(3);
		return resultOK;
	}

	asmResult mov_AXrmw(CPUState * cpu, BYTE * instruction)
	{
		WORD addr = *(WORD*)(instruction + 1);
		WORD w = cpu->GetWordByAddr(addr);
		cpu->SetAX(w);
		cpu->IncreaseIP(3);
		return resultOK;
	}

	asmResult mov_ALib(CPUState * cpu, BYTE * instruction)
	{
		BYTE operand = *(BYTE*)(instruction + 1);
		cpu->SetAL(operand);
		cpu->IncreaseIP(2);
		return resultOK;
	}

	asmResult mov_AHib(CPUState * cpu, BYTE * instruction)
	{
		BYTE operand = *(BYTE*)(instruction + 1);
		cpu->SetAH(operand);
		cpu->IncreaseIP(2);
		return resultOK;
	}

	asmResult mov_AXiw(CPUState * cpu, BYTE * instruction)
	{
		WORD operand = *(WORD*)(instruction + 1);
		cpu->SetAX(operand);
		cpu->IncreaseIP(3);
		return resultOK;
	}

	asmResult mov_CLib(CPUState * cpu, BYTE * instruction)
	{
		cpu->IncreaseIP(2);
		return notImplemented;
	}

	asmResult mov_CHib(CPUState * cpu, BYTE * instruction)
	{
		cpu->IncreaseIP(2);
		return notImplemented;
	}

	asmResult mov_CXiw(CPUState * cpu, BYTE * instruction)
	{
		WORD operand = *(WORD*)(instruction + 1);
		cpu->SetCX(operand);
		cpu->IncreaseIP(3);
		return resultOK;
	}

	asmResult mov_DLib(CPUState * cpu, BYTE * instruction)
	{
		cpu->IncreaseIP(2);
		return notImplemented;
	}

	asmResult mov_DHib(CPUState * cpu, BYTE * instruction)
	{
		cpu->IncreaseIP(2);
		return notImplemented;
	}

	asmResult mov_DXiw(CPUState * cpu, BYTE * instruction)
	{
		WORD operand = *(WORD*)(instruction + 1);
		cpu->SetDX(operand);
		cpu->IncreaseIP(3);
		return resultOK;
	}

	asmResult mov_BLib(CPUState * cpu, BYTE * instruction)
	{
		cpu->IncreaseIP(2);
		return notImplemented;
	}

	asmResult mov_BXiw(CPUState * cpu, BYTE * instruction)
	{
		WORD operand = *(WORD*)(instruction + 1);
		cpu->SetBX(operand);
		cpu->IncreaseIP(3);
		return resultOK;
	}

	asmResult mov_SPiw(CPUState * cpu, BYTE * instruction)
	{
		WORD operand = *(WORD*)(instruction + 1);
		cpu->SetSP(operand);
		cpu->IncreaseIP(3);
		return resultOK;
	}

	asmResult mov_BPiw(CPUState * cpu, BYTE * instruction)
	{
		WORD operand = *(WORD*)(instruction + 1);
		cpu->SetBP(operand);
		cpu->IncreaseIP(3);
		return resultOK;
	}

	asmResult mov_SIiw(CPUState * cpu, BYTE * instruction)
	{
		WORD operand = *(WORD*)(instruction + 1);
		cpu->SetSI(operand);
		cpu->IncreaseIP(3);
		return resultOK;
	}

	asmResult mov_DIiw(CPUState * cpu, BYTE * instruction)
	{
		WORD operand = *(WORD*)(instruction + 1);
		cpu->SetDI(operand);
		cpu->IncreaseIP(3);
		return resultOK;
	}
	asmResult mov_rbrmb(CPUState * cpu, BYTE * instruction)
	{
		return notImplemented;
	}
	asmResult mov_rmbrb(CPUState * cpu, BYTE * instruction)
	{
		return notImplemented;
	}
	asmResult mov_rmbAL(CPUState * cpu, BYTE * instruction)
	{
		return notImplemented;
	}
	asmResult mov_rmwAX(CPUState * cpu, BYTE * instruction)
	{
		return notImplemented;
	}
	asmResult mov_rmbib(CPUState * cpu, BYTE * instruction)
	{
		return notImplemented;
	}
	asmResult mov_rmwiw(CPUState * cpu, BYTE * instruction)
	{
		return notImplemented;
	}
	asmResult mov_rmwrw(CPUState * cpu, BYTE * instruction)
	{
		return notImplemented;
	}
	asmResult mov_rwrmw(CPUState * cpu, BYTE * instruction)
	{
		BYTE rm = *(BYTE*)(instruction + 1);
		int mod = (rm & (3 << 6)) >> 6;
		
		if (mod == mod11)
		{
			int reg1 = (rm & (7 << 3)) >> 3;
			int reg2 = rm & 7;
			cpu->GetRegistersAsArray()[reg1] = cpu->GetRegistersAsArray()[reg2];
			cpu->IncreaseIP(2);
			return resultOK;
		}
		else
		{
			return resultOK;
		}
	}
	asmResult mov_rmwsr(CPUState * cpu, BYTE * instruction)
	{
		return notImplemented;
	}
	asmResult mov_srrmw(CPUState * cpu, BYTE * instruction)
	{
		return notImplemented;
	}
}