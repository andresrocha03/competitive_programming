# Roadmap

This is dedicated for solving the problems of the neetcode roadmap available in this [link](https://neetcode.io/problems/duplicate-integer?list=neetcode150)

# Problems

### Hashing
Notes:

CPP:

    - map and unordered_map are containers that store data in the form of key-value pairs. Maps are implemented using red-black trees and unordered_maps are implemented using hash_tables.
    - set store ordered data, implemented with self balancing BST. unordered_set implemented using hash_table.

Python:

    - use defauldict to automatically create a default value when a key is accessed for the first time.
    - python's dictionary is a hash table.

- [Contains duplicate](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/duplicate.cpp)
- [Anagram](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/anagram.cpp)
- [TwoSum](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/twosum.cpp)
- [Group Anagram](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/group_anagram.cpp)
- [TopK](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/topkfrequent.cpp)
- [Encode](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/encode.cpp)
- [Product](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/product.cpp)
- [Sudoku](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/sudoku.cpp)
- [Longest Sequence](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/longseq.cpp)

### Stack

CPP:

    - stack container is a proper data structure for these problems
    - define a bool function sortCondition to combine with sort() and give your own sense to sorting

Python: 

    - it is possible to use a list or import a deque from collection's module.

- [Valid Parentheses](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/stack/parentheses.cpp)
- [MinStack](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/stack/minstack.cpp)
- [Reverse Polish](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/stack/polish.cpp)
- [Daily Temperatures](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/stack/temperature.cpp)
- [Car fleet](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/stack/carfleet)
-[Rect](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/stack/rectangle.cpp)

### Two pointers
Notes:

    - Use isalnum() to check whether a char is alphanumeric or not;

- [Palindrome](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/two_pointers/palindrome) 

- [TwoSum](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/two_pointers/twosum.cpp)

- [3sum](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/two_pointers/3sum.cpp)

- [Container with most water](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/two_pointers/container.cpp)

- [Trapping Rain Water](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/two_pointers/trapping_water.cpp)

### Binary Search

Notes:

    - There is two ways of coding binary search: use an interval and work with two pointers, keeping the right answer inside that interval; or use a binary jump size to iterate the array, jumping when it is convenient until you reach the correct answer.

    - We can use binary search in functions to find the minimum solution for a problem.

    - Sometimes we use l < r, when we are sure that l==r returns the correct candidate. Others, we use l<=r, when we want to evaluate all possible candidates until none is left.

    - Consider the stack of recursion when computing the complexity of space.

- [Binary Search](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/binary_search/bin_search.cpp)

- [Search a 2D Matrix](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/binary_search/2dmatrix.cpp)

- [Koko Eating Bananas](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/binary_search/kokobananas.cpp)

- [Minimum in Rotated Array](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/binary_search/rot_min_array.cpp)

- [Search in Rotated Array](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/binary_search/bin_search.cpp)

- [Time based key-value store](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/binary_search/time_store.cpp)

- [Find Median of Sorted Arrays](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/binary_search/find_median.cpp)

### Sliding Window
Notes:
    - Usually we can assume O(1) for unordered containers operations, but in the worst case there can be collisions. Then, we would have to traverse a bucket to do operations and complexity would be O(N) - this is very specific and unusual for competitive programming problems not focused in adversarial hashing. 

- [Best time to Buy and Sell Stock](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/slinding_window/stock.cpp)

- [Longest Substring Without Repeating Characters](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/slinding_window/subtring.cpp)

- [Longest Repeating Character Replacement](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/slinding_window/replace.cpp)

- [Permutation in String](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/slinding_window/permutation.cpp)

- [Minimum Window Substring](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/slinding_window/min_substring.cpp )

- [Sliding Window Maximum](https://github.com/andresrocha03/competitive_programming/blob/main/roadmap_neetcode/sliding_window/slidingmax.cpp)

### Linked List

Notes:
    - When we have a pointer, we use * to dereference it. If the pointer points to some object, we can use -> to simultaneously dereference and have access to the attributes. Ex: (*node).val = node->val, where node is a pointer to the object node with attribute val.

- [Reverse Linked List]()

- [Merge Two Sorted Linked Lists]()

- [Linked List Cycle Detection]()