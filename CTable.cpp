#include "CTable.h"


CTable::CTable() {
	if (test)
		std::cout << s_name << std::endl;
	table = new int[length];
	for (int i = 0; i < length; i++)
		table[i] = 0;
}


CTable::CTable(std::string sName, int iTableLen) {
	s_name = sName;
	if (test)
		std::cout << s_name << std::endl;

	length = iTableLen;
	table = new int[length];
	for (int i = 0; i < length; i++)
		table[i] = 0;
	/*
	table = new int** [length];

	for (int i = 0; i < length; i++)
		table[i] = new int*[length];

	for (int i = 0; i < length; i++)
		for (int j = 0; j < length; j++)
			table[i][j] = new int[length];
	*/

}

CTable::CTable(CTable& pcOther) {
	s_name = pcOther.sGetName();
	length = pcOther.iGetSize();
	if (test)
		std::cout << "kopiuje " << s_name << std::endl;
	table = new int[length];
	for (int i = 0; i < length; i++)
		table[i] = pcOther.iGetVal(i);
}

/*CTable::CTable(CTable&& pcOther) {
	if (test)
		std::cout << "Move  " << std::endl;
	if (table != NULL) delete table;
	s_name = pcOther.sGetName();
	length = pcOther.iGetSize();
	table = pcOther.table;
	pcOther.table = NULL;
}*/

CTable::~CTable() {
	if (test)
		std::cout << "usuwam " << s_name << std::endl;
	/*
	for (int i = 0; i < length; i++)
		for (int j = 0; i < length; i++)
			delete[] table[i][j];

	for (int i = 0; i < length; i++)
		delete[] table[i];
	*/

	delete[] table;
}

void CTable::vSetName(std::string sName) {
	s_name = sName;
}

std::string CTable::sGetName() {
	return s_name;
}

int CTable::iGetSize() {
	return length;
}

int CTable::iGetVal(int Pos) {
	return table[Pos];
}

void CTable::vSetValueAt(int iOffset, int iNewVal) {
	if (iOffset < 0 || iOffset >= length)
		return;
	table[iOffset] = iNewVal;
}

void CTable::vPrint() {
	for (int i = 0; i < length; i++)
		std::cout << table[i] << " ";
	std::cout << std::endl;
}

bool CTable::bSetNewSize(int iTableLen) {
	if (iTableLen <= 0)
		return false;
	if (test)
		std::cout << "zmieniam rozmiar  " << iTableLen << std::endl;
	int* table2;
	table2 = new int[iTableLen];
	if (length > iTableLen)
		length = iTableLen;
	for (int i = 0; i < length; i++)
		table2[i] = table[i];
	length = iTableLen;
	delete[] table;
	table = table2;
	return true;
}

CTable* CTable::pcClone() {
	if (test)
		std::cout << "pcClone" << std::endl;
	CTable* table2 = new CTable(*this);
	return table2;
}

void v_mod_tab(CTable* pcTab, int iNewSize) {
	if (test)
		std::cout << "metoda przyjmojaca *CTable" << std::endl;
	pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize) {
	if (test)
		std::cout << "metoda przyjmojaca CTable" << std::endl;
	cTab.bSetNewSize(iNewSize);
}

void CTable::operator=(CTable& pcOther) {
	if (test)
		std::cout << "op=" << std::endl;
	table = pcOther.table;
	length = pcOther.length;
}//void CTable::operator=(CTable &pcOther)

CTable* CTable::operator+(CTable& pcOther) {
	if (test)
		std::cout << "op+" << std::endl;
	CTable* table2;
	int l = 0;
	table2 = new CTable("suma " + pcOther.s_name + " i " + s_name, (length + pcOther.length));
	for (int i = 0; i < length; i++)
		table2->vSetValueAt(i, table[i]);
	l = length;
	for (int i = 0; i < pcOther.length; i++)
		table2->vSetValueAt(i + l, pcOther.table[i]);
	return table2;

}