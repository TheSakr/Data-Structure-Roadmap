#include <iostream>
using namespace std ;
template <typename T>
struct Node 
{
T data ;
Node * next = nullptr;
Node (T d):data(d){}
};
template <typename T>
class dynamic_Stack
{
    private:
    Node<T> * Top= nullptr ;
    public :
    ~dynamic_Stack() {
    while (Top != nullptr)
        pop();
    }

    void push(T data)
    {
    Node<T>* new_node = new Node<T>(data);
    new_node->next = Top;
    Top = new_node;
    cout << "value : " << data << " pushed\n";
    }

    void pop () 
    {
        if (Top == nullptr)
            cout << "Stack is empty";
        else{
            Node<T>*temp = Top ;
            Top = Top ->next ;
            delete temp ;
        }

    }
    void display ()
    {
        if ( Top != nullptr)
        {
        Node<T> * temp = Top ;
        size_t count= 1 ;
        while (temp != nullptr )
            {
            cout << "( " << count++ << ", " << temp->data << " )\n";
            temp = temp -> next ;
            }
        }
        else
        {
            cout << "it is empty" ;
        }
    }

    void peek () 
    {
        cout << "peek is " <<Top->data << '\n' ;


    }


};
int main ()
{
    dynamic_Stack<int> ss;

    ss.push(6);
    ss.push(5);
    ss.push(2);
    ss.push(7);
    ss.push(5);

    ss.display();
    ss.pop();
    cout << "\nafter pop\n";
    ss.display();
    ss.peek() ;


    return 0 ;
}