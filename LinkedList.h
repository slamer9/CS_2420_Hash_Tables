//Necessary includes
#include <string>


template <class Type>
class ListNode
{
public:
    ListNode();
    ~ListNode();
    //Needs copy constructor
private:
    ListNode<Type>* front;
    ListNode<Type>* back;

    string 
};

template <class Type>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void add();
private:
    ListNode<Type>* head;
};