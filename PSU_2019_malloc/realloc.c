/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** realloc
*/

#include "libmy_malloc.h"

void *realloc(void *ptr, size_t size)
{
    data_t *tmp = ptr - 1;
    void *new_ptr = NULL;

    if (ptr == NULL)
        return (malloc(size));
    if (tmp->size >= size)
        return (ptr);
    new_ptr = malloc(size);
    new_ptr = memcpy(new_ptr, ptr, tmp->size);
    return (new_ptr);
}