# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: Chieh-En Wu
Email: s1133317@mail.yzu.edu.tw

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
  int myHashInt(int key, int m) {
    return ((key % m) + m) % m;
}

  ```
- Rationale: Division method ensures each integer key maps into the valid bucket range [0, m-1]. Adding m before the modulo deals with negative keys. When m is prime, this strategy minimizes collision patterns and distributes keys more evenly.

### Non-integer Keys
- Formula / pseudocode:
  ```text
  int myHashString(const std::string& str, int m) {
    unsigned long hash_val = 0;
    for (char c : str)
        hash_val = hash_val * 31 + c;
    return static_cast<int>(hash_val % m);
}

  ```
- Rationale: The polynomial "multiply-31-add" scheme is chosen for its strong distribution properties and is widely used (e.g., Java). Each character affects the final hash, and the multiplication breaks up common prefixes, reducing collisions for similar strings. Using a prime modulus further enhances uniformity.

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
Integer Keys

| Table Size (m) | Key→Index Sequence                | Pattern/Observation      |
|----------------|-----------------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ... 9, 0, 1, ...      | Pattern repeats every 10 |
| 11             | 10, 0, 1, ...  8, 9, 7, 8, 9      | More uniform             |
| 37             | 20, 21, 22, ... 30, 14, 15, ... 23| Near-uniform             |

String Keys

| Table Size (m) | Key→Index Sequence           | Pattern/Observation                   |
|----------------|------------------------------|---------------------------------------|
| 10             | 2,4,1,9,3,8,0,5,0,3          | Several collisions, some repeats      |
| 11             | 10,6,6,7,9,6,5,5,0,9         | Collisions, slightly better than m=10 |
| 37             | 27,3,28,20,25,23,26,29,27,18 | Most keys in different buckets        |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o hash_function_cpp main.cpp hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot
- Example output for integers:
  ```
  === Hash Function Observation (C Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  ...

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      0
  ...

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  ...

  === Hash Function Observation (C++ Version) ===

=== Table Size m = 10 ===
Key     Index
-----------------
21      1
22      2
23      3
24      4
25      5
26      6
27      7
28      8
29      9
30      0
51      1
52      2
53      3
54      4
55      5
56      6
57      7
58      8
59      9
60      0

=== Table Size m = 11 ===
Key     Index
-----------------
21      10
22      0
23      1
24      2
25      3
26      4
27      5
28      6
29      7
30      8
51      7
52      8
53      9
54      10
55      0
56      1
57      2
58      3
59      4
60      5

=== Table Size m = 37 ===
Key     Index
-----------------
21      21
22      22
23      23
24      24
25      25
26      26
27      27
28      28
29      29
30      30
51      14
52      15
53      16
54      17
55      18
56      19
57      20
58      21
59      22
60      23

=== String Hash (m = 10) ===
Key     Index
-----------------
cat     2
dog     4
bat     1
cow     9
ant     3
owl     8
bee     0
hen     5
pig     0
fox     3

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     10
dog     6
bat     6
cow     7
ant     9
owl     6
bee     5
hen     5
pig     0
fox     9

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     27
dog     3
bat     28
cow     20
ant     25
owl     23
bee     26
hen     29
pig     27
fox     18

  <!-- ```

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes. -->

## Analysis
-Prime vs Non-prime Table Size:
Prime sizes (11, 37) provide more even spread and less pattern repetition, essential for minimizing clustering in hash tables.

-Collisions:
Non-prime sizes (10) create periodic collisions, reducing efficiency—evident in integer keys.

-Design improvement:
Consistently choose prime table size and robust hash functions (e.g., polynomial rolling for strings) for best results.

## Reflection
1.Good hash function design relies on both the hash method and thoughtfully chosen bucket count (m).

2.Prime table sizes reduce periodicity and collisions, showing clear improvement in experimental results.

3.For robustness, the polynomial method for strings (with carefully chosen constants) and division method for integers (~with prime m~) are recommended.

4.To further improve hash table efficiency, maintaining a load factor below 0.7 is advised. This may require dynamic resizing or initial bucket count planning based on expected data volume.
