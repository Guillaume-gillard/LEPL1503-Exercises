#include <string.h>
#define true 1
#define false 0

/*
* @return: returns true (1) if str is a palindrome, -1 if str is NULL, otherwise false (0).
*/
int pal(char *str)
{
    if (str == NULL) return -1;
    size_t str_len = strlen(str);
    int left_counter = 0;
    int right_counter = str_len - 1;
    while (true) {
        while (str[left_counter] == ' ') left_counter++;
        while (str[right_counter] == ' ') right_counter--;
        
        if (str[left_counter] != str[right_counter] || (str[left_counter] ^ 32) != str[right_counter]) return 0;
        left_counter++;
        right_counter--;
    }
    return 1;
}