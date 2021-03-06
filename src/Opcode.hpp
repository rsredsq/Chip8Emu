//
//  Opcode.hpp
//  Chip8
//

#ifndef Opcode_hpp
#define Opcode_hpp

#include <fstream>
#include <vector>
#include "CHIP.h"
#include <string>
#include <vector>
#include <tuple>

enum TypeArg {
	name,
	number,
	reg,
	addr,
	i,
	b,
	key,
	dt,
	st,
	v0,
	f,
	hf,
	r
};

static const std::string TypeArgStr[]{
	"string-name",
	"number",
	"register",
	"address",
	"I",
	"BCD",
	"Key",
	"Delay timer",
	"Sound timer",
	"V0",
	"font - F",
	"HyperFont - HF",
	"RPL - R"
};

struct OpcodeData {
    OpcodeData(ushort val) {
        rawCode = val;
    }
    
    union {
        struct {
            ushort n4 : 4;
            ushort n3 : 4;
            ushort n2 : 4;
            ushort n1 : 4;
        };
        ushort rawCode;
    };
};

#ifdef CHIP_EMU
#define EXEC_DESCR CPU* const, const OpcodeData
#elif CHIP_ASM
#define EXEC_DESCR std::ofstream&, int
#elif CHIP_DISASM
#define EXEC_DESCR std::ostream&, const OpcodeData
#endif

class CPU;
extern void fn_nop(EXEC_DESCR);

class Opcode final {
public:
	Opcode() : Opcode("", {}, "") {
        
    }
    
    Opcode(const char* name, const std::vector<TypeArg> arguments, const char* description, void (*exec)(EXEC_DESCR) = fn_nop);
    
    const char* getName() const { return name; };
	const std::vector<TypeArg> getArgs() const { return arguments; }
private:
    const char* name;
	const std::vector<TypeArg> arguments;
    const char* description;
public:
    void (*exec)(EXEC_DESCR);
};

#endif /* Opcode_hpp */
