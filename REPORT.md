# Group 7 – Assignment 2
## Hashing and Searching for a Music Application

### 1. Problem Statement

A music application stores the following song IDs:

**105, 210, 315, 420, 525, 630, 735, 840**

The task is to implement a hash table using the **Division Method**, insert the song IDs, identify collisions, perform searches using hashing and linear search, record the number of operations/comparisons, calculate the load factor, and compare the observed performance with the theoretical complexity.

---

## 2. Hash Table Design

### Hash function

The Division Method uses:

`h(key) = key % TABLE_SIZE`

For this implementation:

- Table size = **11**
- Collision resolution = **Linear Probing**

The table size is deliberately chosen so that the supplied IDs create collisions and the collision-resolution process can be observed.

### Why collisions occur

Different keys can produce the same hash index. When the calculated position is already occupied, linear probing checks the next position:

`(index + 1) % TABLE_SIZE`

until an empty position is found.

---

## 3. Algorithms

### 3.1 Insertion

1. Calculate the hash index using `key % TABLE_SIZE`.
2. Check whether the calculated position is empty.
3. If occupied, count a collision.
4. Move to the next table position.
5. Repeat until an empty position is found.
6. Insert the key.

### 3.2 Hashing Search

1. Calculate the hash index.
2. Compare the key with the item at that position.
3. If it matches, return the position.
4. Otherwise, move to the next position using linear probing.
5. Stop when the key is found, an empty slot is reached, or the probing cycle returns to the starting position.

### 3.3 Linear Search

1. Start from the first stored ID.
2. Compare the target with each ID.
3. Stop when the target is found.
4. If the end is reached, the item is absent.

---

## 4. Expected Hash Table

Using `h(key) = key % 11` and linear probing, the keys are inserted as follows:

| Song ID | Initial Hash | Final Position |
|---:|---:|---:|
| 105 | 6 | 6 |
| 210 | 1 | 1 |
| 315 | 7 | 7 |
| 420 | 2 | 2 |
| 525 | 8 | 8 |
| 630 | 3 | 3 |
| 735 | 9 | 9 |
| 840 | 4 | 4 |

Because these IDs have different remainders modulo 11, this particular set does **not** create collisions with table size 11.

Therefore, the program correctly reports zero insertion collisions for this configuration. This is useful for comparing the observed result with the theoretical behaviour of hashing.

---

## 5. Search Comparison

The program performs both searches for:

- 105
- 420
- 840
- 999 (an ID that is not stored)

### Example comparison

| Target | Hashing comparisons | Linear-search comparisons |
|---:|---:|---:|
| 105 | 1 | 1 |
| 420 | 1 | 4 |
| 840 | 1 | 8 |
| 999 | 1 | 8 |

For the supplied table, 999 hashes to index 9. Index 9 contains 735 and the next position (10) is empty, so the unsuccessful hashing search requires one key comparison before stopping.

---

## 6. Load Factor

The load factor is:

`α = n / m`

where:

- `n` = number of stored elements = 8
- `m` = hash table size = 11

Therefore:

`α = 8 / 11 = 0.727`

So the load factor is approximately:

**72.73%**

A higher load factor generally means more occupied positions and a greater possibility of probing during collisions. In this particular data set, the keys are distributed without insertion collisions.

---

## 7. Complexity Analysis

### Hashing

- Average successful search: **O(1)**
- Average unsuccessful search: **O(1)** when the load factor is controlled and the hash function distributes keys well
- Worst-case search: **O(n)**
- Average insertion: **O(1)**
- Worst-case insertion: **O(n)**

### Linear Search

- Best case: **O(1)**
- Average case: **O(n)**
- Worst case: **O(n)**

For `n` stored elements, linear search may need to examine many or all elements. Hashing normally requires only a small number of probes when the table is well designed and the load factor is reasonable.

---

## 8. Observed vs Theoretical Performance

The observed program results demonstrate that hashing can locate many stored IDs with very few comparisons because the hash function directly maps an ID to a table position.

For example, with the current table and data, the IDs 105, 420 and 840 have direct positions, so successful hashing searches require only one comparison.

Linear search depends on the position of the target in the original list. An ID near the end can require several comparisons.

The theoretical results are consistent with the implementation:

| Method | Average Case | Worst Case |
|---|---|---|
| Hashing | O(1) | O(n) |
| Linear Search | O(n) | O(n) |

---

## 9. Suitability for the Music Application

Hashing is suitable for a music application when the main operation is to quickly locate a song from its ID. A song ID is naturally suited to key-value lookup, and hashing can provide near-constant-time average lookup.

However, the actual performance depends on:

- Quality of the hash function
- Table size
- Load factor
- Collision-resolution method
- Distribution of song IDs

For a large music database, a well-designed hash table can provide efficient ID-based lookup.

---

## 10. Conclusion

The project implements a hash table using the Division Method and Linear Probing. It inserts the given song IDs, displays the table, reports collisions, performs hashing and linear searches, counts comparisons, and calculates the load factor.

The experimental results show why hashing is useful for direct ID-based searching. Hashing generally requires fewer comparisons than linear search when the table is appropriately sized and the keys are distributed well. Its average search complexity is O(1), while linear search has O(n) average complexity.

Thus, for fast song-ID lookup, hashing is an appropriate data structure, provided that the hash table is designed to control collisions and maintain a suitable load factor.
