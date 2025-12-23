#include <iostream>
using namespace std ;
template <typename T>
class Dynamic_arr 
{
    private:
    size_t capacity ;
    int top ;
    T * arr ;
    void resize (size_t new_cap)
    {
        T * new_arr = new T[new_cap] ; 
        for (int i = 0 ; i < capacity ; i++)
        {
            new_arr[i] = arr[i] ;
        }
        capacity = new_cap ;

        delete[] arr ;
        arr = new_arr ;

    }

    public :
    Dynamic_arr (size_t cap):top(-1) {
        capacity = cap ;
        arr = new T[capacity] ;
    }
    ~Dynamic_arr(){
        delete[] arr ;
    }
    bool isEmpty ()
    {
     return top == -1 ;   
    }
    bool isFull ()
    {

        return top == capacity - 1 ;
    }
    void push (T val)
    {
        if (top == capacity-1 )
            resize(2*capacity);
        arr[++top] = val ;
        cout << val << " pushed successfully "<<'\n' ;
    }
    void pop ()
    {
        if (isEmpty())
        {
            cout << "Array is empty \n" ;
            return ;
        }
        else {
            --top ;
        }
    }
    void peek ()
    {

        cout << arr[top] ;
    }
    void dispay () 
    {
        for ( int i = top ; i >=0 ; i--)
        {
            cout << arr[i] << '\n' ;
        }
    }

};
int main ()
{
    Dynamic_arr<int> * array = new Dynamic_arr<int>(7) ;
    array ->push(8) ;
    array ->push(5) ;
    array ->push(4) ;
    array -> pop() ;
    array ->dispay() ;

}