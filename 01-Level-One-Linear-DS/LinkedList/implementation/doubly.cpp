#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        Node* cur = head;
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
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at tail
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
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
        while (cur->next && index < position - 1) {
            cur = cur->next;
            index++;
        }

        if (!cur->next) {
            insertAtTail(value);
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = cur->next;
        newNode->prev = cur;
        cur->next->prev = newNode;
        cur->next = newNode;
    }

    // Delete first occurrence of a value
    void deleteByValue(int value) {
        if (isEmpty()) return;

        Node* cur = head;
        while (cur && cur->data != value) {
            cur = cur->next;
        }
        if (!cur) return; // not found

        if (cur == head && cur == tail) {            // only node
            head = tail = nullptr;
        } else if (cur == head) {                    // delete head
            head = head->next;
            head->prev = nullptr;
        } else if (cur == tail) {                    // delete tail
            tail = tail->prev;
            tail->next = nullptr;
        } else {                                     // middle node
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        delete cur;
    }

    // Delete at position (0-based index)
    void deleteAtPosition(int position) {
        if (isEmpty() || position < 0) return;

        Node* cur = head;
        int index = 0;
        while (cur && index < position) {
            cur = cur->next;
            index++;
        }
        if (!cur) return;

        if (cur == head && cur == tail) {
            head = tail = nullptr;
        } else if (cur == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (cur == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        delete cur;
    }

    // Search value
    bool search(int value) const {
        Node* cur = head;
        while (cur) {
            if (cur->data == value) return true;
            cur = cur->next;
        }
        return false;
    }

    // Length
    int length() const {
        int count = 0;
        Node* cur = head;
        while (cur) {
            count++;
            cur = cur->next;
        }
        return count;
    }

    // Reverse the list
    void reverse() {
        if (isEmpty()) return;

        Node* cur = head;
        Node* temp = nullptr;

        while (cur) {
            // swap next and prev
            temp = cur->prev;
            cur->prev = cur->next;
            cur->next = temp;
            cur = cur->prev; // move using swapped prev
        }

        // After loop, temp is at old head's prev = new head
        if (temp) {
            head = temp->prev;
        }

        // swap head and tail pointers
        // (head already adjusted above; recompute tail)
        tail = head;
        while (tail && tail->next) tail = tail->next;
    }

    // Print forward
    void printForward() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " <-> ";
            cur = cur->next;
        }
        cout << "NULL\n";
    }

    // Print backward
    void printBackward() const {
        Node* cur = tail;
        while (cur) {
            cout << cur->data << " <-> ";
            cur = cur->prev;
        }
        cout << "NULL\n";
    }
};

// Example usage
int main() {
    DoublyLinkedList dll;

    dll.insertAtHead(3);
    dll.insertAtHead(2);
    dll.insertAtHead(1);       // 1 <-> 2 <-> 3
    dll.insertAtTail(4);       // 1 <-> 2 <-> 3 <-> 4
    dll.insertAtPosition(99, 2); // 1 <-> 2 <-> 99 <-> 3 <-> 4

    cout << "Forward: ";
    dll.printForward();
    cout << "Backward: ";
    dll.printBackward();

    dll.deleteByValue(99);
    dll.deleteAtPosition(0);

    cout << "After deletions (forward): ";
    dll.printForward();

    cout << "Length: " << dll.length() << endl;
    cout << "Search 3: " << (dll.search(3) ? "found" : "not found") << endl;

    dll.reverse();
    cout << "After reverse (forward): ";
    dll.printForward();

    return 0;
}
