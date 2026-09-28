# 🎵 Group 7 – Hashing Assignment

## Assignment 2 – Data Structures and Algorithms

This repository contains the complete implementation and documentation for **Group 7's Assignment 2**, based on the hashing and searching problem given in the assignment sheet.

The project demonstrates how a music application can efficiently store and retrieve song IDs using a **Hash Table**. It compares hashing with the traditional **Linear Search** technique and records the number of comparisons required by each method.

---

## 📌 Assignment Question

A music application stores the following song IDs:

```text
105, 210, 315, 420, 525, 630, 735, 840
```

The assignment requires the following:

1. Implement a hash table using the **Division Method**.
2. Insert all the given song IDs into the hash table.
3. Display the hash table after insertion.
4. Identify and report collisions.
5. Search for song IDs using hashing.
6. Search for the same IDs using linear search.
7. Record the number of operations/comparisons required for each search.
8. Calculate the load factor of the hash table.
9. Compare the observed performance with the theoretical complexity of hashing and linear search.
10. Determine whether hashing is suitable for the music application.

This repository provides all the source code, report material, and sample output required for the assignment.

---

# 🎯 Project Objective

The main objective of this project is to understand the practical use of **hashing as a searching technique**.

In a music application, every song can be assigned a unique ID. When a user searches for a song using its ID, the application should be able to locate the corresponding record quickly.

A hash table provides a way to convert a key, such as a song ID, into an index in an array. This can significantly reduce the number of comparisons required during searching.

This project therefore compares:

- **Hashing**
- **Linear Search**

and demonstrates their practical behaviour using the given song IDs.

---

# 🧠 Concepts Used

The project covers the following Data Structures and Algorithms concepts:

- Hash Tables
- Hash Functions
- Division Method
- Collision
- Collision Resolution
- Linear Probing
- Hashing Search
- Linear Search
- Load Factor
- Time Complexity
- Average-case Complexity
- Worst-case Complexity
- Search Comparisons

---

# 🔢 Hashing Using the Division Method

The **Division Method** is one of the simplest methods for generating a hash value.

The formula used is:

```text
h(key) = key % TABLE_SIZE
```

In this project:

```text
TABLE_SIZE = 11
```

Therefore, each song ID is divided by 11 and the remainder determines its initial position in the hash table.

For example:

```text
105 % 11 = 6
```

Therefore, song ID `105` initially maps to index `6`.

Another example:

```text
420 % 11 = 2
```

Therefore, song ID `420` maps to index `2`.

---

# 🔄 Collision Resolution

A **collision** occurs when two different keys produce the same hash-table index.

For example, if two IDs produce:

```text
h(key1) = 5
h(key2) = 5
```

both keys cannot occupy index 5 at the same time.

This project uses **Linear Probing** to resolve collisions.

When a collision occurs, the program checks the next available position:

```text
(index + 1) % TABLE_SIZE
```

The program continues checking subsequent positions until an empty position is found.

For example:

```text
Initial position → 5
Position occupied → 6
Position occupied → 7
Position empty → insert at 7
```

The program also counts the number of collisions and additional probes that occur during insertion.

---

# 🗃️ Hash Table Configuration

The program uses:

| Parameter | Value |
|---|---:|
| Number of song IDs | 8 |
| Hash table size | 11 |
| Hash method | Division Method |
| Collision resolution | Linear Probing |
| Empty slot marker | -1 |

The hash table contains 11 positions numbered:

```text
0  1  2  3  4  5  6  7  8  9  10
```

---

# 🎵 Song IDs

The input data used by the program is:

```text
105
210
315
420
525
630
735
840
```

The program stores these IDs in both:

1. The original array, for linear search.
2. The hash table, for hashing-based search.

This allows a direct comparison between the two searching techniques.

---

# 📊 Expected Hash Mapping

Using:

```text
h(key) = key % 11
```

the supplied IDs map as follows:

| Song ID | Hash Calculation | Initial Index |
|---:|---:|---:|
| 105 | 105 % 11 | 6 |
| 210 | 210 % 11 | 1 |
| 315 | 315 % 11 | 7 |
| 420 | 420 % 11 | 2 |
| 525 | 525 % 11 | 8 |
| 630 | 630 % 11 | 3 |
| 735 | 735 % 11 | 9 |
| 840 | 840 % 11 | 4 |

For this particular data set, the initial hash positions are different. Therefore, no collision occurs during insertion when the table size is 11.

This is an important observation from the experiment: **whether collisions occur depends on both the hash function and the selected table size.**

---

# 🔍 Hashing Search

The hashing search follows the same hash function used during insertion.

