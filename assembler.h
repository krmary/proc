#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <malloc.h>
#include "../assert_my.h"
#include <string.h>

struct func_file_ass;

struct func_type {
    void     (*ptr_func)(func_file_ass* info);
    char     name_func[15];
    commands type;
};

void     PasteFile  (func_file_ass* info);
void     FileInfo   (func_file_ass* info);
commands ChooseFunc (func_file_ass* info);
int      RegIndex   (const char* arg);

void Jmp     (func_file_ass* info);
void Push    (func_file_ass* info);
void Pop     (func_file_ass* info);
void K1_func (func_file_ass* info);
void K2_func (func_file_ass* info);
void Call    (func_file_ass* info);
void In      (func_file_ass* info);

size_t SizeFile      (const char* name);
void*  ReadFromFile  (const char* name);
void   BufferFilling (char* buffer, size_t size_type, size_t size, FILE* fp);
int    CountStr      (char* buffer, size_t size_type);
void   IndexPaste    (func_file_ass* info);

struct func_file_ass { //TODO func_file_ass new name /
    char   func   [10] = {0};
    char   arg    [10] = {0};
    int    labels [64] = {-1};
    int    num_strings;
    char** index;
    char*  buffer;
    int    type_func = -1;
    int    error     =  0;
    int    comm_num  =  0;
    FILE*  fp =  0;
    char   file_name[30] = {0};
    struct func_type all_functions[NUM_FUNC] = {{K1_func, "hlt",    HLT},
                                                {Push,    "push",   PUSH},
                                                {K1_func, "add",    ADD},
                                                {K1_func, "sub",    SUB},
                                                {K1_func, "div",    DIV},
                                                {K1_func, "out",    OUT},
                                                {Push,    "push",   PUSH},
                                                {Pop,     "pop",    POP},
                                                {K1_func, "mul",    MUL},
                                                {Jmp,     "jmp",    JMP},
                                                {K2_func, "ja",     JA},
                                                {K2_func, "jae",    JAE},
                                                {K2_func, "jb",     JB},
                                                {K2_func, "jbe",    JBE},
                                                {K2_func, "je",     JE},
                                                {K2_func, "jne",    JNE},
                                                {Call,    "call",   CALL},
                                                {K1_func, "ret",    RET},
                                                {In,      "in",     IN},
                                                {K1_func, "pow",    POW},
                                                {K1_func, "sqrt",   SQRT},
                                                {Push,    "push",   PUSH},
                                                {Pop,     "pop",    POP},
                                                {K1_func, "printm", PRINTM}};
};
