// Question 1: First argument 
/*
* You found a hint from the hacker, telling the first parameter is located at the 12th byte after ptr. 
* An int is guaranteed to be 4 bytes long.
*
* Write the body of the function first which returns the integer at that position in memory.
*/
int first(void *ptr)
{   
    int int_ptr = (int *) ptr 
    return *(ptr + 12);
}

// Question 2: Second argument 
char second(void *ptr)
{
    return *(ptr + 6);
}

// Question 3: Third argument
int third(void *ptr)
{
    return *(ptr + 45)
}