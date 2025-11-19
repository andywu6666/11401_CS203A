/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp
    - 2025/11/19: Change Developer and implement my own hash function

   Developer: Chieh-En Wu <s1133317@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    
    return ((key % m) + m) % m;  
}

int myHashString(const std::string& str, int m) {
    unsigned long hash_val = 0;
    for (char c : str) {
        hash_val = hash_val * 31 + c;
    }
    return static_cast<int>(hash_val % m);  
}
