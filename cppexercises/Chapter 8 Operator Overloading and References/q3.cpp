#include <iostream> 
#include <vector>
using namespace std;

class Imaginary{

    public:
        Imaginary(double real,double imaginary):realP(real),imaginaryP(imaginary){}
        Imaginary(double realPart):realP(realPart),imaginaryP(0){}
        Imaginary(){realP=0.0;imaginaryP=0.0;}
        friend bool operator ==(Imaginary &i1,Imaginary &i2);
        double Real(){
            return realP;
        }
        double Ima(){
            return imaginaryP;
        }
        void setReal(int param1){
            realP=param1;
        }
         void setIm(int param1){
            imaginaryP=param1;
        }
        friend istream & operator >> (istream & istr,Imaginary & i1);
        friend ostream & operator << (ostream & ostr,Imaginary & i1);
    private:
        double realP;
        double imaginaryP;
};
Imaginary  operator + (Imaginary &i1,Imaginary &i2);
int main()
{
    Imaginary num1,num2,num3;
    cin >> num1;
    cin >> num2;
    cout << num1;
    cout << num2;
    num3=num1+num2;
    cout << num3;
}
bool operator ==(Imaginary &i1,Imaginary &i2){

    return (i1.realP==i2.realP && i1.imaginaryP==i2.imaginaryP);    
}
Imaginary operator + (Imaginary &i1,Imaginary &i2){

    return Imaginary(i1.Real()+i2.Real(),i1.Ima()+i2.Ima());
}
istream & operator >> (istream & istr,Imaginary & i1){
    double imaginary,real;
    istr >> real;
    istr >> imaginary;
    i1.setReal(real);
    i1.setIm(imaginary);

    return istr;
}
ostream & operator << (ostream & ostr,Imaginary & i1){
    
    ostr << i1.Real();
    ostr << "+" << i1.Ima() << "i";

    return ostr;
}