#include <stdio.h>
#include <stdbool.h>

typedef enum {
    A, B, C, D, E, F, PC, SP,
    NUM_OF_REGISTERS
} Registers;

int registers[NUM_OF_REGISTERS];


#define sp (registers[SP])
#define ip (registers[PC])

bool running = true;
int stack[256];

typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};

void eval(int instr) {
    switch (instr) {
        case HLT: {
            running = false;
            break;
        }
        case PSH: {
            sp++;
            stack[sp] = program[++ip];
            break;
        }
        case POP: {
            // store the value at the stack in val_popped THEN decrement the stack ptr 
			int val_popped = stack[sp--];
    
            // print it out!
            printf("%d\n", val_popped);
            break;
        }
        case ADD: {
            // first we pop the stack and store it as 'a'
            int a = stack[sp--];

            // then we pop the top of the stack and store it as 'b'
            int b = stack[sp--];

            // we then add the result and push it to the stack
            int result = a + b;
            sp++;
            stack[sp] = result;

            // all done!
            break;
        }
    }
}

int fetch() {
    return program[ip];
}

int main() {
    while(running) {
        eval(fetch());
        ip++; // increment the ip every iteration
    }
}
