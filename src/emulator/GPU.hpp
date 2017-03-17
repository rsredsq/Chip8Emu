//
//  GPU.hpp
//  Chip8Emulator
//

#ifndef GPU_hpp
#define GPU_hpp

#include "CHIP.h"

#define WIDTH 128
#define HEIGHT 64

enum ResolutionMode {
    LOW = 1,
    HIGH = 2
};

class GPU
{
private:
    ResolutionMode resMode;
    int width, height;
	unsigned char gfx[WIDTH][HEIGHT];

public:
    void setResolutionMode(const ResolutionMode mode);
    ResolutionMode getResolutionMode() const { return resMode; };
	void clearScreen();
    void reset();
	byte& operator()(const int i, const int j);
    
	int getWidth();
	int getHeight();
};
#endif /* GPU_hpp */