#pragma once
#include<iostream>
static const bool test = true;

class CTable {
private:
	std::string s_name = "standName";
	int length = 5;
	//int*** table;
	int* table;

public:
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(CTable& pcOther);
	~CTable();
	void vSetName(std::string sName);
	std::string sGetName();
	int iGetSize();
	int iGetVal(int Pos);
	bool bSetNewSize(int iTableLen);
	void vSetValueAt(int iOffset, int iNewVal);
	void vPrint();
	CTable* pcClone();
	void operator=(CTable& pcOther);
	CTable* operator+(CTable& pcOther);
};

void v_mod_tab(CTable* pcTab, int iNewSize);
void v_mod_tab(CTable cTab, int iNewSize);