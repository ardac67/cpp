#include <iostream>
#include "Catalog.h"
#include "Commands.h"
#include "BookCatalog.h"
#include "MovieCatalog.h"
#include "MusicCatalog.h"
#include <algorithm>
#include <list>
#include <fstream>
#include "Exception.h"
#include <unordered_set>

template<class T>
Catalog<T>::Catalog(){}
  
template<class T>      
Catalog<T>::Catalog(T _info1,T _info2,T _info3,T _info4, T _info5){
    info1=_info1;
    info2=_info2;
    info3=_info3;
    info4=_info4;
    info5=_info5;
}

template <class T>
void Catalog<T>::Search(T field, T keyword, T typeName) {/*first define the searched field then search through it*/
        if (typeName == "book") {
            SearchInList(bookCatalog, field, keyword);
        } else if (typeName == "music") {
            SearchInList(musicCatalog, field, keyword);
        } else if (typeName == "movie") {
            SearchInList(movieCatalog, field, keyword);
        } else {
            cout << "Invalid typeName for searching." << endl;
            return;
        }
}

template <class T>
template<class U> 
void Catalog<T>::SearchInList(list<U>& itemList, T field, T keyword) {/*get list and iterate through it if find the keyword then log it*/
for (auto& item : itemList) {
    if(field=="starring"){
        if (CheckFieldMatch(item, field, keyword)) {
                LogFile(item,field);
            }
    }
    else{
            if (CheckFieldMatch(item, field, keyword)) {                 
                LogFile(item,field);
            }
        }
    }     
}

template <class T>
template<class U> 
bool Catalog<T>::CheckFieldMatch(U& item, T field, T keyword) {/*if the desired string founded in the field string*/
    string info;
    if (field == "title") {
        info=item.returnInfo1();
        size_t found=info.find(keyword);
        if(found != string::npos){
            return true;
        }
        else
            return false;
    } else if (field == "authors" || field=="artists" || field=="director") {
        info=item.returnInfo2();
        size_t found=info.find(keyword);
        if(found != string::npos){
            return true;
        }
        else
            return false;
    } else if (field=="year") {
        info=item.returnInfo3();
        size_t found=info.find(keyword);
        if(found != string::npos){
            return true;
        }
        else
            return false;
    } else if (field == "tags" || field=="genre" || field=="starring") {
        if(field=="starring")
            info=item.returnInfo5();
        else    
            info=item.returnInfo4();
        size_t found=info.find(keyword);
        if(found != string::npos){
            return true;
        }
        else
            return false;
    }
    return false;
}

template<class T>
void Catalog<T>::ExecuteCommands(T typeName,Commands<T> & cmds){/*executing commands according to command object
    first define command type then write the command to the file then search if it exists or not
*/
        if(cmds.returnCmdType()=="search"){
            WriteCommandToFile(cmds.returnCmdType(),cmds.returnKeyword(),"in"
            ,cmds.returnField());
            Search(cmds.returnField(),cmds.returnKeyword(),typeName);
        }
        else if(cmds.returnCmdType()=="sort"){  
            WriteCommandToFile(cmds.returnCmdType(),cmds.returnField());
            SortStep(cmds.returnField(),typeName);
            if(typeName=="book"){
                LogFile(bookCatalog,typeName);
            }
            else if(typeName=="music"){
                LogFile(musicCatalog,typeName);
            }
            else if(typeName=="movie"){
                LogFile(movieCatalog,typeName);
            }
        }
    
}

