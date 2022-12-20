#include "CTab.h"
CTab::CTab(const CTab& cOther)
{
	v_copy(cOther);
	std::cout << "Copy ";
}//CTab::CTab(const CTab &cOther)

CTab::~CTab()
{
	if (pi_tab != NULL) delete pi_tab;
	std::cout << "Destr ";
}//CTab::~CTab()

CTab CTab::operator=(const CTab& cOther)
{
	if (pi_tab != NULL) delete pi_tab;
	v_copy(cOther);
	std::cout << "op= ";
	return(*this);
}//CTab CTab::operator=(const CTab &cOther)

CTab CTab::operator=(const CTab&& cOther) {
	if (pi_tab != NULL) delete pi_tab;
	std::cout << "opp= ";
	return(std::move(*this));
}//CTab CTab::operator=(const CTab &&cOther)

void CTab::v_copy(const CTab& cOther)
{
	pi_tab = new int[cOther.i_size];
	i_size = cOther.i_size;
	for (int ii = 0; ii < cOther.i_size; ii++)
		pi_tab[ii] = cOther.pi_tab[ii];
}//void CTab::v_copy(CTab &cOther)

CTab::CTab(CTab&& cOther)
{
	pi_tab = cOther.pi_tab;
	i_size = cOther.i_size;
	cOther.pi_tab = NULL;
	std::cout << "MOVE ";
}//CTab::CTab(CTab &&cOther)

bool CTab::bSetSize(int iNewSize) {
	if (iNewSize <= 0)
		return false;
	int* iNewTab = new int[iNewSize];
	if (i_size > iNewSize)
		i_size = iNewSize;
	for (int ii = 0; ii < i_size; ii++)
		iNewTab[ii] = pi_tab[ii];
	i_size = iNewSize;
	delete pi_tab;
	pi_tab = iNewTab;
	return true;
}