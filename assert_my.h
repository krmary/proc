#ifdef STACK_DEBUG
    #define ON_DBG(...) __VA_ARGS__

    #define PrintInfo fprintf(fp, "file: %s, function: %s, line: %d, date: %s, time: %s\n", file, func, line, date, time)

    #define StackInit(stk, capacity) \
    { \
        (stk)->err = stackinit(stk, capacity); \
        if ((stk)->err != STK_OK) \
            CheckStack((stk)->fp1, (stk)->err, __func__, __FILE__, __LINE__, __DATE__, __TIME__); \
    }

    #define StackPush(stk, value) \
    { \
        (stk)->err = stackpush(stk, value); \
        if ((stk)->err != STK_OK) \
            CheckStack((stk)->fp1, (stk)->err, __func__, __FILE__, __LINE__, __DATE__, __TIME__); \
    }

    #define StackPop(stk) \
        stackpopSafe((stk)->fp1, stk, __func__, __FILE__, __LINE__, __DATE__, __TIME__);

    #define StackDump(stk) PrintStack(stk, __func__, __FILE__, __LINE__);

#else
    #define ON_DBG(...)

    #define PrintInfo
    #define StackPush(stk, value) \
    { \
        (stk)->err = stackpush(stk, value); \
        if ((stk)->err != STK_OK) \
            CheckStack((stk)->fp1, (stk)->err); \
    }

    #define StackPop(stk) \
        stackpopSafe((stk)->fp1, stk);

    #define StackInit(stk, capacity) \
    { \
        (stk)->err = stackinit(stk, capacity); \
        if ((stk)->err != STK_OK) \
            CheckStack((stk)->fp1, (stk)->err); \
    }

    #define StackDump(stk)
#endif

#define assert_my(condition, red_param) \
    { \
        if(! condition) \
        { \
            fprintf(stderr, "HELLO\nerror:( : condition: " #condition ",\n\
            %s:%d function: %s, ", __FILE__, __LINE__, __func__); \
            return red_param; \
        } \
    }




