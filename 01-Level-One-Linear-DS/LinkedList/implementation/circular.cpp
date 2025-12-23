#include <iostream>
using namespace std;

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;  // points to first node
    Node* tail;  // points to last node (tail->next == head)

public:
    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    ~CircularLinkedList() {
        if (!head) return;
        Node* cur = head;
        // break the circle to avoid infinite loop
        tail->next = nullptr;
        while (cur) {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }
        head = tail = nullptr;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    // Insert at head
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
            newNode->next = head;     // circular link
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;        // maintain circle
        }
    }

    // Insert at tail
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;        // maintain circle
        }
    }

    // Insert at position (0-based index)
    void insertAtPosition(int value, int position) {
        if (position <= 0 || isEmpty()) {
            insertAtHead(value);
            return;
        }

        Node* cur = head;
        int index = 0;

        // move to node before desired position, but stop if we complete a full circle
        while (cur->next != head && index < position - 1) {
            cur = cur->next;
            index++;
        }

        // if we are at the end, insert at tail
        if (cur->next == head) {
            insertAtTail(value);
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = cur->next;
        cur->next = newNode;
    }

    // Delete first occurrence of a value
    void deleteByValue(int value) {
        if (isEmpty()) return;

        Node* cur = head;
        Node* prev = tail; // previous of head is tail in circular list

        // handle deletion with circular traversal
        do {
            if (cur->data == value) {
                // only one node
                if (cur == head && cur == tail) {
                    delete cur;
                    head = tail = nullptr;
                }
                // deleting head
                else if (cur == head) {
                    head = head->next;
                    tail->next = head;
                    delete cur;
                }
                // deleting tail
                else if (cur == tail) {
                    tail = prev;
                    tail->next = head;
                    delete cur;
                }
                // deleting middle node
                else {
                    prev->next = cur->next;
                    delete cur;
                }
                return;
            }
            prev = cur;
            cur = cur->next;
        } while (cur != head);
    }

    // Delete at position (0-based index)
    void deleteAtPosition(int position) {
        if (isEmpty() || position < 0) return;

        Node* cur = head;
        Node* prev = tail;

        // position 0 -> head
        if (position == 0) {
            // only one node
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            } else {
                head = head->next;
                tail->next = head;
                delete cur;
            }
            return;
        }

        int index = 0;
        // move to desired position
        while (cur->next != head && index < position) {
            prev = cur;
            cur = cur->next;
            index++;
        }

        if (index != position) return; // position out of range

        // deleting tail
        if (cur == tail) {
            tail = prev;
            tail->next = head;
            delete cur;
        } else {
            prev->next = cur->next;
            delete cur;
        }
    }

    // Search value
    bool search(int value) const {
        if (isEmpty()) return false;

        Node* cur = head;
        do {
            if (cur->data == value) return true;
            cur = cur->next;
        } while (cur != head);

        return false;
    }

    // Length (number of nodes)
    int length() const {
        if (isEmpty()) return 0;

        int count = 0;
        Node* cur = head;
        do {
            count++;
            cur = cur->next;
        } while (cur != head);
        return count;
    }

    // Print list starting from head (one full circle)
    void print() const {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        Node* cur = head;
        do {
            cout << cur->data << " -> ";
            cur = cur->next;
        } while (cur != head);
        cout << "(head)\n";
    }
};

// Example usage
int main() {
    CircularLinkedList cll;

    cll.insertAtHead(3);
    cll.insertAtHead(2);
    cll.insertAtHead(1);        // 1 -> 2 -> 3 -> (head)
    cll.insertAtTail(4);        // 1 -> 2 -> 3 -> 4 -> (head)
    cll.insertAtPosition(99, 2);// 1 -> 2 -> 99 -> 3 -> 4 -> (head)

    cll.print();

    cll.deleteByValue(99);
    cll.deleteAtPosition(0);    // delete head

    cll.print();

    cout << "Length: " << cll.length() << endl;
    cout << "Search 3: " << (cll.search(3) ? "found" : "not found") << endl;

    return 0;
}
