#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;


class ImageEditor
{
    public:
        int OpenFile(); /*member function to open a file*/
        int ConvertToGreyScale();/*convert function to converting greyscale for file*/
        int SaveImage();/*saving image if the file opened*/
        bool ControlNumber(string text);/*controlling input in a situation of char existance*/
        ImageEditor(){};/*default constructor no parameters*/
        
    private:    
        string ImageFileName,format;/*string format and ImageFileName variables*/
        bool isImageOpened;/*if the file open makes it true just a control variable*/
        int RowMember,ColMember,maxValueRgb;/*Rowmember and colmember just hold the pixel data of releated objects, and max value of rgb is the 255 */
        vector<vector<int>> changedData,originalData;/*pixel data for original data and greyscaled data of image*/
};

int main() {
    int choice = -1;
    ImageEditor imageEditor; /*creating instance of ImageEditor class*/
    int scriptChoice;
    int openImageChoice;
    int x;
    bool valid_input=false,valid_input1=false,valid_input2=false;
    while (choice != 0) {
        cout << "Main Menu" << endl;
        cout << "0 - Exit" << endl;
        cout << "1 - Open An Image(D)" << endl;
        cout << "2 - Save Image Data(D)" << endl;
        cout << "3 - Scripts(D)" << endl;
        cin >> choice;

        if (!(valid_input = cin.good())) {/*char existence control*/
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice=-1;
		}
 
        switch (choice) {
            case 0:
                // Exit the program
                break;
            case 1:
             
                openImageChoice=-1;
                while (openImageChoice != 0) {
                    cout << "OPEN AN IMAGE MENU" << endl;
                    cout << "0 - UP" << endl;
                    cout << "1 - Enter The Name Of the File" << endl;
                    cin >> openImageChoice;
                      if (!(valid_input2 = cin.good())) {/*char existence control*/
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            openImageChoice=-1;
                        }

                    switch (openImageChoice) {
                        case 0:
                            // Go back to main menu
                            break;
                        case 1:
                            // OpenImage
                            x=imageEditor.OpenFile(); /*openin image*/
                            if(x==-1){ /*if error occured stay in the menu*/
                                cout << "ERROR" << endl;
                                x=0;
                            }    
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 2:
                // Save image data
                x=imageEditor.SaveImage();/*saving image if and only if file is opened*/
                if(x==-1)/*if error occured stay in the menu*/
                {
                    cout << "ERROR" << endl;
                    x=0;   
                };  
                break;
            case 3:
                scriptChoice = -1;
                
                while (scriptChoice != 0) {
                    cout << "Scripts Menu" << endl;
                    cout << "0 - UP" << endl;
                    cout << "1 - Convert To Grayscale(D)" << endl;
                    cin >> scriptChoice;
                      if (!(valid_input1 = cin.good())) {/* controlling the char existence*/
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            scriptChoice=-1;
                        }

                    switch (scriptChoice) {
                        case 0:
                            // Go back to main menu
                            break;
                        case 1:
                            // Convert to grayscale
                            x=imageEditor.ConvertToGreyScale();/*converting the image to grey scale if and only if image is opened*/
                            if(x==-1){
                                cout << "ERROR" << endl;
                                x=0;
                            }   
                            break;
                        default:
                            break;
                    }
                }
                break;
            default:
                break;
        }
    }

    return 0;
}

int ImageEditor::OpenFile()
{   
    cin >> ImageFileName;/*getting file name*/

    string text,temp;
    int count=1,rowPlace=0,columnPlace=0;
    int found,column=0,row=0;

    ifstream OpenedFile(ImageFileName);

    if(!OpenedFile.is_open())/*file status control maybe it is no existed*/
        return -1;

    stringstream stringToParse;


    getline(OpenedFile,text); /*getting first line of the file*/
    format=text;/*assigned it in format member variable of the class*/

    if(text!="P3")
        return -1;
    getline(OpenedFile,text);/*getting second line */

    stringToParse << text;

    while (!stringToParse.eof()) { /*getting the pixel column and row data*/
 
        stringToParse >> temp;
 
        if (stringstream(temp) >> found){

            if(count==1){
                column=found;
                count++;
            }
            else if(count==2){
                row=found;
                count++;
            }
        }

        temp = "";
    }  

    if(row==0 || column==0)/*if row or column value is not matched with desired file format print return -1*/
        return -1;

    RowMember=row;/*assing it to member variables as row */
    ColMember=column;/*assing it to member variables as column */

    originalData.resize(row);/*resizing the originaldata vector which holds the pixel data of the image*/
    for (int i = 0; i < row; i++) {
        originalData[i].resize(column * 3);/*resizing column of the vector*/
    }

    getline(OpenedFile,text);/*getting the numeric value of max rgb value*/
    maxValueRgb=stoi(text);/*assing it into the maxValueRgb variable*/
   
    while(getline(OpenedFile,text)){/*getting the pixel data values */

        stringstream ss;
        ss << text;

        string newTemp;
        int newFound;
        
        
        while(!ss.eof()){/*reading till end of the string*/
            ss >> newTemp;
            bool checkNum=ControlNumber(newTemp);/*char existence control if exists return -1*/
            if(!checkNum)
                return -1;
            if (stringstream(newTemp) >> newFound){
                    originalData[rowPlace][columnPlace]=newFound; /*if no error occured assing the data inside of the file to the member original data vector variable */
                    columnPlace++;
            }
            newTemp = "";
        }
        if(columnPlace==(column*3))
        {
            columnPlace=0;
            rowPlace++;
        }
    }
    isImageOpened=true; /*at the end everything went succesful set isImageOpened variable to the true*/
    OpenedFile.close();/*close the file*/

    return 1;
}

int ImageEditor::ConvertToGreyScale()
{   
    if(!isImageOpened){/*if file not opened return -1 as an error*/
        return -1;
    }
    float coefficients[3]={0};/*array to hold coefficients of the gray values*/
    bool  numberRangeCheck=true,valid_inputCoef=false;/*error controls for char existence and number range*/
    do
    {
        cout<< "Enter the coefficients for the test" << endl;
        
        for(int i=0;i<3;i++) {
            cin >> coefficients[i];/*get inputs*/
            if (!(valid_inputCoef = cin.good())) {/*control the inputs in case of char existence*/
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                numberRangeCheck=false;
                break;
		    }
            else    
                numberRangeCheck=true;
        }
            
        if(numberRangeCheck)/*control inputs in case of the range [0,1)*/
        {
             for(int i=0;i<3;i++){

                if(coefficients[i]<0 || coefficients[i]>=1){

                    numberRangeCheck=false;
                    break;
                }
            }
        }
        
        if(!numberRangeCheck)/*if format is not okey then print error*/
            cerr << "Please re-enter the value of rgb" << endl;
        
       
        
    }
    while(!numberRangeCheck);/*getting the inputs until correct inputs is given*/

    int calc=0;
    for(int i=0;i<RowMember;i++){/*making rgb calculations according to the instructions of the hmw*/
        for(int j=0;j<ColMember*3;j+=3){

            int red = originalData[i][j];
            int green = originalData[i][j + 1];
            int blue = originalData[i][j + 2];

            int gray = round((coefficients[0] * red) + (coefficients[1]* green) + (coefficients[2]* blue));
            if (gray > 255) {
                gray = 255;
            }
            originalData[i][j] = gray;
            originalData[i][j + 1] = gray;
            originalData[i][j + 2] = gray;
        }
    }
  
    changedData.resize(RowMember);/*resizing changed data vector to the hold the new adjusted data*/
    for (int i = 0; i < RowMember; i++) {
        changedData[i].resize(ColMember * 3);
    }
    for(int i=0;i<RowMember;i++){
        for(int j=0;j<ColMember*3;j++){
            changedData[i][j]=originalData[i][j];/*assinging adjusted data to the changedData member vector variable*/
        }
    } 
    
 


    return 1;
}
int ImageEditor::SaveImage()
{
    if(!isImageOpened){/*if image is not opened returning -1*/
        return -1;
    }
    else{
            string newImageFile;/*getting file name*/
            cin >> newImageFile;
            ofstream outfile(newImageFile);/*creating new file*/
            outfile << format << endl;/*first line starts with format*/
            outfile << ColMember << " " << RowMember << endl;/*second line includes row and column number*/
            outfile << maxValueRgb << endl;/*third line includes maxValueOf rgb number*/
            for(int i=0;i<RowMember;i++){

                for(int j=0;j<ColMember*3;j++){

                    outfile<< changedData[i][j]<<" ";/* and the last lines is a source of pixel values of the colours*/
                }
             outfile << endl;
            } 
            return 1;
    }    
        
}

bool ImageEditor::ControlNumber(string enteredNumber)
{   
    bool charExistence=false;/*if char exists make it true*/
    int i=0;
    while(enteredNumber[i]!='\0')
    {
        int testIt;

        testIt=enteredNumber[i];/*store the indexes of enteredNumber string into variable as ASCII*/

        if( !(testIt >=48 && testIt<=57) ) /*if asci codes between these numbers make it false*/
        {
            charExistence=true;
            break;
        }
        else
        {
            i++;
            charExistence=false;
        } 
    }
    if(charExistence) 
        return false;
    else 
        return true;
}



  /*  // Open an image
                x=imageEditor.OpenFile();
                if(x==-1)
                {
                    cout << "Format is not supported"<< endl;
                    x=0;   
                };
                break; */