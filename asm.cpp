#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

#include "asm.h"
#include "read_from_file.h"

// 1 push, 2 add, 3 sub, 4 mul, 5 div, 6 out,7 in, 0 hlt

struct Type_of_command
{
    const char *name_command;
    int code_of_command ;
};

Type_of_command massive_of_commands[] =
{
    {"push", 1},
    {"add" , 2},
    {"sub" , 3},
    {"mul" , 4},
    {"div" , 5},
    {"out" , 6},
    {"in"  , 7},
    {"hlt" , 0}
};

int type_of_command (const char* command);

int assembler (const char* input_file, const char* output_file)
{
    int size = get_size_of_file(input_file);

    FILE *file_in  = fopen(input_file, "r");
    FILE *file_out = fopen(output_file, "wb");


    if (file_in == NULL)
    {
        printf("The input file has't opened");
        return -1;
    }

    if (file_out == NULL)
    {
        printf("The output file has't opened");
        return -1;
    }

    char c = '0'; // count strings
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        fscanf(file_in, "%c", &c);
        if (c == '\n')
            count++;
    }

    fseek(file_in, 0, SEEK_SET);

    char command[50] = {};

    for (int i = 0; i < count; i++)
    {
        fscanf(file_in, "%s ", command);
        int type = type_of_command(command);
        fprintf (file_out,"%d", type);

        if (type == 1)
        {
        fscanf(file_in, "%s ", command);
        int a = atoi(command);
        fprintf (file_out," %d", a);
        }

        if (type == 0)
            break;
        fprintf (file_out,"\n");
    }

    if (fclose (file_in) || fclose (file_out))
    {
        printf ("One or two files haven't closed\n");
        assert(0);
    }

    return 0;
}

int type_of_command (const char* command)
{
    int size_of_array = sizeof(massive_of_commands) / sizeof(massive_of_commands[0]);

    for (int i = 0; i < size_of_array; i++)
    {
        if (strcmp(command, massive_of_commands[i].name_command) == 0)
            return massive_of_commands[i].code_of_command;
    }

    printf("Not such command");
    return -1;
}
