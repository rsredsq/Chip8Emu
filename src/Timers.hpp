//
//  Timers.hpp
//  Chip8Emulator
//

#ifndef Timers_hpp
#define Timers_hpp

#include <iostream>

class Timers
{
	unsigned char delay_timer;      // ������� ��������
	unsigned char sound_timer;      // � �����
public:
	void init();					// ������������� ����������
	void update();					// update timers
	
	double getSoundTimer();
	void setSoundTimer(double v);

	double getDelayTimer();
	void setDelayTimer(double v);
};

#endif /* Timers_hpp */
