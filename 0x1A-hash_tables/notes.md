# Notes on Hash Tables

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
