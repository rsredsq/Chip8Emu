//
//  Keyboard.cpp
//  Chip8Emulator
//
//  
//
//

#include "Keyboard.hpp""

void Keyboard::init()
{
	// ��������� ������
	for (int i = 0; i < 16; i++)
		key[i] = 0;

	// �������� �������
	for (int i = 0; i < 50; ++i)
		memory[i] = font[i];
}