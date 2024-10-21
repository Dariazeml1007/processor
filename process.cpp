#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

#include "stack.h"
#include "check.h"
#include "operators.h"
#include "process.h"

int process_code (Stack_t *stk, int code[])
{
    int ip = -1;
    int flag = 1;

    while (flag)
    {
       ip += 1;
       STACK_DUMP(stk);
       switch(code[ip])
       {

            case 1 :
            {
                stack_push(stk, code[ip + 1]);
                ip += 1;
                break;
            }

            case 2:
            {
                add(stk);
                break;
            }

            case 3: // enum
            {
                sub(stk);
                break;
            }

            case 4:
            {
                mul(stk);
                break;
            }

            case 5:
            {
                div(stk);
                break;
            }

            case 6:
            {

                int result = 0;
                stack_pop(stk, &result);
                printf ("%d \n", result);
                STACK_DUMP(stk);
                break;
            }

            case 7:
            {
                int new_elem = 0;
                scanf ("%d", &new_elem);
                stack_push(stk, new_elem);
                break;
            }

            case 0:
            {
                flag = 0;
                break;
            }

            default :
            {
                assert (0 && "not correct command");
            }

       }
    }

    return 0;

}
