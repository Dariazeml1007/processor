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


int get_size_of_file (const char *name_of_file)
{
    assert(name_of_file);
    int info_of_file = 0;
    struct stat buffer;


    if ((info_of_file = stat(name_of_file, &buffer)) != 0)
    {
        printf("stat failure error .%d\n", info_of_file);
        return STAT_FILE_ERROR;
    }

    return buffer.st_size;
}

int read_commands (Commands *code_of_command, const char *INPUT_FILE)
{
    assert(code_of_command);
    assert(INPUT_FILE);

    code_of_command->test_file = fopen (INPUT_FILE, "r");  // check

    code_of_command->size = get_size_of_file(INPUT_FILE);

    code_of_command->text = (char *) calloc(code_of_command->size, sizeof(char));

    if (!code_of_command->text)
    {
        printf ("Allocation memory\n");
        return ERROR_WITH_READ;
    }

    if (fread(code_of_command->text, sizeof(char), code_of_command->size, code_of_command->test_file) == 0)
    {
        printf ("Haven't read");

        return ERROR_WITH_READ;
    }

    code_of_command->code = (int *) calloc(code_of_command->size, sizeof(int));

    if (!code_of_command->code)
    {
        printf ("Allocation memory\n");
        return ERROR_WITH_READ;
    }

    int machine_command = 0, j = 0;

    for (int i = 0; i < code_of_command->size; i++)
    {
        if (code_of_command->text[i] >= '0' && code_of_command->text[i] <= '9')
        {
            machine_command = 10 * machine_command + (code_of_command->text[i] - '0');
        }
        else
        {
            code_of_command->code[j++] = machine_command;
            machine_command = 0;
        }

    }

    return OK;

}
