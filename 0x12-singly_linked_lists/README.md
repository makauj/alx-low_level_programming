# Singly linked lists

## 0. Print list Explanation
### `print_list` Function:
- Writes the opening bracket '[' using write.
- Calls 'print_number' to print the length.
- Writes the closing bracket '] ' and a space using write.
- Checks if 'h->str' is NULL and writes'[0] (nil)\n' if it is.
- Otherwise, writes the string 'h->str' and a newline \n.
- Increments the count and moves to the next node.
### `print_number` Function:
- Recursively prints each digit of the 'unsigned int n'.
- Converts each digit to its character representation by adding `0`.
- Writes each digit using 'write'.
### `add_node` Function:
- Function adds a new node to the head of the list.
- It duplicates the string, sets the string length, and updates the head of the list.
