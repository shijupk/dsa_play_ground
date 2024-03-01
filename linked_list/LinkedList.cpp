#include <iostream>

using namespace std;
namespace SinglyLinkedList
{

    template <typename T>
    class Node
    {
    public:
        T data;
        Node *next;
        Node(T data)
        {
            this->data = data;
        }
    };

    template <typename T>
    class LinkedList
    {
    public:
        Node<T> *head;

    public:
        LinkedList()
        {
            head = nullptr;
        }

        void Add(T data)
        {
            Node<T> *new_node = new Node<T>(data);
            new_node->next = this->head;
            this->head = new_node;
        }

        void Print()
        {
            Node<T> *current = head;
            while (current != nullptr)
            {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "NULL" << endl;
        }

        bool Find(Node<T> *node, T data)
        {
            if (node == nullptr)
            {
                return false;
            }

            if (node->data == data)
            {
                return true;
            }
            else
            {
                return Find(node->next, data);
            }
        }
#pragma region Problem_1
        // Problem 1. Reverse a Linked List: Reverse the order of elements in a linked list.
        void Reverse()
        {
            // Initialize current, previous and next pointers
            Node<T> *current = head;
            Node<T> *prev = NULL, *next = NULL;

            while (current != NULL)
            {
                // Store next
                next = current->next;
                // Reverse current node's pointer
                current->next = prev;
                // Move pointers one position ahead.
                prev = current;
                current = next;
            }
            head = prev;
        }
#pragma endregion Problem_1

#pragma region Problem_2
        // Problem 2. Detect a Cycle in a Linked List: Determine whether a linked list contains a cycle.
        bool isCycle()
        {
            Node<T> *slow = head;
            Node<T> *fast = head;

            while (slow != nullptr && fast != nullptr && fast->next != nullptr)
            {

                slow = slow->next;
                fast = fast->next->next;

                if (slow == fast)
                {
                    return true;
                }
            }
            return false;
        }
#pragma endregion Problem_2

#pragma region Problem_2.1
        // problem 2.1 Find the first node of the loop in a Linked List
        // This intersting problem as it involved understandin floyd's detection loop algorithm

        Node<T> *FindFirstNodeInCycle()
        {
            Node<T> *currentNode = head;

            if (currentNode == nullptr || currentNode->next == nullptr)
            {
                return nullptr;
            }

            Node<T> *slow = head;
            Node<T> *fast = head;

            while (fast && fast->next)
            {

                slow = slow->next;
                if (fast->next)
                    return nullptr;
                fast = fast->next->next;
                if (slow == fast)
                {
                    break;
                }
            }

            if (slow != fast)
                return nullptr;

            // this is part is tricky need to understand the loop rotations.. see g for geeks
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return fast;
        }
#pragma endregion Problem_2 .1

#pragma region problem_3
        // Find the Middle of a Linked List: Find the middle node of a linked list.

        T FindMiddle()
        {
            Node<T> *slow = head;
            Node<T> *fast = head;

            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;

                fast = fast->next->next;
            }
            return slow->data;
        }

#pragma endregion problem_3
#pragma region problem_4
// Merge Two Sorted Linked Lists: Merge two sorted linked lists into a single sorted linked list.
#pragma endregion

#pragma region problem_5
        // Remove Nth Node From End of List: Remove the nth node from the end of a linked list.

        T RemoveNthNodeFormEndOfList(T k)
        {
            Node<T> *slow = head;
            Node<T> *fast = head;

            while (k > 0)
            {
                fast = fast->next;
                k--;
            }

            while (fast != nullptr)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow->data;
        }
#pragma endregion

#pragma region problem_6
// Remove Duplicates from Sorted List: Remove duplicates from a sorted linked list.

#pragma endregion

#pragma region problem_7
        // Intersection of Two Linked Lists: Find the node at which two linked lists intersect.

#pragma endregion

#pragma region problem_8
        // Palindrome Linked List: Determine whether a linked list is a palindrome.

#pragma endregion

#pragma region problem_9
        // Merge K Sorted Lists: Merge k sorted linked lists into one sorted linked list.

#pragma endregion

#pragma region problem_10
// Copy List with Random Pointer: Create a deep copy of a linked list with each node containing an additional random pointer.
#pragma endregion

#pragma region problem_11
// Swap Nodes in Pairs: Swap every two adjacent nodes in a linked list.
#pragma endregion

#pragma region problem_12
        // Rotate List: Rotate a linked list to the right by k places.

#pragma endregion

#pragma region problem_13
        // Flatten a Multilevel Doubly Linked List: Flatten a multilevel doubly linked list into a single-level doubly linked list.

#pragma endregion

#pragma region problem_14
        // Reverse Nodes in k-Group: Reverse every k consecutive nodes in a linked list.

#pragma endregion

#pragma region problem_15

// Add Two Numbers Represented by Linked Lists: Given two numbers represented by linked lists, add them and return the result as a linked list.
#pragma endregion

#pragma region problem_16
        // LRU Cache using Linked List: Implement an LRU (Least Recently Used) cache using a linked list.

#pragma endregion

#pragma region problem_17
        // Split Linked List in Parts: Split a linked list into k parts of approximately equal size.

#pragma endregion

#pragma region problem_18
        // Insert into a Sorted Circular Linked List: Insert a node into a sorted circular linked list.

#pragma endregion

#pragma region problem_19
        // Convert Binary Search Tree to Sorted Doubly Linked List: Convert a binary search tree into a sorted doubly linked list.

#pragma endregion

#pragma region problem_20
// Reverse Linked List in Groups of Given Size: Reverse a linked list in groups of a given size.
#pragma endregion
    };

}

