#pragma once
#include <exception>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Custom exception class derived from std::exception
template<typename U>
class MyException : public std::exception {
public:
    // Constructor with data for "missing field" exception
    MyException(int _type, vector<U> data) : type(_type), u(data) {}

    // Constructor for other exceptions (without data)
    MyException(int _type) : type(_type) {}

    // Write the exception details to a log file
    void writeExceptionToLog(int type) {
        ofstream file("output.txt", std::ios::out | std::ios::app);
        if (file.is_open()) {
            if (type == 1) {
                file << "Exception: missing field" << endl;
                for (int i = 0; i < u.size(); i++) {
                    file << '"' + u[i] + '"';
                    if (i != u.size() - 1) {
                        file << " ";
                    }
                }
                file << endl;
            } else if (type == 2) {
                file << "Exception: duplicate entry" << endl;
                for (int i = 0; i < u.size(); i++) {
                    file << '"' + u[i] + '"';
                    if (i != u.size() - 1) {
                        file << " ";
                    }
                }
                file << endl;
            } else if (type == 3) {
                file << "Exception: command is wrong" << endl;
                for (int i = 0; i < u.size(); i++) {
                    if (u[0] == "search") {
                        if (u[i] != "search") {
                            file << '"' + u[i] + '"';
                            if (i == 1) {
                                file << " in";
                            }
                            if (i != u.size() - 1) {
                                file << " ";
                            }
                        } else {
                            file << u[i] << " ";
                        }
                    } else if (u[0] == "sort") {
                        if (u[i] != "sort") {
                            file << '"' + u[i] + '"';
                            if (i != u.size() - 1) {
                                file << " ";
                            }
                        } else {
                            file << u[i] << " ";
                        }
                    } else {
                        file << u[i];
                        if (i != u.size() - 1) {
                            file << " ";
                        }
                    }
                }
                file << endl;
            }
        } else {
            cout << "Failed to open the file.\n";
        }
    }

    // Return the type of the exception
    int returnType() {
        return type;
    }

private:
    int type;
    vector<U> u;
};
