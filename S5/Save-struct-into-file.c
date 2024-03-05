#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

typedef struct point {
    int x;
    int y;
    int z;
} point_t;

/*
 * @pre pt != NULL, pointer to the first point_t in the array
 *      size > 0, the length of the array.
 *      filename != NULL
 * @post writes the array of point_t in the file.
 *       return 0 is everything worked correctly
 *       -1 if open() failed.
 *       -2 if close() failed.
 *       -3 if mmap() failed.
 *       -4 if munmap() failed.
 *       -5 if msync() failed.
 *       -6 if ftruncate() failed.
 *
 */
int save(point_t *pt, int size, char *filename)
{
    int global_size = sizeof(*pt) * size;
    int file = open(filename, O_CREAT | O_RDWR);
    if (file == -1) return -1;

    // Truncate the file to the appropriate size
    if (ftruncate(file, global_size) == -1) {
        close(file);
        return -6;
    }

    // Map the file to memory
    void *mapped_memory = mmap(NULL, global_size, PROT_WRITE, MAP_SHARED, file, 0);
    if (mapped_memory == MAP_FAILED) {
        close(file);
        return -3;
    }

    // Copy the data to the mapped memory
    memcpy(mapped_memory, pt, global_size);

    // Sync the mapped memory with the file
    if (msync(mapped_memory, global_size, MS_SYNC) == -1) {
        munmap(mapped_memory, global_size);
        close(file);
        return -5;
    }

    // Unmap the memory and close the file
    if (munmap(mapped_memory, global_size) == -1) {
        close(file);
        return -4;
    }
    if (close(file) == -1) return -2;
    
    return 0;
}