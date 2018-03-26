//Necessary includes
#include <string>


template <class Type>
class ListNode
{
public:
    ListNode();
    ListNode(string name, Type data);
    ~ListNode();
    //Needs copy constructor
private:
    ListNode<Type>* front;
    ListNode<Type>* back;

    string name;
    Type data;
};

template <class Type>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void add(string name, Type data);
    void add(ListNode<Type>& node);
    
    //overloaded + operator here
private:
    ListNode<Type>* head;
};