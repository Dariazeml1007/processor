#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

#include "stack.h"
#include "check.h"
#include "operators.h"


int sub (Stack_t *stk)
{
    int first_number = 0;
    int second_number = 0;

    stack_pop(stk, &first_number);
    stack_pop(stk, &second_number);

    stack_push(stk, second_number - first_number);

    return 0;
}

int add (Stack_t *stk)
{
    int first_number = 0;
    int second_number = 0;

    stack_pop(stk, &first_number);
    stack_pop(stk, &second_number);
    stack_push(stk, first_number + second_number);

    STACK_DUMP(stk);

    return 0;
}

int mul (Stack_t *stk)
{
    int first_number = 0;
    int second_number = 0;

    stack_pop(stk, &first_number);
    stack_pop(stk, &second_number);

    stack_push(stk, second_number * first_number);

    STACK_DUMP(stk);
    return 0;
}

int div (Stack_t *stk)
{
    int first_number = 0;
    int second_number = 0;

    stack_pop(stk, &first_number);
    stack_pop(stk, &second_number);

    if (first_number != 0)
        stack_push(stk, second_number / first_number);

    else
        {
            printf ("division on 0 is forbidden\n");
            dtor(stk);
            assert(0);
        }

    return 0;

}
