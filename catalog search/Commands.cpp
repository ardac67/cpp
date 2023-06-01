#include <iostream>
#include "Commands.h"
using namespace std;

// Default constructor
template <class T>
Commands<T>::Commands() {}

// Parameterized constructor
template <class T>
Commands<T>::Commands(T _commandType, T _field, T _keyword) {
    commandType = _commandType;
    field = _field;
    keyword = _keyword;
}

// Parameterized constructor
template <class T>
Commands<T>::Commands(T _commandType, T _field) {
    commandType = _commandType;
    field = _field;
}

// Check if the field name matches the file type
template <class T>
template <class U>
bool Commands<T>::checkFieldName(U field, U fileType) {
    if (fileType == "book") {
        if (field == "title" || field == "authors" || field == "year" || field == "tags")
            return true;
        else
            return false;
    } else if (fileType == "music") {
        if (field == "title" || field == "year" || field == "genre" || field == "artists")
            return true;
        else
            return false;
    } else if (fileType == "movie") {
        if (field == "title" || field == "year" || field == "director" || field == "genre" || field == "starring")
            return true;
        else
            return false;
    } else {
        return false;
    }
}
