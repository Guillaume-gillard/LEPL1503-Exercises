#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

typedef struct points {
    int NOMA;
    float LEPL1103;
    float LEPL1203;
    float LEPL1108;
    float LEPL1302;
    float LEPL1402;
    float average;
} points_t;


/*
* Function used to compare two structures based on their averages.
*
* @s1 : a pointer to the first structure
* @s2 : a pointer to the second structure
*
* @return an integer less than, equal to, or greater than zero if the first argument is considered to be
*        respectively less than, equal to, or greater than the second
*/
int compar(const void* s1, const void* s2)
{
    const points_t *struct1 = (const points_t *) s1;
    const points_t *struct2 = (const points_t *) s2;

    if (struct1->average < struct2->average) return -1;
    if (struct1->average > struct2->average) return 1;
    return 0;
}

/*
* Function used to update the file with the structures stored in it
*
* @filename : the path indicating where to find the file (!= NULL)
*
* @return 0 if no error
*        -1 if open failed
*        -2 if mmap failed
*        -3 if munmap failed
*        -4 if msync failed
*        -5 if fstat failed
*        -6 if close failed
*/
int sort(char* filename)
{
    int file = open(filename, O_RDWR);

}