class Test
{
public:
    void static Test_Reverse_LinkedList()
    {

        cout << "Start:: 1. Reverse the order of elements in a linked list" << endl;
        SinglyLinkedList::LinkedList<int> list;

        list.Add(10);
        list.Add(20);
        list.Add(30);
        list.Add(40);
        list.Add(50);
        list.Add(60);
        list.Add(50);
        list.Add(70);
        list.Add(80);
        list.Print();

        list.Reverse();
        cout << "Result: ";
        list.Print();
        cout << "End." << endl;
    }

    void static Test_IsCycle()
    {
        cout << "Start:: 2. Detect a Cycle in a Linked List" << endl;

        SinglyLinkedList::LinkedList<int> list;

        list.Add(10);
        list.Add(20);
        list.Add(30);
        list.Add(40);
        list.Add(50);
        list.Print();

        // Create a loop for testing
        cout << "No loop: ";
        auto isCycle = list.isCycle();
        cout << isCycle << endl;

        list.head->next = list.head->next->next;
        cout << "With loop: ";
        isCycle = list.isCycle();
        cout << isCycle << endl;
        cout << "End." << endl;
    }

    void static Test_FirstNodeInCycle()
    {
        cout << "Start:: 2. Detect a Cycle in a Linked List" << endl;

        SinglyLinkedList::LinkedList<int> list;

        list.Add(10);
        list.Add(20);
        list.Add(30);
        list.Add(40);
        list.Add(50);
        list.Print();

        // Create a loop for testing
        list.head->next->next = list.head->next->next->next;
        cout << "With loop: ";
        auto node = list.FindFirstNodeInCycle();
        cout << "FirstNodeInCycle: " << node->data << endl;
        cout << "End." << endl;
    }

    void static Test_FindMiddle()
    {
        cout << "Start:: 3. Find the Middle of a Linked List" << endl;

        SinglyLinkedList::LinkedList<int> list;

        list.Add(10);
        list.Add(20);
        list.Add(30);
        list.Add(40);
        list.Add(90);
        list.Add(60);
        list.Add(50);
        list.Add(70);
        list.Add(80);
        list.Add(100);
        list.Add(110);
        list.Add(120);
        list.Print();

        auto result = list.FindMiddle();
        cout << "Middle Element: " << result << endl;
        cout << "End." << endl;
    }

    void static Test_RemoveNthNodeFormEndOfList()
    {
        cout << "Start:: 3. Remove Nth Node From End Of List" << endl;

        SinglyLinkedList::LinkedList<int> list;

        list.Add(10);
        list.Add(20);
        list.Add(30);
        list.Add(40);
        list.Add(90);
        list.Add(60);
        list.Add(50);
        list.Add(70);
        list.Add(80);
        list.Add(100);
        list.Add(110);
        list.Add(120);
        list.Print();

        auto result = list.RemoveNthNodeFormEndOfList(6);
        cout << 6 << "th elem from end Element: " << result << endl;
        cout << "End." << endl;
    }
};

void main()
{

    cout << "Singly linkedtest top 20 problems" << endl;
    cout << endl;
    Test::Test_Reverse_LinkedList();
    cout << endl;
    Test::Test_IsCycle();
    cout << endl;

    // Fixme
    // Test::Test_FirstNodeInCycle();

    Test::Test_FindMiddle();

    Test::Test_RemoveNthNodeFormEndOfList();
    cout << endl;
    cout << "Done!" << endl;
}