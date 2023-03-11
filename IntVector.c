#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity)
{
    IntVector *p = NULL;
    p = malloc(sizeof(IntVector));
    if (p != NULL && initial_capacity >=  0)
    {
        p->indicator = malloc(sizeof(int) * initial_capacity);
        p->capacity = initial_capacity;
        if (p->indicator != NULL)
        {
            return p;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

IntVector *int_vector_copy(const IntVector *v)
{
    IntVector *copy_p = (IntVector *)malloc(sizeof(v));
    if (copy_p)
    {
        copy_p->indicator = malloc(sizeof(int) * v->capacity);
        copy_p->capacity = v->capacity;
        if (copy_p->indicator)
        {
            memcpy(copy_p->indicator, v->indicator, sizeof(int) * v->size);
            return copy_p;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

void int_vector_free(IntVector *v)
{
    free(v->indicator);
    free(v);
}

int int_vector_get_item(const IntVector *v, size_t index)
{
    return *(v->indicator + index);
}

void int_vector_set_item(IntVector *v, size_t index, int item)
{
    *(v->indicator + index) = item;
}

size_t int_vector_get_size(const IntVector *v)
{
    return v->size;
}

size_t int_vector_get_capacity(const IntVector *v)
{
    return v->capacity;
}

int int_vector_push_back(IntVector *v, int item)
{
    if (v->size > v->capacity)
    {
        return -1;
    }
    else if (v->size == v->capacity)
    {
        if (v->capacity == 0)
        {
            v->indicator = realloc(v->indicator, sizeof(int) * 1);
            v->capacity += 1;
            *(v->indicator) = item;
            v->size += 1;
            return 0;
        }
        
        v->indicator = realloc(v->indicator, sizeof(int) * v->capacity * 2);
        v->capacity *= 2;
        *(v->indicator + v->size) = item;
        v->size += 1;
        return 0;
    }
    else
    {
        *(v->indicator + v->size) = item;
        v->size += 1;
        return 0;
    }
}

void int_vector_pop_back(IntVector *v)
{
    if (v->size != 0)
    {
        v->size -= 1;
    }
}

int int_vector_shrink_to_fit(IntVector *v)
{
    if (v->size < v->capacity)
    {
        v->capacity = v->size;
        v->indicator = realloc(v->indicator, sizeof(int) * v->capacity);
        if (v->indicator != NULL)
        {
            return 0;
        }
        return -1;
    }
    else
    {
        return -1;
    }
}

int int_vector_resize(IntVector *v, size_t new_size)
{
    if (new_size > v->size)
    {    
        if (new_size > v->capacity)
        {
            int_vector_reserve(v, new_size);
            for (short i = v->size; i <= v->capacity; i++)
            {
                v->indicator[i] = 0;
            }
            v->size = new_size;
        }
        else if (new_size < v->capacity)
        {
            v->size = new_size;
            short check = int_vector_shrink_to_fit(v);
            if (check)
            {
                return -1;
            }
        }
        return 0;
    }
    else
    {
        return 0;
    }
}

int int_vector_reserve(IntVector *v, size_t new_capacity)
{
    if (new_capacity > v->capacity)
    {
        v->indicator = realloc(v->indicator, sizeof(int) * new_capacity);
        if (v != NULL)
        {
            v->capacity = new_capacity;
            return 0;
        }
        return -1;
    }
    else
    {
        return 0;
    }
}