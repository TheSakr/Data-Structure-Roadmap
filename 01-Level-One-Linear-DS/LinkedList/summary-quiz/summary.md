#### Linked list 
key points
- it allows efficient ****insertion**** and ****deletion**** operations compared to arrays.
- it is also used to implement other data structures like stack, queue and deque like arrays.
- A linked list is a type of linear data structure individual items are not necessarily at contiguous locations. The individual items are called nodes and connected with each other using links.

- A node contains two things first is data and second is a link that connects it with another node.
- The first node is called the head node and we can traverse the whole list using this head and next links.
![[Pasted image 20251223060934.png]]

![[Pasted image 20251223061040.png]]

[LInkedlists vs arrays in memory](https://www.w3schools.com/dsa/dsa_theory_linkedlists_memory.php)

## Types of Linked Lists

Types of linked lists mainly differ in how their nodes connect to each other, which affects traversal direction, memory usage, and the ease of insertion and deletion. Linked lists are used when frequent insert/delete operations are needed and array-style indexing is less important.[](https://www.geeksforgeeks.org/dsa/types-of-linked-list/)

​

## Singly linked list

- Each node stores **data** and one pointer/reference to the next node only.[](https://www.programiz.com/dsa/linked-list-types)
- Traversal is one-way (from head toward the tail), and memory cost is lower than other variants because there is only one pointer per node.[](https://www.w3schools.com/dsa/dsa_data_linkedlists_types.php)
![[Pasted image 20251223061700.png]]
## Doubly linked list
- Each node stores data and two pointers: one to the next node and one to the previous node.[](https://youcademy.org/different-variants-of-linked-lists/)
- Supports traversal in both directions and makes deletion/insertion in the middle easier, but uses more memory per node than a singly linked list.[](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm)
![[Pasted image 20251223061711.png]]
## Circular linked list

- The last node does not point to null; instead, it points back to the first node, forming a circle.[](https://www.geeksforgeeks.org/dsa/types-of-linked-list/)
- Can be singly or doubly linked, allows continuous traversal starting from any node, and is useful for applications like round-robin scheduling or cyclic buffers.[](https://www.programiz.com/dsa/linked-list-types)
![[Pasted image 20251223061723.png]]
## Circular doubly linked list

- Combines both ideas: every node has next and previous pointers, and the last node’s next points to the first while the first node’s previous points to the last.[](https://www.simplilearn.com/tutorials/data-structure-tutorial/types-of-linked-list)
- Enables efficient forward and backward traversal in a loop and is used in structures like Fibonacci heaps and some navigation systems (e.g., image viewers, playlists).[](https://www.simplilearn.com/tutorials/data-structure-tutorial/types-of-linked-list)
![[Pasted image 20251223061740.png]]



Note :
when i say insert at position 1 it is == index 1 ;
 position is 0-based index



| List type              | Node fields (main attributes) | End behavior                            | Traversal direction             |
| ---------------------- | ----------------------------- | --------------------------------------- | ------------------------------- |
| Singly linked list     | `data`, `next`                | Last node’s `next = NULL`               | One-way: head → tail only       |
| Doubly linked list     | `data`, `prev`, `next`        | First `prev = NULL`, last `next = NULL` | Two-way: head ↔ tail            |
| Circular singly linked | `data`, `next`                | Last node’s `next = head`               | One-way loop: can cycle forever |
| Circular doubly linked | `data`, `prev`, `next`        | Last `next = head`, first `prev = tail` | Two-way loop: full circle       |

main way for the traversing 
is to traverse until you reach the index of pre desired position .
The linking is easy just imagine / design a list you are working on upon these cases .
-  starting where no element in the linkedList .
- progressing and you  are in middle 
- you reached the end .
you can separate the cases into 3 functions and call them when needed / you can combine them together which is more clearly .
You may ask how would i need a case in other case ?
let me give you an example , 
	you want to insert into a linked list , you want to make a function for ( inserting at position )
		what if the position given is the first index ?
			in this case you will use ( insertAtBeginning ( );) .
		or when inserting may you are searching to insert at index where ( node -> next == nulllptr ) so if you were using node-> next for controlling you can't use it here because there is no Node to control !!! and so you will call insert at the end function .
			