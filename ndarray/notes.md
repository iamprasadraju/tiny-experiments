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
