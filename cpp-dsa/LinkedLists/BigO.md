# Big O: Linked List vs. Vector

Time complexity of common operations on a singly linked list that keeps both `head` and `tail` pointers (like the `LinkedList` class in this project), compared with `std::vector`.

| Operation       | Linked List | Vector  |
|-----------------|:-----------:|:-------:|
| Append          | O(1)        | O(1)\*  |
| Remove last     | O(n)        | O(1)    |
| Prepend         | O(1)        | O(n)    |
| Remove first    | O(1)        | O(n)    |
| Insert at index | O(n)        | O(n)    |
| Remove at index | O(n)        | O(n)    |
| Lookup by index | O(n)        | O(1)    |
| Lookup by value | O(n)        | O(n)    |

\* Amortized: every so often the vector runs out of capacity and has to copy everything into a bigger block, but averaged over many appends each one costs O(1).