// Question 1: First argument 
int first(void *ptr)
{   
    int *int_ptr = ptr + 12;
    return *int_ptr;
}

// Question 2: Second argument 
char second(void *ptr)
{
    char *char_ptr = ptr + 6;
    return *char_ptr;
}

// Question 3: Third argument
int third(void *ptr)
{
    int *int_ptr2 = ptr + 45;
    return *int_ptr2;
}