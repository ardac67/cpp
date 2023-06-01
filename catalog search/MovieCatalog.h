#pragma once
#include <iostream>
#include "Catalog.h"
using namespace std;

template <class T>
class MovieCatalog : public Catalog<T>
{
    friend class Catalog<T>;
    public:
        // Default constructor declaration for the MovieCatalog class.
        MovieCatalog();
        // Constructor declaration for the MovieCatalog class that takes four parameters (_info1, _info2, _info3, _info4,_info5).
        MovieCatalog(T _info1,T _info2,T _info3,T _info4,T _info5);
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