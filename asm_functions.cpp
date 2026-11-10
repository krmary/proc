void Jmp (func_file_ass* info) {
    assert_my(info, );

    int label = -1;
    if (info->arg[0] == ':') {
        sscanf(&(info->arg[1]), "%d", &label);
    } else {
        info->error = 1;
    }

    if (info->labels[label] != -1) {
        fprintf(info->fp, "9 %d\n", info->labels[label]);
    }
    info->comm_num += 2;
}

void Push (func_file_ass* info) {
    assert_my(info, );

    int arg_num = 0;

    if (sscanf(info->arg, "[%2s]", info->arg)) {
        if (!(strcmp(info->arg, "AX") && strcmp(info->arg, "BX") && strcmp(info->arg, "CX") && strcmp(info->arg, "DX"))) {
            fprintf(info->fp, "21 %d\n", RegIndex(info->arg));
            info->comm_num += 2;

        } else info->error = 1;

    } else if (sscanf(info->arg, "%d", &arg_num)) {
        fprintf(info->fp, "1 %d\n", arg_num);
        info->comm_num += 2;

    } else {
        if (!(strcmp(info->arg, "AX") && strcmp(info->arg, "BX") && strcmp(info->arg, "CX") && strcmp(info->arg, "DX"))) {
            fprintf(info->fp, "6 %d\n", RegIndex(info->arg));
            info->comm_num += 2;

        } else info->error = 1;
    }
}

void Pop (func_file_ass* info) {
    assert_my(info, );

    int arg_num = 0;

    if (sscanf(info->arg, "[%2s]", info->arg)) {
        if (!(strcmp(info->arg, "AX") && strcmp(info->arg, "BX") && strcmp(info->arg, "CX") && strcmp(info->arg, "DX"))) {
            fprintf(info->fp, "22 %d\n", RegIndex(info->arg));
            info->comm_num += 2;

        } else info->error = 1;

    } else if (!(strcmp(info->arg, "AX") && strcmp(info->arg, "BX") && strcmp(info->arg, "CX") && strcmp(info->arg, "DX"))) {
        fprintf(info->fp, "7 %d\n", RegIndex(info->arg));
        info->comm_num += 2;

    } else info->error = 1;
}

void K1_func (func_file_ass* info) {
    assert_my(info, );

    fprintf(info->fp, "%d\n", info->type_func);
    info->comm_num += 1;
}

void K2_func (func_file_ass* info) {
    assert_my(info, );

    int arg_num = 0;
    sscanf(info->arg, "%d", &arg_num);

    fprintf(info->fp, "%d %d\n", info->type_func, arg_num);
    info->comm_num += 2;
}

void Call (func_file_ass* info) {
    assert_my(info, );

    int label = -1;
    if (info->arg[0] == ':') {
        sscanf(&(info->arg[1]), "%d", &label);

    } else info->error = 1;

    if (info->labels[label] != -1) {
        fprintf(info->fp, "16 %d\n", info->labels[label]);
    }

    info->comm_num += 2;
}

void In (func_file_ass* info) {
    assert_my(info, );

    if (!(strcmp(info->arg, "AX") && strcmp(info->arg, "BX") && strcmp(info->arg, "CX") && strcmp(info->arg, "DX"))) {
            fprintf(info->fp, "18 %d\n", RegIndex(info->arg));
            info->comm_num += 2;

    } else info->error = 1;
}
