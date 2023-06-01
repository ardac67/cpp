#include <iostream>

using namespace std;
/*soru3-30p-GETUvector sinifini tasarlayýnýz,
 sinirsiz bellek miktari, 
 double elemanlarini tutacak ve 
 dinamik bellek yapýsýna sahip olacak (vector stl kullanýlmayacak, derste yapýlan vector orneklerine benzer, ancak dinamik olarak tasarým yapýlacak)
  GETUvector classinin asagidaki operatorlarý (kýsmen unutlmuþ da olabilir.) 
  overload edilmis metodlarýný yazýnýz (<<, +=, +, bellekte kac tane nesnesi oldugunu veren metod, 
  bir double dizisi alarak dinamik diziye ekleyen, double eleman alarak onu ekleyen, 
  ==, !=, [] lvalue olarak, [] rvalue olarak), ayrýca diðer gerekli kendinizce dusundugunuz metodlarý ekleyiniz.*/
class DynamicVector{

    public:
        DynamicVector(){
            size=0;
            array = new double[size];
        }
        DynamicVector(int Size):size(Size){
            array = new double[size];
        }
        DynamicVector(DynamicVector & vctrToCopy){
            array = new double[vctrToCopy.Size()];
            size=vctrToCopy.Size();
            for(int i=0;i<size;i++){
                array[i]=vctrToCopy.array[i];
            }
        }
        int Size(){
            return size;
        }
        void AddElement(double element){
            if(size==0){
                array = new double[1];
                size=size+1;
                array[0]=element;
            }
            else
            {
                double *arrayTemp;
                arrayTemp = new double[size+1];
                for(int i=0;i<size;i++){
                    arrayTemp[i]=array[i];
                }
                delete [] array;
                arrayTemp[size]=element;
                size=size+1;
                array = new double[size];
                for(int i=0;i<size;i++){
                    array[i]=arrayTemp[i];
                }
                delete [] arrayTemp;
            }
        }
        void AddAnotherArray(int * AddedArray,int sizeAdded){
            double *arrayTemp;
            arrayTemp= new double[size+sizeAdded];
            for(int i=0;i<size;i++){
                arrayTemp[i]=array[i];
            }
            for(int i=size;i<size+sizeAdded;i++){
                arrayTemp[i]=AddedArray[i-size];
            }
            delete [] array;
            size=size+sizeAdded;
            array = new double[size];
            for(int i=0;i<size;i++){
                array[i]=arrayTemp[i];
            }
            delete [] arrayTemp;
        }
        friend ostream & operator << (ostream &ostr,DynamicVector & toPrint){
            for(int i=0;i<toPrint.Size();i++){
                ostr << toPrint.array[i] << " ";
            }
            ostr << endl;

            return ostr;
        }
        DynamicVector & operator += (DynamicVector &rs){
            int size1=0;
            if(size>=rs.Size())
                size1=size;
            else 
                size1=rs.Size();
            for(int i=0;i<rs.Size();i++){
                this->array[i]=this->array[i]+rs.array[i];
            }        

            return *this;

        }
        friend bool operator == (DynamicVector &rs,DynamicVector &lf){
            if(rs.Size()!=lf.Size()){
                return false;
            }
            else {
                for(int i=0;i<lf.Size();i++){
                    if(rs.array[i]!=lf.array[i]){
                        return false;    
                    }
                    
                }
                return true;
            }
        }
        double & operator [] (int index){
            return array[index];
        }
        const double operator [] (int index)const {
            return array[index];
        }
        void RemoveElement(double number){
            double * newArray = new double[size-1];
            bool numberFound=false;
            for(int i=0;i<size-1;i++){
                if(array[i]==number)
                {
                    i=i+1;
                    numberFound=true;
                }    
                if(numberFound){
                    newArray[i-1]=array[i];
                }
                else if(!numberFound)    
                    newArray[i]=array[i];
            }
            delete [] array;
            size=size-1;
            array = new double[size];
            for(int i=0;i<size;i++){
                array[i]=newArray[i];
            }
            delete [] newArray;
        }
    private:
        int size;
        double *array;
};
int main(){

    DynamicVector vctr; 
    vctr.AddElement(5);
    vctr.AddElement(31);
    vctr.AddElement(6);
    vctr.AddElement(6);
    cout << vctr << endl;
    vctr.RemoveElement(5);
    vctr.RemoveElement(6);
    vctr.RemoveElement(31);

    cout << vctr ;
    
}