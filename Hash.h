#pragma once

//Necessary #includes
#include <string>
using namespace std;

template <class Type>
class HashTable
{
public:
	HashTable();
	~HashTable();

	void Clear();
	void Insert(string name, Type data);	//Not detailed enough
	Type Retrieve(string formula);
	unsigned int hashFunction(string name);
	Type operator [] (string name);
	
	//Hash tables should be smaller than number of entries to ensure collision


private:
};


template<class Type>
inline HashTable<Type>::HashTable()
{
}

template<class Type>
inline HashTable<Type>::~HashTable()
{
}

template<class Type>
inline void HashTable<Type>::Clear()
{
}

template<class Type>
inline void HashTable<Type>::Insert(string name, Type data)
{
}

template<class Type>
inline Type HashTable<Type>::Retrieve(string formula)
{
	return Type();
}

template<class Type>
inline unsigned int HashTable<Type>::hashFunction(string name)
{
	return 0;
}

template<class Type>
inline Type HashTable<Type>::operator[](string name)
{
	return Type();
}
