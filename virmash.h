#define CODE_FILE "tests/code1.res"
//#define TEXT_FILE "tests/text_code.ASM"

#define NUM_FUNC 24

enum commands {
    HLT    = 0,
    PUSH   = 1,
    ADD    = 2,
    SUB    = 3,
    DIV    = 4,
    OUT    = 5,
    PUSHR  = 6,
    POP    = 7,
    MUL    = 8,
    JMP    = 9,
    JA     = 10,
    JAE    = 11,
    JB     = 12,
    JBE    = 13,
    JE     = 14,
    JNE    = 15,
    CALL   = 16,
    RET    = 17,
    IN     = 18,
    POW    = 19,
    SQRT   = 20,
    PUSHM  = 21,
    POPM   = 22,
    PRINTM = 23,
    ERROR  = -1
};
