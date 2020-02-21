/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** libmy_malloc
*/

#ifndef LIBMY_MALLOC_H_
#define LIBMY_MALLOC_H_

//#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define PAGE_SIZE (getpagesize() * 2)
#define DATA_SIZE (adjust_data_size(sizeof(data_t)))

//------ Structure ------

typedef struct data_s 
{
    unsigned int size;
    unsigned char f;
    struct data_s *next;
} data_t;

typedef struct glob_s
{
    data_t *list;
    unsigned int total_size;
    unsigned int used_size;
    unsigned int free_size;
} glob_t;

glob_t glob;

//------ Prototypes ------

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

//malloc
data_t *init_block(unsigned int size);
data_t *find_free_node(unsigned int size);
int more_heap(unsigned int size);
data_t *push_front_node(data_t *node);

//utils
unsigned int adjust_data_size(size_t size);

#endif /* !LIBMY_MALLOC_H_ */