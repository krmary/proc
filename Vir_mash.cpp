#include "../virmash.h"
#include "processor.h"
#include "functions.cpp"

int main(void) {
    struct processor proc = {};
    proc.buffer = ReadFromFile(CODE_FILE, &proc);

    proc.stack = {0};
    proc.vozvr = {0};
    size_t capacity = 5;
    StackInit(&proc.stack, capacity);
    StackInit(&proc.vozvr, capacity); //TODO стеки в проц
    //TODO func inic

    while (proc.IP != -1) {
        CheckComand(&proc);
        StackDump(&proc.stack);
    }

    DestroyData(&proc.stack);
    free(proc.buffer);
    return 0;
}

void PrintVM (processor* proc, stack_t* stk) {
    for (int i = 0; proc->buffer[i] != -1; i++) {
        if (i == proc->IP) fprintf(stk->fp1, "->");
        else fprintf(stk->fp1, "  ");

        fprintf(stk->fp1, "%d\n", proc->buffer[i]);
    }
    StackDump(stk);
}

void CheckComand (processor* proc) {
    int comand = proc->buffer[proc->IP];
    if (comand > NUM_FUNC) {
        printf("ERROR uncnown operation %d %d\n", comand, proc->IP);
        return;
    }
    proc->all_functions[comand].ptr_func(proc);
    // switch (comand) {
    //     case PUSH:
    //         Push(proc);
    //         break;
    //     case ADD:
    //         Add(proc);
    //         break;
    //     case SUB:
    //         Sub(proc);
    //         break;
    //     case DIV: //TODO struct
    //         Div(proc);
    //         break;
    //     case OUT:
    //         Out(proc);
    //         break;
    //     case POP:
    //         Popr(proc);
    //         break;
    //     case PUSHR:
    //         Pushr(proc);
    //         break;
    //     case MUL:
    //         Mul(proc);
    //         break;
    //         //______________________________________ //TODO блоки логические
    //     case JMP:
    //         Jmp(proc);
    //         break;
    //     case JA:
    //         Ja(proc);
    //         break;
    //     case JAE:
    //         Jae(proc);
    //         break;
    //     case JB:
    //         Jb(proc);
    //         break;
    //     case JBE:
    //         Jbe(proc);
    //         break;
    //     case JE:
    //         Je(proc);
    //         break;
    //     case JNE:
    //         Jne(proc);
    //         break;
    //     case CALL:
    //         Call(proc);
    //         break;
    //     case RET:
    //         Ret(proc);
    //         break;
    //     case IN:
    //         In(proc);
    //         break;
    //     case HLT:
    //         Hlt(proc);
    //         break;
    //     case POW:
    //         Pow(proc);
    //         break;
    //     case SQRT:
    //         Sqrt(proc);
    //         break;
    //     default:
    //         printf("UNKNOWN operation %d %d\n", comand, proc->IP);
    //         proc->IP += 1;
    //         break;
    // }
    return;
}

int* ReadFromFile (const char* name, processor* proc) {
    assert_my(name, 0);
    FILE  *fp = fopen(name, "r");
    assert_my(fp, 0); //TODO name .

    size_t size_type = sizeof(int);
//TODO snprintf
    int  size_buffer = 10;
    int* buffer = (int*)calloc(size_buffer, size_type);
    assert_my(buffer, 0);
    int is_digit = 0;

    for(int i = 0; (is_digit = fscanf(fp, "%d", &buffer[i])) != -1; i++) {
        if (i + 1 >= size_buffer) {
            size_buffer *= 2;
            int* new_buffer = (int*)realloc((void*)buffer, size_buffer*size_type);

            if (new_buffer == NULL) {
                free(buffer);
                return NULL;
            }

            buffer = new_buffer;
        }
    }
    fclose(fp);
    return buffer;
}
