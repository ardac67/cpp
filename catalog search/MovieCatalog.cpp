#include <iostream>
#include "MovieCatalog.h"
using namespace std;

template <class T>
MovieCatalog<T>::MovieCatalog():Catalog<T>(){}
 
template <class T>
MovieCatalog<T>::MovieCatalog(T _info1,T _info2,T _info3,T _info4,T _info5):
    Catalog<T>(_info1,_info2,_info3,_info4,_info5){}
