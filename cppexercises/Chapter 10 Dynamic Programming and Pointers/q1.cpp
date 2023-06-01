#include <iostream>

using namespace std;
class TwoDArray
{
    public:
        TwoDArray(){/*working*/
            int row,col;
            cin >> row ;
            cin >> col;
            maxRows=row;
            maxCols=col;
            intArrPtr= new double*[row];/*weird part*/
            for(int i=0;i<row;i++){
                intArrPtr[i]= new double[col];
            }
        }
        
        TwoDArray(int row ,int col){/*woring*/
            maxRows=row;
            maxCols=col;
            intArrPtr= new double*[row];
            for(int i=0;i<col;i++){
                intArrPtr[i]= new double[col];
            }
            for(int i=0;i<maxRows;i++){
                for(int j=0;j<maxCols;j++){
                    intArrPtr[i][j]=i+j;
                }
            }

        }
        TwoDArray(const TwoDArray &copied){/*working*/
            intArrPtr= new double*[copied.maxRows];
            for(int i=0;i<copied.maxRows;i++){
                intArrPtr[i]= new double[copied.maxCols];
            }

            maxRows=copied.maxRows;
            maxCols=copied.maxCols;
            for(int i=0;i<copied.maxRows;i++){
            for(int j=0;j<copied.maxCols;j++){
                intArrPtr[i][j]=copied.intArrPtr[i][j];
            }
            }
        }
        void SetNumber(int row ,int col,int value){/*working*/
            intArrPtr[row][col]=value;
        }
        double GetIndex(int row,int col){/*working*/
            return intArrPtr[row][col];
        }
        int returnRow(){return maxRows;}/*working*/
        int returnCol(){return maxCols;}/*working*/
        friend ostream & operator << (ostream & ostr,TwoDArray & arrayToPrint)/*working*/
        {
            for(int i=0;i<arrayToPrint.returnRow();i++){
                for(int j=0;j<arrayToPrint.returnCol();j++){
                    ostr << arrayToPrint.intArrPtr[i][j] << " "; 
                }
                ostr << endl;
            }
            return ostr;
        }
        TwoDArray& operator = (const TwoDArray &rs){/*referance döndürmece tuhaflık var bak bunada*/
            maxRows=rs.maxRows;
            maxCols=rs.maxCols;            
            intArrPtr=new double*[maxRows];
            for(int i=0;i<maxCols;i++){
                intArrPtr[i]= new double[maxCols];
            }
            for(int i=0;i<maxRows;i++){
                for(int j=0;j<maxCols;j++){
                    intArrPtr[i][j]=rs.intArrPtr[i][j];
                }
            }
            return *this;
        }
        friend TwoDArray operator + (const TwoDArray &ls,const TwoDArray &rs);/*woring*/
        ~TwoDArray(){/*tam oturmadı kontrol et*/
            for(int i=0;i<maxRows;i++){
                delete [] intArrPtr[i];
            }
            delete [] intArrPtr;
            printf("Deleted\n");
        }

        
    private:
        int maxRows;
        int maxCols;
        double **intArrPtr;
};

int main()
{
    TwoDArray two(2,2),three(2,2);
    TwoDArray newObj(two+three);
    cout << two;
    cout << three;
    cout << newObj;
    //cout << newObj.returnRow() << " " << newObj.returnCol()<< endl;
    two=newObj;
    cout << two;
    two.~TwoDArray();
    three.~TwoDArray();
    newObj.~TwoDArray();
}

TwoDArray operator + (const TwoDArray &ls,const TwoDArray &rs){

    TwoDArray summedArr(ls.maxRows,ls.maxCols);
        for(int i=0;i<ls.maxRows;i++){
            for(int j=0;j<ls.maxCols;j++){
                summedArr.intArrPtr[i][j]=ls.intArrPtr[i][j]+rs.intArrPtr[i][j];
            }
        }

    return TwoDArray(summedArr);

}
