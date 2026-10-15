* struct - collection of variables with different types as one entity for convenient handling.

* typedef - to give a type another name.

* enum - user define type that assigns names to a set of integer constants. start with 0 ... n

---

* size_t - unsigned int (match max addressable memory space by os/architecture-dependent)

* _Float16 - 16 bits (half-precision floating-point)

* float - 32 bit (single precision)

* double - 64 bit (double precision)

---

* Shallow copy - copies only the memory address (pointer) both variables end up pointing to the exact same shared block of data. if the original data dies or changes, the copy breaks.

* Deep Copy:  Allocates brand new, independent memory space on the heap and clones the actual values over. The two variables become entirely independent.

--- 

* malloc - manual memory allocation on Heap segment of RAM.
    - returns void* pointer to the start of the allocated memory block.
    - return NULL of size.
    - persistent until explicitly freed via free().
    - For large memory allocations (greater than ~512 bytes), 
        allocate memory in multiples of 512 bytes to maximise space efficiency. 
    - For small allocations (1–512 bytes), allocate only the required amount to improve CPU performance by making better use of cache lines.
        - Example 1: Shape (4, 3) → 12 elements → \(12 \times 8 = 96\) bytes → allocate 96 bytes (small allocation, below 512 bytes).
        - Example 2: Shape (100, 100) → 10,000 elements → \(10{,}000 \times 8 = 80{,}000\) bytes → allocate 80,384 bytes (next multiple of 512 bytes).

* free - releases memory allocated by malloc, preventing memory leaks.