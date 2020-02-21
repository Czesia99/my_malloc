/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** malloc
*/

#include "libmy_malloc.h"

data_t *init_block(unsigned int size)
{
    data_t *data = sbrk(0) - glob.free_size;

    data->size = size;
    data->f = 0;
    return (data);
}

data_t *find_free_node(unsigned int size)
{
    data_t *tmp = glob.list;

    for (; tmp; tmp = tmp->next) {
        if (tmp->f == 1 && size + DATA_SIZE <= tmp->size) {
            return (tmp);
        }
    }
    return (NULL);
}

int more_heap(unsigned int size)
{
    unsigned int i = 0;

    for (; i < size; i += PAGE_SIZE);
    if (sbrk(i) == (void *)-1)
        return (-1);
    glob.total_size += i;
    glob.free_size = glob.total_size - glob.used_size;
    return (0);
}

data_t *push_front_node(data_t *node)
{
    if (glob.list == NULL)
        node->next = NULL;
    else
        node->next = glob.list;
    glob.used_size += DATA_SIZE + node->size;
    glob.free_size = glob.total_size - glob.used_size;
    return (node);
}

void *malloc(size_t size)
{
    void *limit = NULL;
    unsigned int _size = 0;

    if (!size)
        return (NULL);
    _size = adjust_data_size(size);
    limit = find_free_node(_size);
    if (!limit)
    {
        if (_size + DATA_SIZE > glob.free_size) {
            if (more_heap(_size + DATA_SIZE) == -1)
                return (NULL);
        }
        data_t *node = init_block(_size);
        glob.list = push_front_node(node);
        limit = (void *)glob.list;
    }
    if (limit == NULL)
        return (NULL);
    return (limit + DATA_SIZE);
}