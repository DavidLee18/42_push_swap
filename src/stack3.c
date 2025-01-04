
#include "push_swap.h"

size_t  *twisted_sorted(t_list **dyn, t_vec v)
{
    size_t  i;
    size_t  *res;

    i = 0;
    res = (size_t *)gc_calloc(dyn, 1, sizeof(size_t));
    if (res == NULL)
        return (NULL);
    while (i < v.len)
    {
        if (alt_sorted(v, i))
        {
            *res = i;
            return (res);
        }
        i++;
    }
    return (NULL);
}

_Bool	alt_sorted(t_vec v, size_t offset)
{
    size_t  alt_top;
    size_t  alt_bottom;
    size_t  i;

    alt_top = wrapping_sub(v.top, offset, v.len);
    alt_bottom = wrapping_sub(v.bottom, offset, v.len);
    i = wrapping_sub(alt_top, 1, v.len);
    while (i != alt_bottom)
    {
        if (v.ptr[i] > v.ptr[wrapping_sub(i, 1, v.len)])
            return (0);
        i = wrapping_sub(i, 1, v.len);
    }
    return (1);
}