template <class T>
void Catalog<T>::SortStep(T field,T typeName){/*sort desired field according to field if not probably match then throw exception*/
    try{
            if (typeName == "book") {
                    // Sort bookCatalog based on the specified field
                    if (field == "title") {
                        bookCatalog.sort([](BookCatalog<T>& a,  BookCatalog<T>& b) {
                            return a.returnInfo1() < b.returnInfo1();
                        });
                    } else if (field == "authors") {
                        bookCatalog.sort([]( BookCatalog<T>& a,  BookCatalog<T>& b) {
                            return a.returnInfo2() < b.returnInfo2();
                        });
                    } else if (field == "year") {
                        bookCatalog.sort([]( BookCatalog<T>& a,  BookCatalog<T>& b) {
                            return a.returnInfo3() < b.returnInfo3();
                        });
                    } else if (field == "tags") {
                        bookCatalog.sort([]( BookCatalog<T>& a,  BookCatalog<T>& b) {
                            return a.returnInfo4() < b.returnInfo4();
                        });
                    } else {
                        // Invalid field
                        throw MyException<string>(3);
                    }
            } 
            else if (typeName == "music") {
                    if (field == "title") {
                        musicCatalog.sort([](MusicCatalog<T>& a,  MusicCatalog<T>& b) {
                            return a.returnInfo1() < b.returnInfo1();
                        });
                    } else if (field == "artists") {
                        musicCatalog.sort([]( MusicCatalog<T>& a,  MusicCatalog<T>& b) {
                            return a.returnInfo2() < b.returnInfo2();
                        });
                    } else if (field == "year") {
                        musicCatalog.sort([]( MusicCatalog<T>& a,  MusicCatalog<T>& b) {
                            return a.returnInfo3() < b.returnInfo3();
                        });
                    } else if (field == "genre") {
                        musicCatalog.sort([]( MusicCatalog<T>& a,  MusicCatalog<T>& b) {
                            return a.returnInfo4() < b.returnInfo4();
                        });
                    } else {
                        // Invalid field
                        throw MyException<string>(3);
                    }
            } 
            else if (typeName == "movie") {
                    if (field == "title") {
                        movieCatalog.sort([](MovieCatalog<T>& a,  MovieCatalog<T>& b) {
                            return a.returnInfo1() < b.returnInfo1();
                        });
                    } else if (field == "director") {
                        movieCatalog.sort([]( MovieCatalog<T>& a,  MovieCatalog<T>& b) {
                            return a.returnInfo2() < b.returnInfo2();
                        });
                    } else if (field == "year") {
                        movieCatalog.sort([]( MovieCatalog<T>& a,  MovieCatalog<T>& b) {
                            return a.returnInfo3() < b.returnInfo3();
                        });
                    } else if (field == "genre") {
                        movieCatalog.sort([]( MovieCatalog<T>& a,  MovieCatalog<T>& b) {
                            return a.returnInfo4() < b.returnInfo4();
                        });
                    } else if (field == "starring") {
                        movieCatalog.sort([]( MovieCatalog<T>& a,  MovieCatalog<T>& b) {
                            return a.returnInfo5() < b.returnInfo5();
                        });
                    } else {
                        // Invalid field
                        throw MyException<string>(3);
                    }
            } 
            else {
                    // Invalid typeName
                    throw MyException<string>(3);
                }
    }
    catch(MyException<string> ex){
        ex.writeExceptionToLog(ex.returnType());
    }
}

template <class T>
template<class U> 
void Catalog<T>::LogFile(U& item, T field){/*log the following informations*/
    ofstream file("output.txt", std::ios::out | std::ios::app);
    //cout <<" its here" << endl;
    if (file.is_open()) {
        if(returnMovieSize()>0){
            file << '"'+item.returnInfo1()+'"' << " "<< '"'+item.returnInfo2()+'"'
            <<" " << '"'+item.returnInfo3()+'"' << " "
            << '"'+item.returnInfo4()+'"' << " " << '"'+item.returnInfo5()+'"'
            <<endl;
        }
        else{
            file << '"'+item.returnInfo1()+'"' << " "<< '"'+item.returnInfo2()+'"'
            <<" " << '"'+item.returnInfo3()+'"' << " "
            << '"'+item.returnInfo4()+'"'
            <<endl;
        }
        file.close();
    }
    else {
        std::cout << "Failed to open the file.\n";
    }
    
}

template <class T>
template<class U> 
void Catalog<T>::LogFile(list<U>& itemList,T field){/*log the following informations according to list*/
    ofstream file("output.txt", std::ios::out | std::ios::app);
    //cout <<" its here" << endl;
    if (file.is_open()) {
        if(returnMovieSize()>0){
            for (auto& item : itemList){
                file << '"'+item.returnInfo1()+'"' << " "<< '"'+item.returnInfo2()+'"'
                <<" " << '"'+item.returnInfo3()+'"' << " "
                << '"'+item.returnInfo4()+'"' << " " << '"'+item.returnInfo5()+'"'
                <<endl;
            }
        }
        else{
                for (auto& item : itemList){
                    file << '"'+item.returnInfo1()+'"' << " "<< '"'+item.returnInfo2()+'"'
                    <<" " << '"'+item.returnInfo3()+'"' << " "
                    << '"'+item.returnInfo4()+'"'
                    <<endl;
            }
        }
        file.close();
    }
    else {
        std::cout << "Failed to open the file.\n";
    }
}

