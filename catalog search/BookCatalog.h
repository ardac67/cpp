#pragma once
#include <iostream>
#include "Catalog.h"
using namespace std;


template <class T>
class BookCatalog : public Catalog<T>
// Declaration of the BookCatalog class, which is derived from the Catalog class using the public inheritance access specifier.
{
    public:
        BookCatalog();
        // Default constructor declaration for the BookCatalog class.

        BookCatalog(T _info1, T _info2, T _info3, T _info4);
        // Constructor declaration for the BookCatalog class that takes four parameters (_info1, _info2, _info3, _info4).
        /*getters for inherited information*/
        T returnInfo1(){
            return Catalog<T>::returnInfo1();
        }
         T returnInfo2(){
            return Catalog<T>::returnInfo2();
        }
         T returnInfo3(){
            return Catalog<T>::returnInfo3();
        }
         T returnInfo4(){
            return Catalog<T>::returnInfo4();
        }
         T returnInfo5(){
            return Catalog<T>::returnInfo5();
        }

};
