#pragma once
class CRefCounter
{
public:
	CRefCounter() { i_count; }
	int iAdd() { return(++i_count); }
	int iDec() { return(--i_count); };
	int iGet() { return(i_count); }
private:
	int i_count;
};//class CRefCounter


template<typename T>
class CMySmartPointer
{
public:
	CMySmartPointer(T* pcPointer);//CMySmartPointer(T*pcPointer)
	CMySmartPointer(const CMySmartPointer<T>& pcOther);//CMySmartPointer(const CMySmartPointer &pcOther)
	~CMySmartPointer();//~CMySmartPointer()
	CMySmartPointer operator=(const CMySmartPointer<T>& cOther);
	T& operator*() { return(*pc_pointer); }
	T* operator->() { return(pc_pointer); }
private:
	CRefCounter* pc_counter;
	T* pc_pointer;
};

