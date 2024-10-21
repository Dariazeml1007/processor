#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <sys\stat.h>

#include "stack.h"
#include "check.h"
#include "operators.h"
#include "process.h"
#include "read_from_file.h"
#include "asm.h"





int main()
{
    const char* INPUT_FILE = "command.txt";
    const char* OUTPUT_FILE = "machine_code.txt";

    assembler(INPUT_FILE, OUTPUT_FILE);

    Stack_t stk = {};
    Commands code_of_command = {};

    StackElem_t POISON = 66666;
    stack_ctor (&stk, 10, POISON);

    read_commands (&code_of_command, OUTPUT_FILE);

    process_code (&stk, code_of_command.code);


    memory_report(&stk, FREE_);

    fclose(code_of_command.test_file);
    free(code_of_command.text);
    free(code_of_command.code);
    dtor(&stk);
    return 0;
}

