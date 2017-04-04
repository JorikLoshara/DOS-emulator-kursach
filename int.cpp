#include "int.h"
#include "short.h"

asmResult Instructions::int_ib(CPUState * cpu, BYTE * instruction)
{
	BYTE N = *(BYTE*)(instruction + 1);
	switch (N)
	{
	case 0x21:
		return int21h(cpu, instruction);
		break;
	case 0x20:
		return int20h(cpu, instruction);
		break;
	default:
		return notImplemented;
		break;
	}
}



asmResult Instructions::int21h(CPUState * cpu, BYTE * instruction)
{
	switch (cpu->GetAH())
	{
	case 0x09:
		/*char *pSymbol = (char*)cpu->GetSegment(cpu->GetDS())->memory + cpu->GetDX();
		while (*pSymbol != '$')
		{
			std::cout << *pSymbol;
			pSymbol++;
		}*/
		std::cout << "Типа Output string\n";
		break;
	}
	cpu->IncreaseIP(2);
	return resultOK;
}

asmResult Instructions::int20h(CPUState * cpu, BYTE * instruction)
{
	std::cout << "Program terminated\n";
	system("pause");
	return programExit;
}

asmResult Instructions::int_3(CPUState * cpu, BYTE * instruction)
{
	return notImplemented;
}