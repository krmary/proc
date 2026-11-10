#include "../virmash.h"
#include "assembler.h"
#include "asm_functions.cpp"

int main(int argc, char *argv[]) {
    func_file_ass info = {};
    strcpy(info.file_name, argv[1]);
    FileInfo(&info);
    PasteFile(&info); //TODO index num_strings ->struct
    //TODO увеличить структуру всё туда добавить и использовать один раз
    info.comm_num = 0;
    PasteFile(&info);

    free(info.index);
    free(info.buffer);
    return 0;
}

void PasteFile (func_file_ass* info) {
    assert_my(info, );
    assert_my(info->index, );

    info->fp = fopen(CODE_FILE, "w+");
    assert_my(info->fp, );

    for(int i = 0; i < info->num_strings; i++) {
        if (*(info->index[i]) == ':') {
            int label = -1;
            sscanf(info->index[i] + 1, "%d", &label);

            info->labels[label] = info->comm_num;//TODO массив структур для регистров
            continue;
        }

        if (sscanf(info->index[i], "%s %s\n", &info->func[0], &info->arg[0]) > 0) {
            info->type_func = ChooseFunc(info);
            if (info->type_func != ERROR) {
                info->all_functions[info->type_func].ptr_func(info);

            } else printf("ERROR %d func %s\n", info->type_func, info->func);

        } else continue;
    }
    fclose(info->fp);
}

void FileInfo (func_file_ass* info) {
    info->buffer = (char*)ReadFromFile(info->file_name);
    info->num_strings = CountStr(info->buffer, sizeof(char)); //TODO почистить до \n

    info->index = (char**)calloc(info->num_strings, sizeof(char*));  // ptrs to strings
    assert_my(info->index, );
    IndexPaste(info);

    for (int i = 0; i < 64; i++) info->labels[i] = -1;
}

commands ChooseFunc (func_file_ass* info) {
    for (int i = 0; i < NUM_FUNC; i++) {
        if (!strcmp(info->all_functions[i].name_func, info->func)) return info->all_functions[i].type;
    }
    return ERROR;
}

size_t SizeFile (const char* name) {
    struct stat st;
    size_t size = 0;

    assert_my(stat(name, &st) == 0, 0);
    size = st.st_size;

    return size;
}

void* ReadFromFile (const char* name) {
    fprintf(stderr, "%s\n",  name);
    FILE  *fp = fopen(name, "r");
    assert_my(fp, 0);

    size_t size = SizeFile(name);
    size_t size_type = sizeof(char);

    char*  buffer = (char*)calloc(size + 1, size_type);
    assert_my(buffer, 0);

    BufferFilling(buffer, size_type, size, fp);

    fclose(fp);
    return buffer;
}

void BufferFilling (char* buffer, size_t size_type, size_t size, FILE *fp) {
    int size_useful = 0;
    assert_my((size_useful = fread(buffer, size_type, size/size_type, fp)) != 0,  );
    *(buffer + size_useful) = '\0';

    return;
}

int CountStr (char* buffer, size_t size_type) {
    int num_lines = 1;

    for (char* p = buffer; *p; p++) {
        if (*p == '\n' && *(p + 1) != '\0') {
            ++num_lines;
        }
    }

    return num_lines;
}

void IndexPaste (func_file_ass* info) {
    *info->index = info->buffer;
    int i = 0;

    for (int line = 1; *(info->buffer + i) != '\0' && line < info->num_strings; i++) {
        if (*(info->buffer + i) == '\n' || *(info->buffer + i) == ';') {//TODO циклом заполнить всё до слеш н
            while (*(info->buffer + i) != '\n') i++;
            if (*(info->buffer + i) == '\n') *(info->index + line) = info->buffer + i + 1;
            *(info->buffer + i) = '\0';
            line++;
        }
    }

    while (*(info->buffer + i) != '\n' & *(info->buffer + i) != ';') i++;

    *(info->buffer + i) = '\0';
}

int RegIndex (const char* arg) {
    if (!strcmp(arg, "AX")) return 0;
    if (!strcmp(arg, "BX")) return 1;
    if (!strcmp(arg, "CX")) return 2;
    if (!strcmp(arg, "DX")) return 3;
    return -1;
}

