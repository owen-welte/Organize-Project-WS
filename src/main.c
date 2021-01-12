/*
** EPITECH PROJECT, 2020
** Organize-Project-WS
** File description:
** main.c
*/

#include "project.h"

int my_strlen(const char *str)
{
    int count = 0;

    if (!str)
        return -1;
    while (str[count])
        count++;
    return count;
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_putchar(char const c)
{
    write(1, &c, 1);
}

int print_error(char const *error_message)
{
    write(2, error_message, my_strlen(error_message));
    return 84;
}

int main(int ac, char const *av[])
{
    if (ac != 3) {
        if (ac > 3)
            return print_error(TOO_MANY_ARGS);
        if (ac < 3)
            return print_error(TOO_FEW_ARGS);
    }

    for (int i = 0; i < ac; i++) {
        my_putstr(av[i]);
        my_putchar(' ');
    }
    return 0;
}