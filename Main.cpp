#include<iostream>
#include<fstream>
#include<vector>
#include<Windows.h>
#include"CPUState.h"
#include"Segment.h"
#include"Opcodes.h"
#include"mov.h"
#include"add.h"
#include"inc.h"
#include"dec.h"
#include"int.h"
#include"neskolko_srazu.h"
#include"pop.h"
#include"push.h"
#include"small.h"
#include"sub.h"
#include"xchg.h"
#include"xor.h"
#include<conio.h>
#include<locale.h>


char signature1[] = "VirusCodeGenerator by RedArc";
size_t sigLength = strlen(signature1);

typedef asmResult(*AbstractFunctionForAssemblerCommand)(CPUState* cpu, BYTE* instruction);
const WORD DEFAULT_SEGMENT = 0x1234;

void initInstructionTable(AbstractFunctionForAssemblerCommand* table);
bool findBytePattern(BYTE* memToScan, size_t memSize, BYTE* signature, size_t signatureLength);
void debugCPU(CPUState* cpu);
std::vector<std::string> getFilesList(std::string directoryPath);
bool emulateFile(std::string filePath);

void main(int argc, char** argv)
{
	setlocale(LC_CTYPE, "RUS");
	
	std::vector<std::string> comFiles;
	comFiles = getFilesList(argv[1]);

	if (comFiles.size() == 0)
	{
		std::cout << "No files in directory\n";
		exit(0);
	}

	std::ofstream ofs("MLG_360_AV_yolooooo_rekt_result.txt", std::ofstream::trunc);
	for (int i = 0; i < comFiles.size(); i++)
	{
		ofs.write(comFiles[i].c_str(), comFiles[i].size());

		if (emulateFile(comFiles[i]))
		{
			ofs.write(" - ne ok\n", 9);
		}
		else
		{
			ofs.write(" - ok\n", 6);
		}
	}

}

bool emulateFile(std::string filePath)
{
	Segment *segment = new Segment();
	CPUState *cpu = new CPUState();

	std::ifstream ifs(filePath, std::ios::binary);
	if (ifs.fail())
	{
		std::cout << "File not found\n";
		system("pause");
		exit(0);
	}

	ifs.seekg(0, std::ios::end);
	size_t fileSize = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	ifs.read((char*)segment->GetProgramAddr(), fileSize);
	ifs.close();
	cpu->SetSegmentAndSelectorAsTinyMemoryModelSpecialForDOSDUDOSBecauseItUsesOnlyThis(segment, DEFAULT_SEGMENT);
	segment = 0;

	BYTE *memToScan = cpu->GetSegment(DEFAULT_SEGMENT)->GetBaseAddr();

	AbstractFunctionForAssemblerCommand InstructionTable[256];
	initInstructionTable(InstructionTable);

	while (1)
	{
		BYTE opcode = *cpu->GetNextInstruction();
		asmResult res = InstructionTable[opcode](cpu, cpu->GetNextInstruction());

		switch (res)
		{
		case memChanged:
			if (findBytePattern(memToScan, SEGMENT_SIZE, (BYTE*)signature1, sigLength))
			{
				delete cpu;
				return true;
			}
			break;
		case notImplemented:
			delete cpu;
			return false;
			break;
		case resultOK:
			break;

		default:
			break;
		}
			
	}

}


void debugCPU(CPUState* cpu)
{
	std::cout << "AX: " << std::hex << cpu->GetAX() << "\n";
	std::cout << "BX: " << std::hex << cpu->GetBX() << "\n";
	std::cout << "CX: " << std::hex << cpu->GetCX() << "\n";
	std::cout << "DX: " << std::hex << cpu->GetDX() << "\n";
	std::cout << "SI: " << std::hex << cpu->GetSI() << "\n";
	std::cout << "DI: " << std::hex << cpu->GetDI() << "\n";
	std::cout << "SP: " << std::hex << cpu->GetSP() << "\n";
	std::cout << "BP: " << std::hex << cpu->GetBP() << "\n";
	std::cout << "IP: " << std::hex << cpu->GetIP() << "  " << std::hex << (int)*cpu->GetNextInstruction() << "\n";
}

