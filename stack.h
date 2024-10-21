#ifndef STACK
#define STACK

typedef int StackElem_t;
typedef int Canary_t;

const double POISON_VALUE = 10000.f;

const Canary_t DED = 3565;
const Canary_t EDA = 3802;

#define specif_for_stk_elem "%d"
#define specif_for_stk_canary "%d"

#define STACK_DUMP(stk_ptr) stack_dump (stk_ptr, __LINE__, __FILE__);


struct Stack_t
{
    StackElem_t *data = {};
    size_t size       = 0;
    size_t capacity   = 0;

    FILE *dump_file          = NULL;
    FILE *memory_report_file = NULL;

    unsigned long hash_current = 0;

    StackElem_t poison = 0;

    Canary_t *left_canary  = NULL;
    Canary_t *right_canary = NULL;
};

typedef enum
{
    SHRINK,
    INCREASE
} Change_t;

typedef enum
{
    STAT_FILE_ERROR = 1,
    ERROR_WITH_READ = 1,
    OK = 0,
    SUCCESS_GET_SIZE = 0
}Status_of_read;

typedef enum
{
    STK_ERROR = 1,
    DATA_ERROR = 2,
    OK_STACK = 0
} Error_of_stack;

typedef enum
{
    BEFORE_CHANGE = -1,
    FREE_ = 0,
    AFTER_CHANGE = 1

} Status_of_change;

void stack_ctor (Stack_t *stk, int capacity, StackElem_t poison_value);
void dtor (Stack_t *stk);

void stack_push (Stack_t *stk, StackElem_t elem);
void stack_pop (Stack_t *stk, StackElem_t *x);

void change_stack_capacity (Stack_t *stk, Change_t coefficient);
unsigned long hash (Stack_t *stk);
bool check_hash (Stack_t *stk);

#endif
