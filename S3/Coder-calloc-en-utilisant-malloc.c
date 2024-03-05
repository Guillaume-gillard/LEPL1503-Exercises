#include <stdlib.h>

void *calloc2(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0) return NULL;
    int *ptr = (int *) malloc(nmemb*size);
    return ptr;
}