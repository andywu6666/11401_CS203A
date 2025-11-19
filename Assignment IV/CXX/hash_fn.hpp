/* 
   ========================================
   Hash Function Observation (C++ Version)
   ========================================
   
   Description:
   This program tests and displays the output of hash functions for integer
   and string keys using different table sizes. It utilizes the hash functions
   defined in "hash_fn.cpp".

   Development History:
    - 2025/11/19: Initial implementation

   Developer: Chieh-En Wu <s1133317@mail.yzu.edu.tw>
 */
#ifndef HASH_FN_HPP
#define HASH_FN_HPP

#include <string>

int myHashString(const std::string& str, int m);
int myHashInt(int key, int m);

#endif
