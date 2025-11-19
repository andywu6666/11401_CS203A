/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h
    - 2025/11/19: Change Developer and implement my own hash function

   Developer: Chieh-En Wu <s1133317@mail.yzu.edu.tw>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    
    return ((key % m) + m) % m;  
}
// C does not have std::string, so we use char* instead
int myHashString(const char* str, int m) {
    unsigned long hash_val = 0;
    while (*str) {
        hash_val = hash_val * 31 + (unsigned char)(*str);
        str++;
    }
    return (int)(hash_val % m); 
}
