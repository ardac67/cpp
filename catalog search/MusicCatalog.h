#pragma once
#include <iostream>
#include "Catalog.h"
using namespace std;

template <class T>
class MusicCatalog : public Catalog<T>
{
    public:
        // Default constructor declaration for the MusicCatalog class.
        MusicCatalog();
        // Constructor declaration for the MusicCatalog class that takes four parameters (_info1, _info2, _info3, _info4).
        MusicCatalog(T _info1,T _info2,T _info3,T _info4);
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