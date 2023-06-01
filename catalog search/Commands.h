#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Commands class template
template <class T>
class Commands 
{   
public:
    Commands(); // Default constructor
    Commands(T _commandType, T _field, T _keyword); // Parameterized constructor
    Commands(T _commandType, T _field); // Parameterized constructor

    T returnCmdType() { // Getter for commandType
        return commandType;
    }

    T returnField() { // Getter for field
        return field;
    }

    T returnKeyword() { // Getter for keyword
        return keyword;
    }

    template<typename U>
    bool checkFieldName(U field, U fileType); // Check if the field name matches the file type

private:
    T commandType; // Type of command
    T field; // Field name
    T keyword; // Keyword associated with the command
};
