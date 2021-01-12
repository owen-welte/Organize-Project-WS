/*
** EPITECH PROJECT, 2020
** Organize-Project-WS
** File description:
** main.c
*/

#include "project.h"
#include "lib.h"

void print_usage(void)
{
    my_putstr(
            "Detect the type of the passed variable"
            "USAGE\n"
            "    ./my_prog var\n"
            "\nDESCRIPTION\n"
            "    var: The var you want to test\n"
            "         (You can have up to 10 variables)\n"
            );
}

void print_error(char const *error_message)
{
    write(2, error_message, my_strlen(error_message));
}

int check_error(int ac, const char *arg)
{
    if (ac > 10) {
        print_error(TOO_MANY_ARGS);
        return 1;
    } else if (ac < 2) {
        print_error(TOO_FEW_ARGS);
        return 1;
    }
    if (arg[0] == '-' && arg[1] == 'h') {
        print_usage();
        return 2;
    }
    return 0;
}

int detect_number(const char *arg)
{
    for (int i = 0; arg[i]; i++)
        if (arg[i] < '0' || arg[i] > '9')
            return 0;
    my_putstr("Number)");
    return 1;
}

int detect_lowcase(const char *arg)
{
    for (int i = 0; arg[i]; i++)
        if (arg[i] < 'a' || arg[i] > 'z')
            return 0;
    my_putstr("Lowcase word)");
    return 1;
}

int detect_upcase(const char *arg)
{
    for (int i = 0; arg[i]; i++)
        if (arg[i] < 'A' || arg[i] > 'Z')
            return 0;
    my_putstr("Upcase word)");
    return 1;
}

int detect_word(const char *arg)
{
    for (int i = 0; arg[i]; i++)
        if ((arg[i] < 'A' || arg[i] > 'Z') && (arg[i] < 'a' || arg[i] > 'z'))
            return 0;
    my_putstr("Word)");
    return 1;
}

int detect_arg_type(const char *arg)
{
    my_putstr(" (");
    if (detect_number(arg) == 1)
        return 0;
    else if (detect_lowcase(arg) == 1 || detect_upcase(arg) == 1)
        return 0;
    else if (detect_word(arg) == 1)
        return 0;
    else
        my_putstr("String)");
    return 1;
}

int main(int ac, char const *av[])
{
    int error_ret = check_error(ac, av[1]);

    if (error_ret == 1)
        return 84;
    else if (error_ret == 2)
        return 0;
    for (int i = 1; i < ac; i++) {
        my_putstr(av[i]);
        detect_arg_type(av[i]);
        my_putchar('\n');
    }
    return 0;
}
