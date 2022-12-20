#include "CMySmartPointer.h"

template<typename T>
CMySmartPointer<T>::CMySmartPointer(T* pcPointer)
{
	pc_pointer = pcPointer;
	pc_counter = new CRefCounter();
	pc_counter->iAdd();
}//CMySmartPointer(T*pcPointer)

template<typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer<T>& pcOther)
{
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
}//CMySmartPointer(const CMySmartPointer &pcOther)

template<typename T>
CMySmartPointer<T>::~CMySmartPointer()
{
	if (pc_counter->iDec() == 0)
	{
		delete pc_pointer;
		delete pc_counter;
	}//if (pc_counter->iDec())
}//~CMySmartPointer()

template<typename T>
CMySmartPointer<T> CMySmartPointer<T>::operator=(const CMySmartPointer<T>& cOther) {
	if (pc_counter->iDec() == 0)
	{
		delete pc_pointer;
		delete pc_counter;
	}//if (pc_counter->iDec())

	pc_pointer = cOther.pc_pointer;
	pc_counter = cOther.pc_counter;
	pc_counter->iAdd();
	return *this;
}