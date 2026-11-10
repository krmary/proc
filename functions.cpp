void Add (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    StackElem_t i1 = StackPop(&(proc->stack));
    StackElem_t i2 = StackPop(&(proc->stack));

    StackElem_t sum = i1 + i2;
    StackPush(&(proc->stack), sum);

    proc->IP += 1;
    return;
}

void Mul (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    StackElem_t i1 = StackPop(&(proc->stack));
    StackElem_t i2 = StackPop(&(proc->stack));

    StackElem_t mul = i1 * i2;

    StackPush(&(proc->stack), mul);
    proc->IP += 1;
    return;
}

void Sub (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    StackElem_t i1 = StackPop(&(proc->stack));
    StackElem_t i2 = StackPop(&(proc->stack));

    StackElem_t raz = i2 - i1;
    StackPush(&(proc->stack), raz);

    proc->IP += 1;
    return;
}

void Div (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    StackElem_t i1 = StackPop(&(proc->stack));
    StackElem_t i2 = StackPop(&(proc->stack));

    StackElem_t del = i2 / i1;

    StackPush(&(proc->stack), del);
    proc->IP += 1;
    return;
}

void Out (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    StackElem_t i = StackPop(&(proc->stack));
    printf("%d\n", i);

    proc->IP += 1;
    return;
}

void Hlt (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    proc->IP = -1;
    return;
}

void Push (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    StackPush(&(proc->stack), proc->buffer[(proc->IP) + 1]);
    proc->IP += 2;
    return;
}

void Popr (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    proc->reg[proc->buffer[(proc->IP) + 1]] = StackPop(&(proc->stack));
    //printf("%d", proc->reg[proc->buffer[(proc->IP) + 1]]);
    proc->IP += 2;
    return;
}

void Pushr (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    //assert_my(&(proc->reg[(proc->buffer[(proc->IP) + 1])]), );
    StackPush(&(proc->stack), proc->reg[(proc->buffer[(proc->IP) + 1])]);
    proc->IP += 2;
    return;
}

void Jmp (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    proc->IP = proc->buffer[proc->IP + 1];
    return;
}

void Ja (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    int a = StackPop(&(proc->stack));
    int b = StackPop(&(proc->stack));

    if (a > b) Jmp(proc);
    else proc->IP += 2;
}

void Jae (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    int a = StackPop(&(proc->stack));
    int b = StackPop(&(proc->stack));

    if (a >= b) Jmp(proc);
    else proc->IP += 2;
}

void Jb (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    int a = StackPop(&(proc->stack));
    int b = StackPop(&(proc->stack));

    if (a < b) Jmp(proc);
    else proc->IP += 2;
}

void Jbe (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    int a = StackPop(&(proc->stack));
    int b = StackPop(&(proc->stack));

    if (a <= b) Jmp(proc);
    else proc->IP += 2;
}

void Je (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    int a = StackPop(&(proc->stack));
    int b = StackPop(&(proc->stack));

    if (a == b) Jmp(proc);
    else proc->IP += 2;
}

void Jne (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    int a = StackPop(&(proc->stack));
    int b = StackPop(&(proc->stack));

    if (a != b) Jmp(proc);
    else proc->IP += 2;
}

void Call (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    StackPush(&(proc->vozvr), proc->IP + 2);
    Jmp(proc);
}

void Ret (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    int a = StackPop(&(proc->vozvr));

    proc->IP = a;
    return;
}

void In (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    printf("enter number:");
    scanf("%d", &(proc->reg[proc->buffer[proc->IP + 1]]));

    proc->IP += 2;
    return;
}

void Pow (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    double i1 = StackPop(&(proc->stack));
    double i2 = StackPop(&(proc->stack));

    double step = pow(i2, i1);
    StackPush(&(proc->stack), (int)step);

    proc->IP += 1;
    return;
}

void Sqrt (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    double i1 = StackPop(&(proc->stack));
    double i2 = StackPop(&(proc->stack));
    double i3 = 1 / i1;

    double kor = pow(i2, i3);
    StackPush(&(proc->stack), (int)kor);

    proc->IP += 1;
    return;
}

void Pushm (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    StackPush(&(proc->stack), proc->RAM[proc->reg[proc->buffer[proc->IP + 1]]]);

    proc->IP += 2;
    return;
}

void Popm (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    int i = StackPop(&(proc->stack));
    proc->RAM[proc->reg[proc->buffer[proc->IP + 1]]] = i;

    proc->IP += 2;
    return;
}

void Printm (processor* proc) {
    assert_my(proc, );
    assert_my(&(proc->stack), );

    for (int i = 0; i < RAM_CAPACITY; i++) {
        if (proc->RAM[i] == 0) printf("-");
        else if (proc->RAM[i] == 1) printf("*");
        else printf("error");

        if (((i + 1) % 26 == 0) && (i != 0)) printf("\n");
    }

    proc->IP += 1;
    return;
}
