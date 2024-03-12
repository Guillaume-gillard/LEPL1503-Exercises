#include <unistd.h>

/* Wrapper to the malloc system call.
 * If malloc fails, sleep for 5 seconds, and then try again.
 * If malloc failed 10 times in a row, return NULL.
 */
void *sleepy_malloc(size_t s)
{
    if (s == 0) return NULL;
    int *ptr = (int *) malloc(s);
    if (*ptr != NULL) return ptr;
    sleep(5);
    int *ptr = (int *) malloc(s);
    return ptr;
}