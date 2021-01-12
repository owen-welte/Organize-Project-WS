/*
** EPITECH PROJECT, 2020
** Organize-Project-WS
** File description:
** main.c
*/

#include "project.h"
#include "lib.h"

void print_error(char const *error_message)
{
    write(2, error_message, my_strlen(error_message));
}

int check_error(int ac)
{
    if (ac != 3) {
        if (ac > 3) {
            print_error(TOO_MANY_ARGS);
            return 1;
        } else if (ac < 3) {
            print_error(TOO_FEW_ARGS);
            return 1;
        }
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
    if (check_error(ac) == 1)
        return 84;
    for (int i = 0; i < ac; i++) {
        my_putstr(av[i]);
        detect_arg_type(av[i]);
        my_putchar('\n');
    }
    return 0;
}
