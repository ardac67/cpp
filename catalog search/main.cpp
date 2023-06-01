#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <list>
#include "Catalog.h"
#include "BookCatalog.h"
#include "Catalog.cpp"
#include "BookCatalog.cpp"
#include "MovieCatalog.h"
#include "MovieCatalog.cpp"
#include "MusicCatalog.h"
#include "MusicCatalog.cpp"
#include "Commands.h"
#include "Commands.cpp"
#include "Exception.h"

vector<string> splitData(string &input,string delimeter);
vector<string> tokenize(string &str,char delim,string keyword);
void PrepareTheFile(string fileName,string typeName);

int main(){
    /*parsing data.txt*/
    string fileName="data.txt";
    string fileType;
    string line;
    ifstream file(fileName);
    vector <string> token;/*vector for tokenized stuff*/
    Catalog<string> catalog; /*base object*/
    string empty="";

    getline(file , fileType);

    PrepareTheFile("output.txt",fileType);
          if(fileType == "book") {
                while (getline(file, line)) {
                    try{
                        token = splitData(line,"\"");
                            BookCatalog newBookCatalog(token[0],token[1],token[2],token[3]);/*creating book object*/
                            if(token.size()==4){/*checking size*/
                                if(catalog.hasDuplicates(fileType,token[0])){/*checking duplicates*/
                                    throw MyException<string>(2,token);
                                }
                                else
                                    catalog.AddBook(newBookCatalog);/*if not add to list*/
                            }
                            else
                                throw MyException<string>(1,token);
                    }  
                    catch(MyException<string> ex){
                        ex.writeExceptionToLog(ex.returnType());
                    }
                }
            }
            else if (fileType == "music") {
                while (getline(file, line)) {
                    try{
                        token = splitData(line,"\"");
                        MusicCatalog newMusicCatalog(token[0],token[1],token[2],token[3]);/*creating music object*/
                        if(token.size()==4){
                            if(catalog.hasDuplicates(fileType,token[0])){/*checking if it has duplicate*/
                                throw MyException<string>(2,token);
                            }
                            else
                                catalog.AddMusic(newMusicCatalog);/*if not have problem add to list*/
                        }
                        else
                            throw MyException<string>(1,token);
                    }
                    catch(MyException<string> ex){
                        ex.writeExceptionToLog(ex.returnType());
                    }
                    
                }
            }
            else if (fileType == "movie") {
                while (getline(file, line)) {
                    try{
                        token = splitData(line,"\"");
                        if(token.size()==5){/*checking size of it*/
                            MovieCatalog newMovieCatalog(token[0],token[1],token[2],token[3],token[4]);     
                            if(catalog.hasDuplicates(fileType,token[0])){/*checking duplication*/
                                throw MyException<string>(2,token);
                            }
                            else
                                catalog.AddMovie(newMovieCatalog);/*if it has not a problem then add it to movieList*/
                        }
                        else
                            throw MyException<string>(1,token);
                    }
                    catch(MyException<string> ex){
                        ex.writeExceptionToLog(ex.returnType());
                    } 
                }
            }
            file.close();
    /*count the unique entry then write to file*/
    catalog.writeUniqueEntry(fileType);

    /*Parsing command.txt*/
    string commandName="commands.txt";
    ifstream fileCommand(commandName);
    vector<string>parsedCommands;
    string commandLine;
    while(getline(fileCommand,commandLine)){
        parsedCommands=tokenize(commandLine,' ',"in");
        for(int i=0;i<parsedCommands.size();i++){
            parsedCommands[i].erase(remove(parsedCommands[i].begin(), parsedCommands[i].end(), '"'), parsedCommands[i].end());
        }
        try{
                int control=parsedCommands.size();
                Commands<string> cmds;
                if(control==3){/*checking command size*/
                    Commands newCommand(parsedCommands[0],parsedCommands[2],parsedCommands[1]);
                    if(newCommand.checkFieldName(parsedCommands[2],fileType)){/*if field name proper then add the commandList*/
                        cmds=newCommand;
                        catalog.AddCommands(cmds);
                        catalog.ExecuteCommands(fileType,cmds);/*then execute that command*/
                    }    
                    else     
                        throw MyException<string>(3,parsedCommands);
                }
                else if(control==2){/*checking command size*/
                    Commands newCommand(parsedCommands[0],parsedCommands[1],empty); 
                    if(newCommand.checkFieldName(parsedCommands[1],fileType)){/*if field name proper then add the commandList*/
                        cmds=newCommand;
                        catalog.AddCommands(cmds);
                        catalog.ExecuteCommands(fileType,cmds);/*then execute that command*/
                    }    
                    else     
                        throw MyException<string>(3,parsedCommands);
                } 
                else{
                    throw MyException<string>(3,parsedCommands);
                }
        }
        catch(MyException<string> ex){
            ex.writeExceptionToLog(ex.returnType());
        }
    }
    fileCommand.close();
}

vector<string> splitData(string &input,string delimeter){/*just splits the catalog according to delimeter*/
    vector<string> tokens;
    size_t start= input.find(delimeter);
    size_t end= input.find(delimeter,start+1);
    while(start != std::string::npos && end != std::string::npos){
        string data=input.substr(start+1 , end-start-1);
        tokens.push_back(data);
        start=input.find(delimeter,end+1);
        end=input.find(delimeter,start+1);
    }

    return tokens;
}

vector<string> tokenize(string &str,char delim,string keyword){/*just tokenize the commands according to delimeter*/
    vector<string> tokens;
    istringstream iss(str);
    string token;
    bool quotes=false;
    while(getline(iss,token,' ')){
        if(!quotes){
            if(token!="in"){
                tokens.push_back(token);
            }   
        }
        else{
            tokens.back()+=' '+token;
        }
        if(token.front()=='"' && !quotes){
            quotes=true;
        }
        if(token.back()=='"' && quotes){
            quotes=false;
        }
        
    }
    return tokens;
}

void PrepareTheFile(string fileName,string typeName){/*just opens the log file*/
    std::ofstream file(fileName);
    if (file.is_open()) {
        file << "Catalog Read: " << typeName << endl;
        file.close();
    } else {
        std::cerr << "Unable to open the log file: " << fileName << std::endl;
    }
}

