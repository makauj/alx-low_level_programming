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

`h(k, i) = (h'(k)) + c<sub>1</sub>i + c<sub>1</sub>i<sup>2</sup>) mod m`

where
    - c<sub>1</sub> and c<sub>2</sub> are positive auxiliary constants
    - i = {0, 1, ...,}

***iii. Double Hashing***
This solution works by calculating a new hash function for finding the next slot.

`h(k, i) = (h<sub>1</sub>(k) + ih<sub>2</sub>(k)) mod m`