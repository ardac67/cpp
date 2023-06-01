#include <iostream>
#include "BookCatalog.h"
using namespace std;

template <class T>
BookCatalog<T>::BookCatalog():Catalog<T>(){}
// Constructor for BookCatalog class. Inherits from Catalog class.

template <class T>
BookCatalog<T>::BookCatalog(T _info1,T _info2,T _info3,T _info4)
:Catalog<T>(_info1,_info2,_info3,_info4,""){}
// Constructor for BookCatalog class that takes four parameters (_info1, _info2, _info3, _info4)
// and calls the constructor of the Catalog class with these parameters and an empty string as the fifth parameter.
// The empty string is passed as an additional parameter specific to the BookCatalog class.