For a target ID:

1. Calculate its hash value.
2. Go directly to the calculated index.
3. Compare the stored value with the target.
4. If the value matches, the search is successful.
5. If a collision had occurred during insertion, linear probing would continue through the appropriate sequence.
6. If an empty slot is encountered, the target is not present.

Example:

Searching for:

```text
420
```

The hash calculation is:

```text
420 % 11 = 2
```

The program checks index 2 and finds:

```text
420
```

Therefore, the search succeeds with one key comparison.

---

# 🔎 Linear Search

Linear Search checks the stored IDs one by one from the beginning.

For the array:

```text
105, 210, 315, 420, 525, 630, 735, 840
```

searching for `420` requires:

```text
105 → comparison 1
210 → comparison 2
315 → comparison 3
420 → comparison 4
```

Therefore, four comparisons are required.

If the target is the last element, the search may need to examine all elements.

---

# ⚖️ Hashing vs Linear Search

The project records the number of comparisons for both methods.

For example:

| Search ID | Hashing | Linear Search |
|---:|---:|---:|
| 105 | 1 comparison | 1 comparison |
| 420 | 1 comparison | 4 comparisons |
| 840 | 1 comparison | 8 comparisons |

This demonstrates how hashing can reduce the number of comparisons when the hash table is appropriately designed.

---

# 📐 Load Factor

The **load factor** indicates how full a hash table is.

The formula is:

```text
α = n / m
```

where:

- `n` = number of stored elements
- `m` = total number of hash-table positions

For this project:

```text
n = 8
m = 11
```

Therefore:

```text
α = 8 / 11
α = 0.727
```

or approximately:

```text
72.73%
```

A high load factor can increase the probability of collisions and probing in many hash-table implementations. Therefore, table size and hash-function design are important for maintaining efficient performance.

---

# ⏱️ Time Complexity

## Hashing

Under normal conditions with a good hash function:

```text
Average search: O(1)
Average insertion: O(1)
```

However, in the worst case, many keys can collide and the operation may become:

```text
Worst-case search: O(n)
Worst-case insertion: O(n)
```

## Linear Search

Linear search has:

```text
Best case: O(1)
Average case: O(n)
Worst case: O(n)
```

The best case occurs when the required item is the first element.

The worst case occurs when the required item is the last element or is not present.

---

# 🧪 Experimental Analysis

The C program performs sample searches for:

```text
105
420
840
999
```

The first three IDs are present in the data set.

The ID:

```text
999
```

is intentionally absent so that unsuccessful search behaviour can also be observed.

For each search, the program reports:

- Whether the ID was found.
- Hash-table index if found.
- Array position if found.
- Number of hashing comparisons.
- Number of linear-search comparisons.

The program also reports:

- Total insertion collisions.
- Additional probes.
- Load factor.

---

# 📈 Observed Performance

For the supplied data and table size of 11, the IDs have distinct initial hash positions.

Therefore:

```text
Total insertion collisions = 0
```

Successful hashing searches for the supplied IDs can generally find their target directly at the calculated index.

Linear search, on the other hand, depends on the target's position in the original array.

For example:

```text
105 → 1 comparison
420 → 4 comparisons
840 → 8 comparisons
```

This gives a practical demonstration of the difference between direct hash-based lookup and sequential searching.

---

# 💻 Program Features

The C program includes the following functions:

### `hashFunction()`

Calculates the hash index using the Division Method.

```c
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}
```

### `initializeTable()`

Sets all hash-table positions to the empty marker.

### `insert()`

Inserts a song ID and handles collisions using Linear Probing.

### `displayTable()`

Displays the complete hash table.

### `hashingSearch()`

Searches for an ID using the hash table.

### `linearSearch()`

Searches for an ID sequentially through the original array.

### `compareSearch()`

Runs both search methods and displays their results for comparison.

---

# 🛠️ Technologies Used

The project is implemented using:

- **Programming Language:** C
- **Data Structure:** Hash Table
- **Collision Resolution:** Linear Probing
- **Compiler:** GCC / any standard C compiler
- **Version Control:** Git
- **Repository Hosting:** GitHub

No external libraries are required.

---

# 📁 Project Structure

```text
Group-7-Hashing-Assignment/
│
├── group7_hashing.c
├── README.md
├── REPORT.md
├── SAMPLE_OUTPUT.txt
└── .gitignore
```

### `group7_hashing.c`

Contains the complete C source code.

### `README.md`

Provides project documentation, concepts, algorithms, instructions, and analysis.

### `REPORT.md`

Contains the detailed assignment report suitable for academic submission.

