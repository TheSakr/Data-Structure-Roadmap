#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    public :
    T data ;
    Node * next ;
    
    Node (T d  ):data(d),next(nullptr){};
};
template <typename T>
class SingleLinkedList 
{
    private:
    Node<T> * head ;


    public :

    SingleLinkedList ():head(nullptr){ }
    
    bool isEmpty () const
    {
        return head == nullptr ;

    }

    void insertAtBeginning (T data)
    {   
        Node<T>* newNode = new Node(data);
        newNode->next = head;
        head = newNode;

    }

    void insertAtPosition (T data ,  int position)
    {
        if (position <= 0 || isEmpty()){
            insertAtBeginning(data) ;
            return ;
        }
        int index = 0 ;
        Node<T> * cur = head ;
        while (cur->next && index < position-1) // once index reaches pos -1 -> i arrived at prev Node 
        {
            cur = cur->next;  
            index++ ;
        }
        Node<T>*newNode = new Node<T>(data) ;
        newNode->next = cur ->next ;
        cur->next = newNode ;
    }
    void insertAtEnd (T data)
    {
        Node<T> * newNode = new Node<T>(data);
        if (isEmpty()) {
            head = newNode ; 
            return ;
        }
        Node<T>*cur = head ;
        while (cur->next)
            cur = cur->next ;
        cur->next = newNode ;

    }
        void deleteByValue(int value) {
        if (isEmpty()) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* cur = head;
        while (cur->next && cur->next->data != value) {
            cur = cur->next;
        }
        if (cur->next) {
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
    }




};





int main ()
{




    return 0 ;
}