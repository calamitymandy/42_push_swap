#include "push_swap.h"

int *crea_index(int stack, size_t size)
{
    size_t  i;
    size_t  j;
    size_t  value;
    int     *index;

    i = -1;
    j = -1;
    index = malloc(sizeof(int) * (size + 1));
    if (!index)
        return (NULL);
    index[size] = '\0';
    while (++i < size)
    {
        while (++j < size)
            if (stack[i] > stack[j])
                value++;
            index[i] = value;
            value = 0;
            j = -1;
    }
    return (index);
}