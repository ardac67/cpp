#include <iostream>

using namespace std;

class DynamicStringArray{
    public:
        DynamicStringArray(){
            size=0;
            dynamicArray=nullptr;
        }
        DynamicStringArray(DynamicStringArray & arr2){
            size=arr2.Size();
            dynamicArray = new string[size];
            for(int i=0;i<size;i++){
                dynamicArray[i]=arr2.getEntry(i);
            }
        }
        DynamicStringArray & operator =(DynamicStringArray & copied){
            size=copied.Size();
            delete [] dynamicArray;
            dynamicArray = new string[size];
            for(int i=0;i<size;i++){
                dynamicArray[i]=copied.dynamicArray[i];
            }

            return *this;
        }
        int Size(){
            return size;
        }
        void addEntry(string entry){
            //size=size+1;
            string *newArray = new string[size+1];
            for(int i=0;i<size;i++){
                newArray[i]=dynamicArray[i];
            }
            newArray[size]=entry;
            size=size+1;
            delete [] dynamicArray;
            dynamicArray = new string[size];
            /*weird sanki*/
            dynamicArray=newArray;
        }
        bool deleteEntry(string entry){
            bool found=false;
            for(int i=0;i<size;i++){
                if(dynamicArray[i]==entry){
                    string *newArray = new string[size-1];
                    int k=0;
                    while(k<size-1){
                        if(i==k)
                            k=k+1;
                        else
                        {
                            newArray[k]=dynamicArray[k];
                            k++;
                        }    
                    }
                    delete [] dynamicArray;
                    size=size-1;
                    dynamicArray = new string[size];
                    dynamicArray=newArray;
                    found=true;
                    break;
                }
            }
            if(found){
                return true;
            }
            else    
                return false;
        }
        string getEntry(int index){
            if(index>=size || index<0)
                return nullptr; 
            else    
                return dynamicArray[index];
        }
        ~DynamicStringArray(){
            printf("Array freeed\n");
            delete [] dynamicArray;
        }
        void printArray(){
            for(int i=0;i<size;i++){
                cout << dynamicArray[i] << endl;
            }
        }
    private:
        string *dynamicArray;
        int size;
};
int main(){
    DynamicStringArray names;
    // List of names
    names.addEntry("Frank");
    names.addEntry("Wiggum");
    names.addEntry("Nahasapeemapetilon");
    names.addEntry("Quimby");
    names.addEntry("Flanders");
    cout << "List of names:" << endl;
    for(int i = 0; i < names.Size(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    names.addEntry("Spuckler");
    cout << "After adding a name:" << endl;
    for(int i = 0; i < names.Size(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    names.deleteEntry("Nahasapeemapetilon");
    cout << "After removing a name:" << endl;
    for(int i = 0; i < names.Size(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;
    names.deleteEntry("Skinner");
    cout << "After removing a name that isn't on the list:" << endl;
        for (int i = 0; i < names.Size(); i++)
        cout << names.getEntry(i) << endl;
        cout << endl;
        names.addEntry("Muntz");
        cout << "After adding another name:" << endl;
        for (int i = 0; i < names.Size(); i++)
        cout << names.getEntry(i) << endl;
        cout << endl;
        // Remove all of the names by repeatedly deleting the last one
        while (names.Size() > 0) {
        names.deleteEntry(names.getEntry(names.Size() - 1));
        }
        cout << "After removing all of the names:" << endl;
        for (int i = 0; i < names.Size(); i++)
        cout << names.getEntry(i) << endl;
        cout << endl;
        names.addEntry("Burns");
        cout << "After adding a name:" << endl;
        for (int i = 0; i < names.Size(); i++)
        cout << names.getEntry(i) << endl;
        cout << endl;
        cout << "Testing copy constructor" << endl;
        DynamicStringArray names2(names);
        // Remove Burns from names
        names.deleteEntry("Burns");
        cout << "Copied names:" << endl;
        for (int i = 0; i < names2.Size(); i++)
        cout << names2.getEntry(i) << endl;
        cout << endl;
        cout << "Testing assignment" << endl;
        DynamicStringArray names3 = names2;
        // Remove Burns from names2
        names2.deleteEntry("Burns");
        cout << "Copied names:" << endl;
        for (int i = 0; i < names3.Size(); i++)
        cout << names3.getEntry(i) << endl;
        cout << endl;
        cout << "Enter a character to exit." << endl;
        char wait;
        cin >> wait;
        return 0;


}
