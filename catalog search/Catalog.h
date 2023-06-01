#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// Forward declarations
template <class T>
class BookCatalog;

template <class T>
class MovieCatalog;

template <class T>
class MusicCatalog;

template <class T>
class Commands;

// Catalog class template
template <class T>
class Catalog
{
public:
    Catalog(); // Default constructor
    Catalog(T _info1, T _info2, T _info3, T _info4, T _info5); // Parameterized constructor

    T returnInfo1() { // Getter for info1
        return info1;
    }

    T returnInfo2() { // Getter for info2
        return info2;
    }

    T returnInfo3() { // Getter for info3
        return info3;
    }

    T returnInfo4() { // Getter for info4
        return info4;
    }

    T returnInfo5() { // Getter for info5
        return info5;
    }

    void AddBook(BookCatalog<T> book) { // Add a book to the bookCatalog list
        bookCatalog.push_back(book);
    }

    void AddMusic(MusicCatalog<T> music) { // Add music to the musicCatalog list
        musicCatalog.push_back(music);
    }

    void AddMovie(MovieCatalog<T> movie) { // Add a movie to the movieCatalog list
        movieCatalog.push_back(movie);
    }

    int returnBookSize() { // Return the size of the bookCatalog list
        return bookCatalog.size();
    }

    int returnMovieSize() { // Return the size of the movieCatalog list
        return movieCatalog.size();
    }

    int returnMusicSize() { // Return the size of the musicCatalog list
        return musicCatalog.size();
    }

    void AddCommands(Commands<T> cmd) { // Add commands to the commandList list
        commandList.push_back(cmd);
    }

    int returnCommandSize() { // Return the size of the commandList list
        return commandList.size();
    }

    void ShowCatalog(); // Display the catalog
    void ShowCommand(); // Display the commands
    void Search(T field, T keyword, T typeName); // Search for an item in the catalog
    template <class U>
    void SearchInList(list<U>& itemList, T field, T keyword); // Search for an item in a list
    template <class U>
    bool CheckFieldMatch(U& item, T field, T keyword); // Check if a field matches a keyword
    void ExecuteCommands(T typeName, Commands<T>& cmds); // Execute commands
    void SortStep(T field, T typeName); // Sort items in the catalog
    template <class U>
    void LogFile(U& item, T field); // Log an item's field to a file
    template <class U>
    void LogFile(list<U>& itemList, T field); // Log a list of items' fields to a file
    void writeUniqueEntry(T typeName); // Write a unique entry to the catalog
    void WriteCommandToFile(T cmdType, T keyword, T constant, T field); // Write a command to a file
    void WriteCommandToFile(T cmdType, T field); // Write a command to a file
    bool hasDuplicates(T fileType, T info1); // Check if there are duplicates in the catalog

private:
    list<BookCatalog<T>> bookCatalog; // List to store book items
    list<MusicCatalog<T>> musicCatalog; // List to store music items
    list<MovieCatalog<T>> movieCatalog; // List to store movie items
    list<Commands<T>> commandList; // List to store commands

protected:
    T info1; // Additional info field 1
    T info2; // Additional info field 2
    T info3; // Additional info field 3
    T info4; // Additional info field 4
    T info5; // Additional info field 5
};
