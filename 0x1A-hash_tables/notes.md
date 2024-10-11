# ***Notes on Hash Tables***

## What is a Hash Table?
A hash table is a *data structure* that maps `keys` to `values`. We use it to insert, look up and remove key-value pairs quickly. A `hash function` translates each key into a distinct index in an array.
> A **key** is a unique integer used for indexing the values
> A **value** is the data associated with keys.

### Hashing (Hash Function)
Hashing is a technique that maps a large data set to a small data set. This mapping is done using a *hash function*. We use keys to process new indexes and store the corresponding element in the index.
The process of hashing is irreversible and the original value of the key cannot be found because we are trying to map a large dataset into a small one, which may cause collisions.

***Example***
let `k` be a key and `h(x)` be a hash function.
`h(k)` will give us a new index to store the element linked with `k`.

### Collisions
Hash collisions occur when hushing generates the same inex for multiple keys causing a conflict.
To resolve hash collisions, we can:
    - Collision resolution by chaining
    - Open Addressing: Linear/Quadratic Probing and Double Hashing.

#### 1. Collision resolution by chaining
If a hash function produces the same index for multiple elements, we can store these elements in a doubly linked list.

Here is pseudocode for the operations
```
chained_hash_search(T, k)
    return t[h(k)]
chained_hash_insert(T, x)
    T[h(x.key)] = x //insert at the head
chianed_hash-Delete(T, x)
    T[h(x.key)] = NIL
```

#### 2. Open Addressing
In this method, we don't store multiple elements into the same slot. Each slot only stores one key or left `NIL`.
Different techniques used in open addressing one:

***i. Linear Probing***
Collisions resolved by checking the next slot.
`h(k, i) = (h'(k) + i) mod m`
where
    - `i = {0, 1, ... ,}`
    - `h'(k)` is a new hash function

If a collision occurs at `h(k, 0)`, then `h(k, 1)` is checked. In this way, the value of `i` is incremented linearly.
The problem with linear probing is that a cluster of adjacent slots is filled. When insert a new element, the entire cluster must be traversed. This adds to the time required to perform operations on the hash table.

***ii. Quadratic Probing***
Unlike with `Linear Probing`, the spacing between the slots is increased using:

h(k, i) = (h'(k)) + c<sub>1</sub>i + c<sub>1</sub>i<sup>2</sup> mod m

where
    - c<sub>1</sub> and c<sub>2</sub> are positive auxiliary constants - `i = {0, 1, ...,}`

***iii. Double Hashing***
This solution works by calculating a new hash function for finding the next slot.

h(k, i) = (h<sub>1</sub>(k) + ih<sub>2</sub>(k)) mod m

## Components of Hashing
**Bucket Index**
The 'hash function` returns a value wjich is the bucket index for a key in a separate chaining method. Each index in the array is called a ucket as it is a bucket of a lined list

**Rehashing**
This is a concept that reduces collisions when we increase elements in the hash table. It creates a new array that is twice the size and copies the previous one's elements into it. This doubling of the array size should be dynamic and reflect some changes. Since the capacity of the hash table is in the hash function, the bucket indexes should be different when the key values from the previous array are copied over.
Generally, if the load factor is greater than 0.5, rehashings are done.
    - Double the size of the array
    - copy the elements from the previous array to the new one.
    - delete previous array from memory and point your hash map's array pointer to the new one
    - Load Factor = num of elements in Hash Map / capacity

### Major Functions
- Insertion
- searching
- Hash Function
- Delete
- Rehashing

#### Implementation
**Header file**
This just includes all the headers and function prototypes we'll need for the functions we'll create.
It also includes the linked list node and table data structure.

```c
#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
     char *key;
     char *value;
     struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
     unsigned long int size;
     hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);


#endif /* HASH_TABLES_H */
```


## Sources
1. (Towards Dev)[https://towardsdev.com/getting-started-with-hash-tables-in-c-a-beginners-guide-88ef312fbb9d]
2. (Ben Hoyt)[https://benhoyt.com/writings/hash-table-in-c/]
3. (Geeks for Geeks)[https://www.geeksforgeeks.org/hash-table-data-structure/]
4. (programiz)[https://www.programiz.com/dsa/hash-table]
5. (Geeks for Geeks)[https://www.geeksforgeeks.org/implementation-of-hash-table-in-c-using-separate-chaining/]