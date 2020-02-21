/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** utils
*/

#include "libmy_malloc.h"

unsigned int adjust_data_size(size_t size)
{
    unsigned int i = 1;

    for (; i < size; i *= 2);
    return (i);
}