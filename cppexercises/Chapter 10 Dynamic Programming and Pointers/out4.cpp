#include <iostream>
#include <vector>
using namespace std;

class Dictionary1{
    public:
    Dictionary1(){
        string input=" ";
        while(input!=":q"){
            cin >> input;
            if(input==":q")
                break;
            else    
                langtoTranslate.push_back(input);
            string input2;
            cin >> input2;
                traslatedLanguage.push_back(input2);   
        }
    }
    string lookup(string wordToTranslate){
        int index=0;
        for(int i=0;i<langtoTranslate.size();i++){
            if(langtoTranslate[i]==wordToTranslate){
                index=i;
                break;
            }
        }

        return traslatedLanguage[index];
    }
    string reverse_lookup(string translatedWord){
        int index=0;
        for(int i=0;i<traslatedLanguage.size();i++){
            if(traslatedLanguage[i]==translatedWord){
                index=i;
                break;
            }
        }

        return langtoTranslate[index];
    }
    int returnSizeMain(){
        langtoTranslate.size();
    }
    
    int returnSizeSec(){
        traslatedLanguage.size();
    }
    void addWord(string word,string translation){
        bool add=true;
        for(int i=0;i<langtoTranslate.size();i++){
            if(langtoTranslate[i]==word){
                add=false;
                break;
            }
        }
        if(add){
            langtoTranslate.push_back(word);
            traslatedLanguage.push_back(translation);
        }
    }
    bool checkExistence(string word){
        for(int i=0;i<langtoTranslate.size();i++){
            if( langtoTranslate[i]==word || traslatedLanguage[i]==word){
                return true;
            }
        }
        return false;
    }
    Dictionary1 reverseDictionary1(){
        Dictionary1 reversed;

        for(int i=0;i<langtoTranslate.size();i++){
            reversed.traslatedLanguage.push_back(langtoTranslate[i]);
            reversed.langtoTranslate.push_back(traslatedLanguage[i]);
        }
        return reversed;
    }
    /*t-e -> e-f  = t-f*/
    Dictionary1 derivedDictionary1(Dictionary1 &dic1,Dictionary1 &dic2){
        Dictionary1 derived;
        for(int i=0;i<dic1.returnSizeMain();i++){
            string toFind=dic1.lookup(dic1.langtoTranslate[i]);
            for(int j=0;j<dic2.returnSizeSec();j++){
                string toTarget=dic2.lookup(toFind);
                derived.addWord(dic1.langtoTranslate[i],toTarget);
            }
        }
        return derived;

    }
    private:
        vector<string> langtoTranslate;
        vector<string> traslatedLanguage;
};


int main(){
    Dictionary1 dic;
    Dictionary1 dic2;
   /*  cout << dic.lookup("sevmek") << endl;
    cout << dic.reverse_lookup("love") << endl;
    dic.addWord("Arda","Determined");
    cout << dic.lookup("Arda") << endl;
    Dictionary1 dic1=dic.reverseDictionary1();
    cout << dic1.lookup("Determined") << endl; */
    Dictionary1 dicDerived=dic.derivedDictionary1(dic,dic2);

    cout << dicDerived.lookup("x") << endl;
     cout << dicDerived.lookup("a") << endl;
      cout << dicDerived.lookup("m") << endl;

}