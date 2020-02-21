/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** calloc
*/

#include "libmy_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    size_t new_size = nmemb * size;
    void *new_ptr = malloc(new_size);

    memset(new_ptr, 0, new_size);
    return (new_ptr);
}