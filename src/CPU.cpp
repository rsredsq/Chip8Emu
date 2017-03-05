//
//  CPU.cpp
//  Chip8Emulator
//
//
//
//

#include "CPU.hpp"

void CPU::init()
{
	PC = 0x200;								// ������ ���������� � 0x200
	opcode = ops[0xFFFF];					// ���������� �����
	I = 0;									// ���������� �������
	SP = 0;									// ���������� stack pointer

	for(int i = 0; i < 16; i++)				// �������� ��� ��������
		V[i] = 0;

	for (int i = 0; i < 16; i++)			// ������� ����
		stack[i] = 0;

	memory.init();							// �������������� ������
	gpu.init();								// �������������� GPU
	timer.init();							// �������������� ������
	board.init();							// �������������� ����������

	mode = 0;								// �� ��������� chip48
}

void CPU::cycle()
{
	static unsigned short rawCode = memory[PC] | memory[PC + 1];						// �������� �����
	PC += 2;																			// ��������� � ��������� ����������

	opcode = getOpCode({rawCode});														// ������ �����
	opcode.exec(this);																	// ��������� �����

	timer.update();																		// �������� ������

}

const Memory& CPU::getMemory()
{
	return memory;
}

const GPU& CPU::getGpu()
{
	return gpu;
}

const Keyboard& CPU::getBoard()
{
	return board;
}

const Timers& CPU::getTimers()
{
	return timer;
}