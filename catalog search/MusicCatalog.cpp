#include <iostream>
#include "MusicCatalog.h"
using namespace std;

template <class T>
MusicCatalog<T>::MusicCatalog():Catalog<T>(){}
 
template <class T>
MusicCatalog<T>::MusicCatalog(T _info1,T _info2,T _info3,T _info4):
                Catalog<T>(_info1,_info2,_info3,_info4,""){}