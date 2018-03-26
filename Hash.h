#pragma once

#define TABLE_SIZE 50
#define LOW_PRIME 7
#define HIGH_PRIME 29

//Necessary #includes
#include "myLinkedList.h"	//FIXME
#include <string>
using namespace std;

template <class Type>
class HashTable
{
public:
	HashTable();
	~HashTable();

	void Clear();
	void Insert(string name, Type data);
	Type Retrieve(string name);		//Return a Type& ?
	Type operator [] (string name);	//Notation for Retrieve
	unsigned int hashFunction(string name);
	
	//Hash tables should be smaller than number of entries to ensure collision


private:
	linkedList<Type>[TABLE_SIZE] data;
};


template<class Type>
inline HashTable<Type>::HashTable()
{
}

template<class Type>
inline HashTable<Type>::~HashTable()
{
	this->Clear();
	delete[] data;
}

template<class Type>
inline void HashTable<Type>::Clear()
{
	for(unsigned int i = 0; i < TABLE_SIZE; ++i)
	{
		this->data[i].clear();		//Linked list needs a clear function FIXME
	}
}

template<class Type>
inline void HashTable<Type>::Insert(string name, Type data)
{
	unsigned int index = this->hashFunction(name);
	linkedList<Type>& hashSlot = this->data[index];
	hashSlot.add(name, data);	//Linked needs an add function with string and Type parameters. FIXME
					//Also probably a node<type> parameter
}

template<class Type>
inline Type HashTable<Type>::Retrieve(string name)
{
	unsignsed int index = this->hashFunction(name);
	linkedList<Type>& hashSlot = this->data[index];
	ListNode<Type> node = hashSlot.findByName(name);	//Node needs a copy constructor FIXME
	return node.data();
}

template<class Type>
inline Type HashTable<Type>::operator[](string name)
{
	Type temp = this->Retrieve(name)
	return temp;
}


template<class Type>
inline unsigned int HashTable<Type>::hashFunction(string name)
{
	unsigned int index;
	//FIXME
	//Convert string to ascii values and add them all together into sum.
	index *= HIGH_PRIME;
	index /= LOW_PRIME;	//THIS DOES INTEGER DIVISION RIGHT?! NOTE[]
	index %= TABLE_SIZE;
	
	return index;
}
