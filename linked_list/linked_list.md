### Singly Linked List Problems

#### Constructor `Node(T data)`

This constructor initializes a node with the provided data. It takes a single argument `data` of type `T` and assigns it to the `data` member variable of the node. The `next` pointer is set to `nullptr`, indicating that this node is initially not linked to any other node.

---

### LinkedList Class

#### Constructor `LinkedList()`

This constructor initializes a linked list with an empty head pointer. It sets the `head` pointer to `nullptr`, indicating that the list is initially empty.

#### Method `Add(T data)`

This method adds a new node to the beginning of the linked list. It takes a single argument `data` of type `T` and creates a new node with this data. The new node's `next` pointer is set to the current head of the list, and then the head pointer is updated to point to the new node, effectively adding the node to the beginning of the list.

#### Method `Print()`

This method prints the elements of the linked list. It starts from the head node and traverses the list, printing the data of each node followed by an arrow (`->`). It continues until it reaches the end of the list, indicated by a `NULL` pointer.

#### Method `bool Find(Node<T> *node, T data)`

This is a helper method for searching for a specific data element in the linked list. It recursively searches for the data starting from the given node. If the data is found in any node, it returns `true`; otherwise, it returns `false`.

#### Method `void Reverse()`

This method reverses the order of elements in the linked list. It iterates through the list, changing the `next` pointers of each node to point to the previous node, effectively reversing the order. Finally, it updates the head pointer to point to the last node in the reversed list, making it the new head of the list.

---

### Main Function

#### `int main()`

This is the entry point of the program. It creates an instance of the `LinkedList` class with integer type. Then, it adds some elements to the list, prints the list, finds an element in the list, reverses the list, prints it again, and finally prints the result of the find operation. It returns 0 to indicate successful completion of the program.