### `SAMPLE_OUTPUT.txt`

Contains an example of the expected program output.

### `.gitignore`

Prevents unnecessary compiled files and IDE files from being uploaded to GitHub.

---

# ▶️ How to Compile

Make sure GCC is installed.

Open a terminal inside the project folder.

Run:

```bash
gcc group7_hashing.c -o group7_hashing
```

If compilation is successful, an executable file will be generated.

---

# ▶️ How to Run

## Linux / macOS

```bash
./group7_hashing
```

## Windows

```bash
group7_hashing.exe
```

The program first displays the hash table and analysis.

It then performs sample searches and provides an interactive search option.

To exit the interactive search, enter:

```text
-1
```

---

# 🖥️ Example Output

A simplified example of the output is:

```text
GROUP 7 - HASHING ASSIGNMENT

Hash method: Division Method + Linear Probing
Table size: 11

Index   Song ID
0       EMPTY
1       210
2       420
3       630
4       840
5       EMPTY
6       105
7       315
8       525
9       735
10      EMPTY

Total collisions during insertion: 0

Load factor = n/m = 8/11 = 0.727 (72.73%)
```

For a search such as `420`, the program reports:

```text
Hashing Search : FOUND at table index 2
Linear Search  : FOUND at array position 3
```

The exact number of comparisons is also displayed.

---

# 📚 Learning Outcomes

After completing this project, the following concepts can be understood more clearly:

1. How a hash function converts a key into an array index.
2. How the Division Method works.
3. Why collisions occur in hash tables.
4. How Linear Probing resolves collisions.
5. How hashing can provide fast average-case searching.
6. How Linear Search works.
7. How to measure search operations experimentally.
8. How to calculate a hash table's load factor.
9. How theoretical complexity relates to practical execution.
10. How data-structure selection depends on the application.

---

# 🎵 Application in a Music System

A real music application may have thousands or millions of songs.

Each song can have a unique ID such as:

```text
105
210
315
...
```

A hash table can be used to associate the ID with information such as:

```text
Song ID → Song Name
Song ID → Artist
Song ID → Album
Song ID → File Location
```

For example:

```text
105 → Song information
210 → Song information
315 → Song information
```

When the application receives a song ID, hashing can provide a fast way to locate the associated record.

In a production application, more advanced data structures and database indexing methods may also be used depending on the requirements.

---

# ✅ Advantages of Hashing

- Very fast average-case lookup.
- Efficient for key-based searching.
- Suitable for large collections when appropriately designed.
- Average search complexity can be O(1).
- Can support efficient insertion and deletion.
- Useful for applications where unique IDs are frequently searched.

---

# ⚠️ Limitations of Hashing

- Collisions can occur.
- Performance depends on the hash function.
- Poor table size selection can increase collisions.
- Worst-case operations can become O(n).
- Hash tables do not naturally maintain sorted order.
- Memory must be allocated for the hash table.

---

# 🔬 Why Linear Probing Was Used

Linear probing is simple to implement and easy to demonstrate in an academic assignment.

When a collision occurs:

```text
index → index + 1 → index + 2 → ...
```

until an empty slot is found.

It also makes it easy to count:

- Collisions
- Probes
- Comparisons

This makes Linear Probing useful for experimentally demonstrating the effect of collisions.

---

# 📝 Conclusion

This project demonstrates the implementation of a hash table for storing and searching song IDs.

The Division Method is used to calculate the initial hash position:

```text
h(key) = key % 11
```

Linear Probing is used as the collision-resolution technique.

The project compares hashing with Linear Search and records the number of comparisons required by both approaches.

For the supplied eight song IDs and a table size of 11, the initial hash positions are distinct, so no insertion collisions occur. The load factor is approximately **0.727**, or **72.73%**.

The experiment illustrates the main advantage of hashing: when the hash table is appropriately designed, key-based searches can be performed in approximately constant average time, **O(1)**. Linear Search requires **O(n)** average time because it may need to examine many elements.

Therefore, hashing is a useful data structure for applications that frequently perform searches using unique identifiers such as song IDs. Its performance should be monitored through appropriate table sizing, a suitable hash function, and effective collision handling.

---

# 👥 Group Information

**Group:** 7

**Assignment:** Assignment 2

**Topic:** Hashing and Searching

**Application Context:** Music Application / Song ID Management

---

# 📌 GitHub Repository

Suggested repository name:

```text
Group-7-Hashing-Assignment
```

The repository contains all source code, documentation, and sample output required to understand and execute the project.

---

## 📄 License

This project was created for academic/educational purposes as part of a Data Structures and Algorithms assignment.
