#include <stdlib.h> 
#include <string.h> 
/*
* Creates a buffer that has the same size as src, and copies the content of src to this buffer.
*
* @src: string to be copied
* @return: return pointer. if src == NULL or in case of error, return NULL
*
* Remember that strings are terminated with '\0' and that strlen("abc") returns 3 even if 4 bytes are required to store this string.
*/
char *buf_strcpy(const char *src)
{
    if (src == NULL) return NULL;
    int src_len = strlen(src);
    char *buffer = malloc((src_len + 1) * sizeof(char));
    if (buffer == NULL) return NULL; //fail of memory allocation
    int i;
    for (i = 0; src[i]; i++){
        buffer[i] = src[i];
    }
    buffer[i] = '\0';
    return buffer;
}