#pragma once

#define TABLE_SIZE 10
#define LOW_PRIME 5
#define MED_PRIME 11
#define HIGH_PRIME 15485863

//Necessary #includes
#include "LinkedList.h"	//my linked list

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
	LinkedList<Type>[TABLE_SIZE] data;
};

template<class Type>
HashTable<Type>::HashTable()
{
}

template<class Type>
HashTable<Type>::~HashTable()
{
	this->Clear();
	delete[] data;
}

template<class Type>
void HashTable<Type>::Clear()
{
	for(unsigned int i = 0; i < TABLE_SIZE; ++i)
	{
		this->data[i].clear();
	}
}

template<class Type>
void HashTable<Type>::Insert(string name, Type data)
{
	unsigned int index = this->hashFunction(name);
	LinkedList<Type>& hashSlot = this->data[index];
	hashSlot.add(name, data);
}

template<class Type>
Type HashTable<Type>::Retrieve(string name)
{
	unsignsed int index = this->hashFunction(name);
	LinkedList<Type>& hashSlot = this->data[index];
	return hashSlot.findByName();
}

template<class Type>
Type HashTable<Type>::operator[](string name)
{
	return (this->Retrieve(name));
}


template<class Type>
inline unsigned int HashTable<Type>::hashFunction(string name)
{
	unsigned int index = 0;

	for(char c: name)
	{
		index += c;
	}

	index /= LOW_PRIME;	
	index *= HIGH_PRIME;
	index /= MED_PRIME;
	index %= TABLE_SIZE;
	
	return index;
}
