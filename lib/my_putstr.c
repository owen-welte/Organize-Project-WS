/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** Print a string on stdout
*/

#include <unistd.h>
#include "lib.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
