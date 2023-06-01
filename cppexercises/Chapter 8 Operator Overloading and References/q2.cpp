#include <iostream>
#include <cstdlib>
using namespace std;

class Rational 
{
    public:
        Rational(int _numerator,int _denominator){
            numerator=_numerator;
            denominator=_denominator;
        } 
        Rational(int wholeNum){
            numerator=wholeNum;
            denominator=1;
        }
        Rational(){
            numerator=0;
            denominator=1;
        }
        void setNumerator(int x);
        void setDenominator(int y);
        int getDenominator();
        int getNumerator();
        ostream& operator <<(ostream &outputStream ,  Rational& number);
        friend istream& operator >>(istream &inputStream ,  Rational& number);
        
    private:
        int numerator;
        int denominator;
};
bool operator == ( Rational &num1, Rational &num2);
bool operator < (Rational &num1, Rational &num2);
Rational operator + (Rational &num1, Rational &num2);
void Rational::setNumerator(int x){
    numerator=x;
}
void Rational::setDenominator(int y){
    denominator=y;
}
int Rational::getDenominator(){
    return denominator;
}
int Rational::getNumerator(){
    return numerator;
}
istream& operator >> (istream &inputStream ,  Rational& number){
    int numerator=0;
    int denominator=0;
        inputStream >> numerator;
        number.numerator=numerator;
        inputStream >> denominator;
        number.denominator=denominator;

    return inputStream;       
}
ostream& operator ImageEditor::<< (ostream &outputStream,  Rational& number){

    int numerator=number.getNumerator();
    int denominator=number.getDenominator();

    outputStream << numerator; 
    outputStream << "/" ;
    outputStream << denominator;

    return outputStream;
}


int main()
{
    Rational r1(67,100);
    Rational r4(67,100);
    Rational r2(-31);
    Rational r3;
    cout << "Test for r1 : "  << r1 << endl;
    cout << "Test for r2 : "  << r2 << endl;
    cout << "Test for r3 : "  << r3 << endl;
    cout << "Test for r4 : "  << r4 << endl;

    cin >> r3 ;
    cout << "Test for r3 : "  << r3 << endl;

    cout << "IS R1==R4 ? " << (r1==r4) << endl;
    cout << "IS R2<R1 ? " << (r2<r1) << endl;
    Rational r5=(r4+r2);
    cout << "R4+R2 : " << r5 << endl;
}


bool operator == ( Rational &num1,Rational &num2){
     
    return (num1.getNumerator()*num2.getDenominator()==num1.getDenominator()*num2.getNumerator());
}
bool operator < (Rational &num1, Rational &num2){
    return num1.getNumerator()*num2.getDenominator()<num1.getDenominator()*num2.getNumerator();
}
Rational operator + (Rational &num1, Rational &num2){
        int denom=num1.getDenominator()*num2.getDenominator();
        int numerator=num1.getNumerator()*num2.getDenominator()+num1.getDenominator()*num2.getNumerator();

    return Rational(numerator,denom);     
}
