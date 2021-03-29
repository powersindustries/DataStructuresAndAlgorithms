# Data Types and Algorithms Cheat Sheet

## _Overview_
### Data Types
- Binary Search Tree
- Doubly Linked List
- Dynamic Array (Similar to vector, List, etc)
- Graph
- Hash Tables
- Linked List
- Stack

### Algorithms
- Recursion 
  - Factorial example
  - Fibonacci Sequence example
- Searching
  - Binary Search
  - Breadth First Search
  - Depth First Search
- Sorting
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Merge Sort
  - Quick Sort

## _Information_

#### Dynamic Array
- Array that allows the user to dynamically add and remove items
- Keeps track of the array's memory capacity and element count

#### Linked List
- Linear data structure that starts at a head element with each proceeding element having a pointer to the next element in the list

#### Doubly Linked List
- Type of Linked List
- Each element in a doubly linked list has a pointer to the previous and next element in the list
- The head element has a null pointer to the previous element
- The tail element has a null pointer to the next element

#### Stack
- Last in first out (LIFO) data structure
- The most recently added element is the first element accessed in the collection

#### Hash Tables
- A key value pair structure
- Each value in the table has a unique hashed key that is generated using a hash function
- Hash functions are functions that can take in an input (like a string) and output an obfuscated key
- Values in the hash table are looked up by their unique hashed key

#### Graph
- Tree data structure where a single parent node has branches of child nodes under it
- Every node in the tree holds its data
- Each node connects to the other nodes by an edge

#### Binary Search Tree
- Node based tree structure
- Made up of a parent node with child nodes under it
- The left child node has a lower value than the right childnode under the parent

#### Recursion
- Recursion is when a method calls itself inside the same method
- Be careful when implementing recursion, because if done incorrectly, it can create a stack overflow

#### Searching
- Breadth First Search
  - Starting at the root node, iterate node by node level by level from left to right until the value is found or the end is reached
- Depth First Search
  - Starting at the root node, search all the way down a branch checking each node for the given value
  - When a branch has been traveled all the way down without finding the value, it goes back to the top and searches down the next branch

#### Sorting
- Bubble Sort
  - Elementary way of sorting the elements in an array, not suggested
  - Compares two values next to each other in an array. If the value on left is higher, it swaps the compared values
  - Continues this pattern until the array is sorted
  - Fun dancing illustration of Bubble Sort: https://www.youtube.com/watch?v=lyZQPjUT5B4
- Selection Sort
  - Scans the array and finds the smallest value. After finding the smallest value, the value is set to the first index in the array
  - After it is set, the first index increases by one
  - This process is repeated until the array is sorted in numeric order.
  - Fun dancing illustration of Selection Sort: https://www.youtube.com/watch?v=Ns4TPTC8whw
- Insertion Sort
  - The array is split into sorted and unsorted portions
  - The values from the unsorted part are placed at the correct position into the sorted part.
  - Fun dancing illustration of Insertion Sort: https://www.youtube.com/watch?v=ROalU379l3U
- Merge Sort
  - Divide and conquer algorithm for sorting
  - Its done by breaking up the list into single value ordered sublists
  - One by one, merge sublists and sort the new list of values
  - Repeat until one sorted list is left
  - Fun dancing illustration of Merge Sort: https://www.youtube.com/watch?v=XaqR3G_NVoo
- Quick Sort
  - Divide and conquer algorithm for sorting
  - Uses a pivot point to sort list
  - Values smaller than the pivot point are moved to the left, values greater move to the right
  - After everything is on the correct side, the pivot point moves and the process is repeated until the list is fully sorted
  - Fun dancing illustration of Quick Sort: https://www.youtube.com/watch?v=ywWBy6J5gz8