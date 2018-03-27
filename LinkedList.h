//Necessary includes
#include <string>


template <class Type>
class ListNode
{
public:
    ListNode(string name = "empty node", Type data = NULL, ListNode* next = nullptr, ListNode* previous = nullptr);
    ~ListNode();
    //Needs copy constructor

    Type data(){return this->node_data;}
private:
    ListNode<Type>* next;
    ListNode<Type>* previous;

    string name;
    Type node_data;
};

template<class Type>
inline ListNode<Type>::ListNode(string name, Type data, ListNode* next, ListNode* previous)
{
    this->name = name;
    this->node_data = data;
    this->next = next;
    this->previous = previous;
}

template<class Type>
inline ListNode<Type>::~ListNode()
{
    //delete this->node_data;   //FIXME should I do this?
}



template <class Type>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void add(string name = "empty node", Type data = NULL);
    void add(ListNode<Type>& node);
    //overloaded + operator here.   Link together then destruct differently? FIXME

    Type findByName(string name);
    Type& findByNameReference(string name);

    ListNode<Type> findNodeByName(string name);
    ListNode<Type>& findNodeByNameReference(string name);

    void clear();

    //Add sorts?
    
private:
    ListNode<Type>* head;
    unsigned int size;
};

template<class Type>
inline LinkedList<Type>::LinkedList()
{
    this->head = nullptr;
    this->size = 0;
}

template<class Type>
inline LinkedList<Type>::~LinkedList()
{
    this->clear();
}

template<class Type>
inline void LinkedList<Type>::add(string name, Type data)
{
    ListNode<Type> temp = new ListNode<Type>(name, data);
    this->add(temp);
}

template<class Type>
inline void LinkedList<Type>::add(ListNode<Type>& node)
{
    node->next = this->head;
    if(this->head != nullptr)
    {
        this->head->previous = node;
    }
    this->head = node;
    this->size++;
}

template<class Type>
inline Type LinkedList<Type>::findByName(string name)
{
    ListNode<Type> temp = this->head;
    while(temp != nullptr)
    {
        if(temp->name == name)
        {
            return temp->node_data;
        }
        temp = temp->next;
    }
    return NULL; //FIXME, throw exception, or state that name doesn't exist if I have more time to improve on this
}

template<class Type>
inline Type& LinkedList<Type>::findByNameReference(string name)
{
    ListNode<Type> temp = this->head;
    while(temp != nullptr)
    {
        if(temp->name == name)
        {
            return temp->node_data;
        }
        temp = temp->next;
    }
    return NULL; //FIXME, throw exception, or state that name doesn't exist if I have more time to improve on this
}

template<class Type>
inline ListNode<Type> LinkedList<Type>::findNodeByName(string name)
{
    ListNode<Type> temp = this->head;
    while(temp != nullptr)
    {
        if(temp->name == name)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL; //FIXME, throw exception, or state that name doesn't exist if I have more time to improve on this
}

template<class Type>
inline ListNode<Type>& LinkedList<Type>::findNodeByNameReference(string name)
{
    ListNode<Type> temp = this->head;
    while(temp != nullptr)
    {
        if(temp->name == name)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL; //FIXME, throw exception, or state that name doesn't exist if I have more time to improve on this
}

template<class Type>
inline void LinkedList<Type>::clear()
{
    if(this->head != nullptr)
    {
        ListNode<Type> temp = this->head;
        while(temp != nullptr)
        {
            temp = temp->next;
            delete this->head;
            this->size--;
            this->head = temp;
        }
    }
}