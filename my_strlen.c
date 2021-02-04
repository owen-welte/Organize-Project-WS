/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** Return the len of a string
*/

int my_strlen(const char *str)
{
    int count = 0;

    if (!str)
        return -1;
    while (str[count])
        count++;
    return count;
}
