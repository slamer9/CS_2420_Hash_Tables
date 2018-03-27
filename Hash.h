#pragma once

#define TABLE_SIZE 10
#define LOW_PRIME 5
#define MED_PRIME 11
#define HIGH_PRIME 15485863

//Necessary #includes
#include "LinkedList.h"	//my linked list


template <class Type>
class HashTable
{
public:
	HashTable();
	~HashTable();

	void Clear();

	void Insert(string name, Type data);

	Type Retrieve(string name);
	Type& RetrieveByReference(string name);
	Type operator [] (string name);	//Alternate notation for Retrieve

	unsigned int hashFunction(string name);

	void displaySize();	//Mainly for debugging purposes

private:
	LinkedList<Type> data[TABLE_SIZE];
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
	for (unsigned int i = 0; i < TABLE_SIZE; ++i)
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
	unsigned int index = this->hashFunction(name);
	LinkedList<Type>& hashSlot = this->data[index];
	return hashSlot.findByName(name);
}

template<class Type>
Type& HashTable<Type>::RetrieveByReference(string name)
{
	unsigned int index = this->hashFunction(name);
	LinkedList<Type>& hashSlot = this->data[index];
	return hashSlot.findByNameReference(name);
}

template<class Type>
Type HashTable<Type>::operator[](string name)
{
	return (this->Retrieve(name));
}


template<class Type>
unsigned int HashTable<Type>::hashFunction(string name)
{
	unsigned int index = 0;

	for (char c : name)
	{
		index += c;
	}

	index /= LOW_PRIME;
	index *= HIGH_PRIME;
	index /= MED_PRIME;
	index %= TABLE_SIZE;

	return index;
}

template<class Type>
void HashTable<Type>::displaySize()
{
	cout << endl << "Displaying hash table distribution." << endl;
	for (unsigned int i = 0; i < TABLE_SIZE; ++i)
	{
		cout << "Hashslot " << i << ", has " << data[i].getSize() << " nodes inside it." << endl;
	}
}
