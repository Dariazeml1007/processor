#ifndef READ
#define READ

struct Commands
{
    int *code = {};
    char *text = {};
    int size = 0;
    FILE *test_file = NULL;
};


int get_size_of_file (const char *name_of_file);
int read_commands (Commands *code_of_command, const char *INPUT_FILE);

#endif
