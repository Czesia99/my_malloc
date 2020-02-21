/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** free
*/

#include "libmy_malloc.h"

void free(void *ptr)
{
    data_t *tmp;

    if (ptr == NULL)
        return;
    tmp = (ptr - 1);
    tmp->f = 1;
}