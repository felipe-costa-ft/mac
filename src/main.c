typedef enum {
	PSH,
	ADD,
	POP,
	SEF,
	HLT
} InstructionSet;

const int program[] = {
	PSH, 5,
	PSH, 6,
	ADD,
	POP,
	HLT
};
