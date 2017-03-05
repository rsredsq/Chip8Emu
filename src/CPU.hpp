//
//  CPU.hpp
//  Chip8Emulator
//
//  
//
//

#ifndef CPU_hpp
#define CPU_hpp

#include <stdio.h>
#include "Memory.hpp"
#include "GPU.hpp"
#include "Timers.hpp"
#include "Keyboard.hpp"
#include "OpCodes.hpp"

class CPU
{

private:
	OpCode opcode;					// ������������ �����
	unsigned char V[16];            // �������� ������ ���������� � ���� �������� VF  
	unsigned short I;               // ��������� �������
	unsigned short PC;              // ��������� ����
	unsigned char SP;               // �������� �����

	unsigned short stack[16];       // ������ �������� � ���� ����

	Memory memory;			        // ������
	GPU gpu;					    // �������
	Timers timer;					// �������
	Keyboard board;					// ����������


	int mode;						// 0 - chip48, 1 - superChip8

public:
	void init();					// ������������� ����������
	void cycle();					// ���� ����

	const Memory& getMemory();
	const GPU& getGpu();
	const Keyboard& getBoard();
	const Timers& getTimers();
};
#endif /* CPU_hpp */
