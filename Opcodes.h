#pragma once

typedef unsigned char BYTE;

namespace opcode {
	BYTE mov_ALrmb = 0xA0;
	BYTE mov_AXrmw = 0xA1;
	BYTE mov_ALib = 0xB0;
	BYTE mov_AHib = 0xB4;
	BYTE mov_AXiw = 0xB8;
	BYTE mov_CLib = 0xB1;
	BYTE mov_CHib = 0xB5;
	BYTE mov_CXiw = 0xB9;
	BYTE mov_DLib = 0xB2;
	BYTE mov_DHib = 0xB6;
	BYTE mov_DXiw = 0xBA;
	BYTE mov_BLib = 0xB3;
	BYTE mov_BXiw = 0xBB;
	BYTE mov_SPiw = 0xBC;
	BYTE mov_BPiw = 0xBD;
	BYTE mov_SIiw = 0xBE;
	BYTE mov_DIiw = 0xBF;
	BYTE mov_rwrmw = 0x8B;


	BYTE push_AX = 0x50;
	BYTE push_CX = 0x51;
	BYTE push_DX = 0x52;
	BYTE push_BX = 0x53;
	BYTE push_SP = 0x54;
	BYTE push_BP = 0x55;
	BYTE push_SI = 0x56;
	BYTE push_DI = 0x57;
	BYTE push_ES = 0x06;
	BYTE push_CS = 0x0E;
	BYTE push_SS = 0x16;
	BYTE push_DS = 0x1E;
	BYTE push_iw = 0x68;

	BYTE pop_AX = 0x58;
	BYTE pop_CX = 0x59;
	BYTE pop_DX = 0x5A;
	BYTE pop_BX = 0x5B;
	BYTE pop_SP = 0x5C;
	BYTE pop_BP = 0x5D;
	BYTE pop_SI = 0x5E;
	BYTE pop_DI = 0x5F;
	
	BYTE xchg_AXCX = 0x91;
	BYTE xchg_AXDX = 0x92;
	BYTE xchg_AXBX = 0x93;
	BYTE xchg_AXSP = 0x94;
	BYTE xchg_AXBP = 0x95;
	BYTE xchg_AXSI = 0x96;
	BYTE xchg_AXDI = 0x97;
	BYTE xchg_rbrmb = 0x86; // rbrmb = rmbrb
	BYTE xchg_rwrmw = 0x87;

	BYTE xor_ALib = 0x34;
	BYTE xor_AXiw = 0x35;
	BYTE xor_rbrmb = 0x32;
	BYTE xor_rwrmw = 0x33;
	BYTE op0x81_rmbib = 0x80;
	BYTE op0x81_rmwiw = 0x81;
	BYTE op0x81_rmwib = 0x83;
	BYTE xor_rmbrb = 0x30;
	BYTE xor_rmwrw = 0x31;

	BYTE add_ALib = 0x04;
	BYTE add_AXiw = 0x05;
	BYTE add_rbrmb = 0x02;
	BYTE add_rwrmw = 0x03;
	BYTE add_rmbrb = 0x00;
	BYTE add_rmwrw = 0x01;
	
	BYTE sub_ALib = 0x2C;
	BYTE sub_AXiw = 0x2D;
	BYTE sub_rbrmb = 0x2A;
	BYTE sub_rwrmw = 0x2B;
	BYTE sub_rmbrb = 0x28;
	BYTE sub_rmwrw = 0x29;

	BYTE inc_AX = 0x40;
	BYTE inc_CX = 0x41;
	BYTE inc_DX = 0x42;
	BYTE inc_BX = 0x43;
	BYTE inc_SP = 0x44;
	BYTE inc_BP = 0x45;
	BYTE inc_SI = 0x46;
	BYTE inc_DI = 0x47;
	BYTE inc_dec_rmb = 0xFE;
	BYTE inc_dec_rmw = 0xFF;

	BYTE dec_AX = 0x48;
	BYTE dec_CX = 0x49;
	BYTE dec_DX = 0x4A;
	BYTE dec_BX = 0x4B;
	BYTE dec_SP = 0x4C;
	BYTE dec_BP = 0x4D;
	BYTE dec_SI = 0x4E;
	BYTE dec_DI = 0x4F;

	BYTE stos_b = 0xAA;
	BYTE stos_w = 0xAB;

	BYTE ret = 0xC3;
	BYTE ret_iw = 0xC2;
	BYTE retf = 0xCB;
	BYTE retf_iw = 0xCA;

	BYTE int_3 = 0xCC;
	BYTE int_ib = 0xCD;

	BYTE nop = 0x90;
}