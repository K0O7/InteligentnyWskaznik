#include <iostream>
#include "CMySmartPointer.cpp"
#include "CTab.h"
#include "CTable.h"


static void testy() {
    CTab* t = new CTab();
    CTab* t2 = new CTab();
    t2->bSetSize(11);
    CMySmartPointer<CTab> a(t);
    CMySmartPointer<CTab> b(t);
    CMySmartPointer<CTab> c(t2);
    a->bSetSize(7);
    std::cout << a->iGetSize();
    std::cout << b->iGetSize() << std::endl;
    b = c;
    std::cout << b->iGetSize();
    std::cout << c->iGetSize();
}

int main()
{
    testy();
}