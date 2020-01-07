/* Assignment: 3
Campus: Ashdod
Author:oz ben zaken, ID: 204015614 */

#pragma once

#ifndef CSet_H
#define CSet_H

#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

template<class T>
class CSet
{
	int size;
	T *arr;
public:
	CSet() :size(0), arr(NULL){} //c'tor
	CSet(const CSet<T>& arr){ *this = arr; } //coppy c'tor

	//get size function. return the size of the CSet
	int getSize()const{ return size; }


	/////////////////////////////////////  operators  //////////////////////////////////////////

	//template operator = that creatin a new similar CSet as the parameter
	const CSet<T>& operator=(const CSet<T>&);

	//template operator [] that returns the object in the i plase of arr with an update option
	T& operator[](int i)const{ return arr[i]; }

	//template operator += that get an object and add it to the CSet if its not in the CSet
	void operator+=(const T&);

	//template operator -= that get an object and remove it from the CSet if its in the CSet
	void operator-=(const T&);

	//template operator | that returns CSET of all the objects that are in the sending CSet and the parameter CSet
	const CSet<T>& operator|(const CSet<T>&)const;

	//template operator & that returns CSet of all the objects that are in both the sending CSet and the parameter CSet
	const CSet<T>& operator&(const CSet<T>&)const;

	//template operator - that returns CSet of all the object that in the sending CSet but not in the parameter CSet
	const CSet<T>& operator-(const CSet<T>&)const;

	//template operator == that returns true if the sending CSet and the parameter CSet are equel
	bool operator==(const CSet<T>&)const;

	//template operator > that returns true if the sending CSet contain the parameter CSet
	bool operator>(const CSet<T>&)const;

	//template operator ^ that returns CSet of all the objects that are in the sending CSet and the parameter CSet but not both
	const CSet<T>& operator^(const CSet<T>&)const;

	//template operator << that imitate cout function
	friend ostream &operator<<<>(ostream&, const CSet<T>&);

	//template function that does the operator - and writing that CSet to a file
	void DifWrite(const CSet<T>&)const;
	

	~CSet(){ if (arr) delete[] arr; } //d'tor
};
#endif


//template operator = that creatin a new similar CSet as the parameter
template<class T>
const CSet<T>& CSet<T>::operator=(const CSet<T>& arr)
{
	if (size)
		delete[] this->arr;
	size = arr.size;
	if (size)
	{
		this->arr = new T[size];
		if (!this->arr)
			throw "bad alloc";
		for (int i = 0; i < size; ++i)
			this->arr[i] = arr[i];
	}
	return *this;
}

//template operator += that get an object and add it to the CSet if its not in the CSet
template<class T>
void CSet<T>::operator+=(const T& obj)
{
	bool exist=false;
	for (int i = 0; i < size && !exist; ++i)
		if (arr[i] == obj)
			exist = true;
	if (!exist)
	{
		T *temp = new T[size + 1];
		if (!temp)
			throw "bad alloc";
		for (int i = 0; i < size; ++i)
			temp[i] = arr[i];
		temp[size] = obj;
		if (size)
			delete []arr;
		arr = temp;
		++size;
	}
}

//template operator -= that get an object and remove it from the CSet if its in the CSet
template<class T>
void CSet<T>::operator-=(const T& obj)
{
	bool exist = false;
	int index;
	for (int i = 0; i < size && !exist; ++i)
	{
		if (arr[i] == obj)
		{
			exist = true;
			index = i;
		}
	}
	if (exist)
	{
		T *temp = new T[size - 1];
		if (!temp)
			throw "bad alloc";
		for (int i = 0; i < index; ++i)
			temp[i] = arr[i];
		for (int i = index + 1; i < size; ++i)
			temp[i - 1] = arr[i];
		delete[] arr;
		++size;
		arr = temp;
	}
}

//template operator | that returns CSET of all the objects that are in the sending CSet and the parameter CSet
template<class T>
const CSet<T>& CSet<T>::operator|(const CSet<T>& secArr)const
{
	CSet<T> *temp = new CSet<T>;
	if (!temp)
		throw "bad alloc";
		(*temp) = *this;
	for (int i = 0; i < secArr.size; ++i)
			(*temp) += secArr[i];
	return *temp;
}

//template operator & that returns CSet of all the objects that are in both the sending CSet and the parameter CSet
template<class T>
const CSet<T>& CSet<T>::operator&(const CSet<T>& secArr)const
{
	CSet<T> *temp = new CSet<T>;
	if (!temp)
		throw "bad alloc";
	bool exist;
	for (int i = 0; i < secArr.size; ++i)
	{
		exist = false;
		for (int j = 0; j < size && !exist; ++j)
			if (secArr[i] == arr[j])
				exist = true;
		if (exist)
			(*temp) += secArr[i];
	}
	return *temp;
}

//template operator - that returns CSet of all the object that in the sending CSet but not in the parameter CSet
template<class T>
const CSet<T>& CSet<T>::operator-(const CSet<T>& secArr)const
{
	CSet<T> *temp=new CSet<T>;
	if (!temp)
		throw "bad alloc";
	(*temp) = *this;
	for (int i = 0; i < secArr.size; ++i)
		(*temp) -= secArr[i];
	return *temp;
}

//template operator == that returns true if the sending CSet and the parameter CSet are equel
template<class T>
bool CSet<T>::operator==(const CSet<T>& secArr)const
{
	if (size != secArr.size)
		return false;
	int i;
		for (i = 0; i < size && i< secArr.size; ++i)
			if (!(arr[i]==secArr[i]))
				return false;
	return true;
}

//template operator > that returns true if the sending CSet contain the parameter CSet
template<class T>
bool CSet<T>::operator>(const CSet<T>& secArr)const
{
	bool exist;
	for (int i = 0; i < secArr.size; ++i)
	{
		exist = false;
		for (int j = 0; j < size && !exist; ++j)
			if (secArr[i] == arr[j])
				exist = true;
		if (!exist)
			return false;
	}
	return true;
}

//template operator ^ that returns CSet of all the objects that are in the sending CSet and the parameter CSet but not both
template<class T>
const CSet<T>& CSet<T>::operator^(const CSet<T>& secArr)const
{
	CSet<T> *temp = new CSet<T>;
	if (!temp)
		throw "bad alloc";
	(*temp) = (*this | secArr) - (*this & secArr);
	return *temp;
}

//template function that does the operator - and writing that CSet to a file
template<class T>
void CSet<T>::DifWrite(const CSet<T>& arr)const
{
	ofstream outfile("DifWrite.txt", ios::app);
	if (!outfile.is_open())
		throw "cant open file";
	CSet<T> temp(*this - arr);
	if (temp.size)
		outfile << "(" << temp[0];
	for (int i = 1; i < temp.size; ++i)
		outfile << "," << temp[i];
	outfile << ")" << endl;
	outfile.close();
}

//template operator << that imitate cout function
template<class T>
ostream& operator << (ostream& out, const CSet<T>& arr)
{
	out << "(";
	if (arr.getSize())
		out << arr[0];
	for (int i = 1; i < arr.getSize(); ++i)
		out << "," << arr[i];
	out << ")" << endl;
	return out;
}
