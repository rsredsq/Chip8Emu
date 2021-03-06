//
//  typeToken.h
//  Chip8Asm
//

#ifndef typeToken_h
#define typeToken_h

#include <string>

enum TypeToken {
	NAME,
	DT,
	ST,
	ADDR, // [i]
	I,	  // I
	B,    // BCD == 'b'
	F,
	HF,
	R,
	KEY,
	LABEL,
	CMD,
	REG,
	HEX,
	DEC,
	BIN,
	COMMENT,
	NIL
};

static const std::string TypeTokenStr[] = {
	"NAME",
	"DT",
	"ST",
	"ADDR",
	"I",
	"B",
	"F",
	"HF",
	"RPL",
	"K",
	"LABEL",
	"CMD",
	"REG",
	"HEX",
	"DEC",
	"BIN",
	"COMMENT",
	"NIL"
};

#endif /* typeToken.h */