template <class T>
void Catalog<T>::writeUniqueEntry(T typeName){/*count the unique entries*/
    ofstream file("output.txt", std::ios::out | std::ios::app);
    if (file.is_open()) {
        int counter=0;
        if(typeName=="book"){
            std::unordered_set<T> unique;
            list<BookCatalog<string>>::iterator iterCommand;
            for(iterCommand=bookCatalog.begin(); iterCommand!= bookCatalog.end();iterCommand++){
                unique.insert(iterCommand->returnInfo1()); 
            }
        file << unique.size() <<" "<<"unique entries"<<endl;
    }
    else if(typeName=="movie"){
            std::unordered_set<T> unique;
            list<MovieCatalog<string>>::iterator iterCommand;
            for(iterCommand=movieCatalog.begin(); iterCommand!= movieCatalog.end();iterCommand++){
                unique.insert(iterCommand->returnInfo1()); 
            }
        file << unique.size() <<" "<<"unique entries"<<endl;
    }
    else if(typeName=="music"){
            std::unordered_set<T> unique;
            list<MusicCatalog<string>>::iterator iterCommand;
            for(iterCommand=musicCatalog.begin(); iterCommand!= musicCatalog.end();iterCommand++){
                unique.insert(iterCommand->returnInfo1()); 
            }
        file << unique.size() <<" "<<"unique entries"<<endl;
    }
    file.close();
    }
    else {
        std::cout << "Failed to open the file.\n";
    }
    
}

template <class T>
void Catalog<T>::WriteCommandToFile(T cmdType,T keyword,T constant,T field){/*write unique commands the log file*/
    ofstream file("output.txt", std::ios::out | std::ios::app);
    if (file.is_open()) {
            file << cmdType << " " << '"'+keyword+'"' << " in " << '"'+field+'"' << endl;
        file.close();
    }
    else {
        std::cout << "Failed to open the file.\n";
    }
}

template <class T>
void Catalog<T>::WriteCommandToFile(T cmdType,T field){/*if it is just sort use this overload*/
    ofstream file("output.txt", std::ios::out | std::ios::app);
    if (file.is_open()) {
            file << cmdType << " "<< '"'+field+'"' << endl;
        file.close();
    }
    else {
        std::cout << "Failed to open the file.\n";
    }
}

template <class T>
bool Catalog<T>::hasDuplicates(T fileType,T info ){/*checking catalog has duplicates*/
    bool control=false;
    if(fileType=="book"){
        list<BookCatalog<string>>::iterator iterCommand;
        list<BookCatalog<string>>::iterator iterCommand1;
        for(iterCommand=bookCatalog.begin(); iterCommand!= bookCatalog.end();iterCommand++){
                if(iterCommand->returnInfo1()==info){
                    control=true;
                    break;
                }
                else    
                    control=false;
        }
        return control;
    }
    else if(fileType=="movie"){
        list<MovieCatalog<string>>::iterator iterCommand;
        list<MovieCatalog<string>>::iterator iterCommand1;
        for(iterCommand=movieCatalog.begin(); iterCommand!= movieCatalog.end();iterCommand++){ 
                if(iterCommand->returnInfo1()==info){
                    control=true;
                    break;
                }
                else    
                    control=false;
        }
        return control;
    }
    else if(fileType=="music"){
        list<MusicCatalog<string>>::iterator iterCommand;
        list<MusicCatalog<string>>::iterator iterCommand1;
        for(iterCommand=musicCatalog.begin(); iterCommand!= musicCatalog.end();iterCommand++){
                if(iterCommand->returnInfo1()==info){
                    control=true;
                    break;
                }
                else    
                    control=false;
        }
        return control;
    }
    else 
        return false;
}
