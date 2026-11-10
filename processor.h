#include "../stack.h"
#include <sys/stat.h>

#define RAM_CAPACITY 338
//typedef int StackElem_t;
struct processor;

struct func_type {
    void (*ptr_func)(processor* proc);
    commands type;
};

int*   ReadFromFile (const char* name, processor* proc);
void   CheckComand  (processor* proc);
void   PrintVM      (processor* proc);

void   Add   (processor* proc);
void   Mul   (processor* proc);
void   Sub   (processor* proc);
void   Div   (processor* proc);

void   Out   (processor* proc);
void   Hlt   (processor* proc);

void   Push  (processor* proc);
void   Pop   (processor* proc);

void   Jmp   (processor* proc);

void   Popr  (processor* proc);
void   Pushr (processor* proc);

void   Ja    (processor* proc);
void   Jae   (processor* proc);
void   Jb    (processor* proc);
void   Jbe   (processor* proc);
void   Je    (processor* proc);
void   Jne   (processor* proc);

void   Call  (processor* proc);
void   Ret   (processor* proc);

void   In    (processor* proc);

void   Pow   (processor* proc);
void   Sqrt  (processor* proc);

void   Pushm (processor* proc);
void   Popm  (processor* proc);

void   Printm (processor* proc);

struct processor {
    int reg[4];
    int RAM[RAM_CAPACITY];
    int IP = 0;
    StackElem_t* buffer; //TODO стек возврата логи
    stack_t vozvr;
    stack_t stack;
    int num_com;
    struct func_type all_functions[NUM_FUNC] = {{Hlt,   HLT},
                                                {Push,  PUSH},
                                                {Add,   ADD}, {Sub, SUB}, {Div, DIV},
                                                {Out,   OUT},
                                                {Pushr, PUSHR}, {Popr, POP},
                                                {Mul,   MUL},
                                                {Jmp,   JMP},
                                                {Ja,    JA}, {Jae, JAE}, {Jb, JB}, {Jbe, JBE}, {Je, JE}, {Jne, JNE},
                                                {Call,  CALL},
                                                {Ret,   RET},
                                                {In,    IN},
                                                {Pow,   POW}, {Sqrt, SQRT},
                                                {Pushm, PUSHM}, {Popm, POPM}, {Printm, PRINTM}};

};