std::vector<std::string> getFilesList(std::string directoryPath)
{
	std::string fileMask = directoryPath + "\\*.com";
	std::vector<std::string> result;
	WIN32_FIND_DATAA wfd;

	HANDLE hFile = FindFirstFileA(fileMask.c_str(), &wfd);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		std::cout << "Неверно задан параметр\n";
		exit(0);
	}
	
	result.push_back(directoryPath + "\\" + wfd.cFileName);
	while (FindNextFileA(hFile, &wfd))
	{
		result.push_back(directoryPath + "\\" +  wfd.cFileName);
	}

	return result;
}

asmResult unknownInstruction(CPUState* cpu, BYTE* instruction)
{
	//WORD instructionAddr = instruction - (cpu->GetSegment(DEFAULT_SEGMENT)->GetBaseAddr() + 0x100);
	//std::cout << "Unknown instruction(" << std::hex << (unsigned int) instructionAddr << ":" << std::hex << (int) *instruction << ")\n";
	return notImplemented;
}

void initInstructionTable(AbstractFunctionForAssemblerCommand* table)
{
	for (int i = 0; i < 256; i++)
		table[i] = unknownInstruction;
	
	table[opcode::mov_ALrmb] = Instructions::mov_ALrmb;
	table[opcode::mov_AXrmw] = Instructions::mov_AXrmw;
	table[opcode::mov_ALib] = Instructions::mov_ALib;
	table[opcode::mov_AHib] = Instructions::mov_AHib;
	table[opcode::mov_AXiw] = Instructions::mov_AXiw;
	table[opcode::mov_CLib] = Instructions::mov_CLib;
	table[opcode::mov_CHib] = Instructions::mov_CHib;
	table[opcode::mov_CXiw] = Instructions::mov_CXiw;
	table[opcode::mov_DLib] = Instructions::mov_DLib;
	table[opcode::mov_DHib] = Instructions::mov_DHib;
	table[opcode::mov_DXiw] = Instructions::mov_DXiw;
	table[opcode::mov_BLib] = Instructions::mov_BLib;
	table[opcode::mov_BXiw] = Instructions::mov_BXiw;
	table[opcode::mov_SPiw] = Instructions::mov_SPiw;
	table[opcode::mov_BPiw] = Instructions::mov_BPiw;
	table[opcode::mov_SIiw] = Instructions::mov_SIiw;
	table[opcode::mov_DIiw] = Instructions::mov_DIiw;
	table[opcode::mov_rwrmw] = Instructions::mov_rwrmw;

	table[opcode::push_AX] = Instructions::push_AX;
	table[opcode::push_CX] = Instructions::push_CX;
	table[opcode::push_DX] = Instructions::push_DX;
	table[opcode::push_BX] = Instructions::push_BX;
	table[opcode::push_SP] = Instructions::push_SP;
	table[opcode::push_BP] = Instructions::push_BP;
	table[opcode::push_SI] = Instructions::push_SI;
	table[opcode::push_DI] = Instructions::push_DI;
	table[opcode::push_ES] = Instructions::push_ES;
	table[opcode::push_CS] = Instructions::push_CS;
	table[opcode::push_SS] = Instructions::push_SS;
	table[opcode::push_DS] = Instructions::push_DS;
	table[opcode::push_iw] = Instructions::push_iw;

	table[opcode::pop_AX] = Instructions::pop_AX;
	table[opcode::pop_CX] = Instructions::pop_CX;
	table[opcode::pop_DX] = Instructions::pop_DX;
	table[opcode::pop_BX] = Instructions::pop_BX;
	table[opcode::pop_SP] = Instructions::pop_SP;
	table[opcode::pop_BP] = Instructions::pop_BP;
	table[opcode::pop_SI] = Instructions::pop_SI;
	table[opcode::pop_DI] = Instructions::pop_DI;

	table[opcode::xchg_AXCX] = Instructions::xchg_AXCX;
	table[opcode::xchg_AXDX] = Instructions::xchg_AXDX;
	table[opcode::xchg_AXBX] = Instructions::xchg_AXBX;
	table[opcode::xchg_AXSP] = Instructions::xchg_AXSP;
	table[opcode::xchg_AXBP] = Instructions::xchg_AXBP;
	table[opcode::xchg_AXSI] = Instructions::xchg_AXSI;
	table[opcode::xchg_AXDI] = Instructions::xchg_AXDI;
	table[opcode::xchg_rbrmb] = Instructions::xchg_rbrmb;
	table[opcode::xchg_rwrmw] = Instructions::xchg_rwrmw;

	table[opcode::xor_ALib] = Instructions::xor_ALib;
	table[opcode::xor_AXiw] = Instructions::xor_AXiw;
	table[opcode::xor_rbrmb] = Instructions::xor_rbrmb;
	table[opcode::xor_rwrmw] = Instructions::xor_rwrmw;
	table[opcode::op0x81_rmbib] = Instructions::op0x81_rmbib;
	table[opcode::op0x81_rmwiw] = Instructions::op0x81_rmwiw;
	table[opcode::op0x81_rmwib] = Instructions::op0x81_rmwib;
	table[opcode::xor_rmbrb] = Instructions::xor_rmbrb;
	table[opcode::xor_rmwrw] = Instructions::xor_rmwrw;

	table[opcode::add_ALib] = Instructions::add_ALib;
	table[opcode::add_AXiw] = Instructions::add_AXiw;
	table[opcode::add_rbrmb] = Instructions::add_rbrmb;
	table[opcode::add_rwrmw] = Instructions::add_rwrmw;
	table[opcode::add_rmbrb] = Instructions::add_rmbrb;
	table[opcode::add_rmwrw] = Instructions::add_rmwrw;

	table[opcode::sub_ALib] = Instructions::sub_ALib;
	table[opcode::sub_AXiw] = Instructions::sub_AXiw;
	table[opcode::sub_rbrmb] = Instructions::sub_rbrmb;
	table[opcode::sub_rwrmw] = Instructions::sub_rwrmw;
	table[opcode::sub_rmbrb] = Instructions::sub_rmbrb;
	table[opcode::sub_rmwrw] = Instructions::sub_rmwrw;

	table[opcode::inc_AX] = Instructions::inc_AX;
	table[opcode::inc_CX] = Instructions::inc_CX;
	table[opcode::inc_DX] = Instructions::inc_DX;
	table[opcode::inc_BX] = Instructions::inc_BX;
	table[opcode::inc_SP] = Instructions::inc_SP;
	table[opcode::inc_BP] = Instructions::inc_BP;
	table[opcode::inc_SI] = Instructions::inc_SI;
	table[opcode::inc_DI] = Instructions::inc_DI;
	table[opcode::inc_dec_rmb] = Instructions::inc_dec_rmb;
	table[opcode::inc_dec_rmw] = Instructions::inc_dec_rmw;

	table[opcode::dec_AX] = Instructions::dec_AX;
	table[opcode::dec_CX] = Instructions::dec_CX;
	table[opcode::dec_DX] = Instructions::dec_DX;
	table[opcode::dec_BX] = Instructions::dec_BX;
	table[opcode::dec_SP] = Instructions::dec_SP;
	table[opcode::dec_BP] = Instructions::dec_BP;
	table[opcode::dec_SI] = Instructions::dec_SI;
	table[opcode::dec_DI] = Instructions::dec_DI;

	table[opcode::stos_b] = Instructions::stos_b;
	table[opcode::stos_w] = Instructions::stos_w;

	table[opcode::ret] = Instructions::ret;
	table[opcode::ret_iw] = Instructions::ret_iw;
	table[opcode::retf] = Instructions::retf;
	table[opcode::retf_iw] = Instructions::retf_iw;

	table[opcode::int_3] = Instructions::int_3;
	table[opcode::int_ib] = Instructions::int_ib;

	table[opcode::nop] = Instructions::nop;

}

bool findBytePattern(BYTE* memToScan, size_t memSize, BYTE* signature, size_t signatureLength)
{
	for (int i = 0; i < memSize; i++)
	{
		for (int j = 0; j < signatureLength; j++)
		{
			if (i + j < memSize)
			{
				if (memToScan[i + j] == signature[j])
				{
					if (j == signatureLength - 1)
					{
						return true;
					}
				}
				else
					break;
			}
			else
				break;
		}
	}

	return false;
}
