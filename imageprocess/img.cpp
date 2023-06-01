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
        ImageEditor(){};/*default constructor no parameters*/
        ImageEditor(string filePath);
        ImageEditor(int row,int column);

        int OpenFile(string filePath); /*member function to open a file*/
        int ConvertToGreyScale();/*convert function to converting greyscale for file*/
        int SaveImage(string fileName) const;/*saving image if the file opened*/
        int GetPixelInfo(int iRow, int iColumn,int iColour) const;
        int GetColumn()const;
        int GetRow()const;
        

        void ChangePixels(int iRow, int iColumn,int iColour,int value);
        void GetDimensions();/*getting dimension*/
        void GetImageData();

        bool ControlNumber(string text);/*controlling input in a situation of char existance*/
        bool GetCharExistence(){
            return charExist;
        }
   
        int& operator () (int iRow, int iColumn,int iColour);/*overloading operator () returns reference to the index*/
        friend ImageEditor operator + (ImageEditor &image1, ImageEditor &image2);/*overloading +  operator retursn ImageEditor object*/
        friend ImageEditor operator - (ImageEditor &image1, ImageEditor &image2);/*overloading -  operator retursn ImageEditor object*/
        friend ostream& operator << (ostream &outputStream ,const ImageEditor &image);/*overloading stream  operator returns Stream reference object*/
       
        
        
    private:    
        string ImageFileName,format="P3";/*string format and ImageFileName variables*/
        bool isImageOpened=true,charExist;/*if the file open makes it true just a control variable*/
        int RowMember,ColMember,maxValueRgb;/*Rowmember and colmember just hold the pixel data of releated objects, and max value of rgb is the 255 */
        vector<vector<int>> changedData,originalData;/*pixel data for original data and greyscaled data of image */
};      /*boş olmasını kontrol et bi ara*/

/*test functions*/
int read_ppm(const string source_ppm_file_name, ImageEditor& destination_object);
int write_ppm(const string destination_ppm_file_name, const ImageEditor& source_object);
int test_addition(const string filename_image1, const string filename_image2, const string filename_image3);
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3);
int test_print(const string filename_image1);
int swap_channels(ImageEditor& image_object_to_be_modified, int swap_choice);
ImageEditor single_color(ImageEditor& source, int color_choice) ;

int main(int argc, char** argv)
{
    // Check for number of command line arguments
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <choice_number> <ppm_file_name1> [<ppm_file_name2> <ppm_file_name3>]" << std::endl;
        return 1;
    }

    // Get the choice number
    int choice = std::atoi(argv[1]);

    // Get the input file name
    std::string input_file_name = argv[2];

    // Check the existence of the optional arguments
    std::string output_file_name1, output_file_name2;
    if (argc >= 4) {
        output_file_name1 = argv[3];
    }
    if (argc >= 5) {
        output_file_name2 = argv[4];
    }

    switch (choice) {
        case 1:
            if (output_file_name1.empty() || output_file_name2.empty()) {
                std::cerr << "Error: Output file names are missing" << std::endl;
                return 1;
            }
            if(test_addition(input_file_name, output_file_name1, output_file_name2)==-1){
                cerr << "Hata" << endl;
                return 0;
            }
            break;
        case 2:
            if (output_file_name1.empty() || output_file_name2.empty()) {
                std::cerr << "Error: Output file names are missing" << std::endl;
                return 1;
            }
            if(test_subtraction(input_file_name, output_file_name1, output_file_name2)==-1){
                cerr << "Hata" << endl;
                return 0;
            }
            break;
        case 3:
            {
                ImageEditor obj;
                if(read_ppm(input_file_name,obj)==0){
                    cerr <<"Hata" << endl;
                    return 0;
                }
                else {
                swap_channels(obj,2);
                write_ppm(output_file_name1,obj);
                }
            }
            break;
        case 4:
            {
                ImageEditor image ;
                if(read_ppm(input_file_name,image)==0){
                    cerr << "Hata"<< endl;
                    return 0;
                }
                else{
                    swap_channels(image,3);
                    write_ppm(output_file_name1,image);
                }
                
            }
            break;
        case 5:
            {
                ImageEditor image1; 
                if(read_ppm(input_file_name,image1)==0){
                    cerr << "Hata" << endl;
                    return 0;
                }
                else {
                    ImageEditor red_channel = single_color(image1, 1);
                    write_ppm(output_file_name1,red_channel);
                }
                
            }
            break;
        case 6:
            {
                ImageEditor image2; 
                if(read_ppm(input_file_name,image2)==0){
                    cerr << "Hata" <<endl;
                }
                else{
                    ImageEditor green_channel = single_color(image2, 2);
                    write_ppm(output_file_name1,green_channel);
                }
            }
            break;
        case 7:
            {
                ImageEditor image3;
                if(read_ppm(input_file_name,image3)==0){
                    cerr << "Hata" << endl;
                }
                else{
                    ImageEditor blue_channel = single_color(image3, 3);
                    write_ppm(output_file_name1,blue_channel );
                }
               
            }
            break;
        default:
            std::cerr << "Error: Invalid choice number" << std::endl;
            return 1;
    }

    return 0;
}

int ImageEditor::OpenFile(string filePath){   
    
    ImageFileName=filePath;/*getting file name*/

    string text,temp;
    int count=1,rowPlace=0,columnPlace=0;
    int found,column=0,row=0;

    ifstream OpenedFile(ImageFileName);

    stringstream stringToParse;


    getline(OpenedFile,text); /*getting first line of the file*/
    format=text;/*assigned it in format member variable of the class*/

    if(text!="P3"){
        charExist=true;
        return -1;
    }
        
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
            if(!checkNum){
                charExist=true;
                return -1;
            }
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

int ImageEditor::ConvertToGreyScale(){   
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

int ImageEditor::SaveImage(string fileName) const{
    if(!isImageOpened){/*if image is not opened returning -1*/
        return -1;
    }
    else{
            string newImageFile=fileName;/*getting file name*/
            //cin >> newImageFile;
            ofstream outfile(newImageFile);/*creating new file*/
            outfile << format << endl;/*first line starts with format*/
            outfile << ColMember << " " << RowMember << endl;/*second line includes row and column number*/
            outfile << maxValueRgb << endl;/*third line includes maxValueOf rgb number*/
            for(int i=0;i<RowMember;i++){

                for(int j=0;j<ColMember*3;j++){
                    //outfile<< changedData[i][j]<<" ";/* and the last lines is a source of pixel values of the colours*/
                    outfile<< originalData[i][j]<<" ";
                }
             outfile << endl;
            } 
            return 1;
    }    
        
}

bool ImageEditor::ControlNumber(string enteredNumber){   
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

ImageEditor::ImageEditor(string filePath){
    if(OpenFile(filePath)==-1){
        cerr << "Error" << endl;
    };
}

ImageEditor::ImageEditor(int row,int column){/*constructing image with row and column*/

    ImageFileName="P3";
    RowMember=row;
    ColMember=column;
    maxValueRgb=255;
    isImageOpened=true;

    originalData.resize(row);
    for (int i = 0; i < row; i++) {
        originalData[i].resize(column * 3);
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<column*3;j++){
            originalData[i][j]=0;
        }
    }


}

void ImageEditor::GetDimensions(){/*returning dimensions*/
    cout << RowMember << " " << ColMember << endl;
}

int ImageEditor::GetPixelInfo(int iRow,int iColumn,int iColour) const  {/*returns pixel info*/

    return originalData[iRow-1][iColumn*3-3+iColour-1];
}

void ImageEditor::ChangePixels(int iRow, int iColumn,int iColour,int value){/*changes the index of pixel*/
    originalData[iRow-1][iColumn*3-3+iColour-1]=value;
}

ImageEditor operator + (ImageEditor &image1, ImageEditor &image2){

    if( (image1.RowMember==image2.RowMember) && (image1.ColMember==image2.ColMember) ){

        ImageEditor summedImage;
        summedImage.RowMember=image1.RowMember;
        summedImage.ColMember=image1.ColMember;
        summedImage.originalData.resize(image1.RowMember);

        for (int i = 0; i < image1.RowMember; i++) {
            summedImage.originalData[i].resize(image1.ColMember * 3);
        }
        summedImage.maxValueRgb=255;
        summedImage.isImageOpened=true;

        for(int i=0;i<image1.RowMember;i++){
            for(int j=0;j<image1.ColMember*3;j++){
                int sum=image1.originalData[i][j] + image2.originalData[i][j];
                if(  sum<=255 ){
                    summedImage.originalData[i][j]=sum;
                }
                else    
                    summedImage.originalData[i][j]=255;
            }
        }

        return summedImage;

    }
    else
        return ImageEditor(0,0);
}

ImageEditor operator - (ImageEditor &image1, ImageEditor &image2){
    if( (image1.RowMember==image2.RowMember) && (image1.ColMember==image2.ColMember) ){

        ImageEditor substractedImage;
        substractedImage.RowMember=image1.RowMember;
        substractedImage.ColMember=image1.ColMember;
        substractedImage.originalData.resize(image1.RowMember);

        for (int i = 0; i < image1.RowMember; i++) {
            substractedImage.originalData[i].resize(image1.ColMember * 3);
        }
        substractedImage.maxValueRgb=255;
        substractedImage.isImageOpened=true;
        for(int i=0;i<image1.RowMember;i++){
            for(int j=0;j<image1.ColMember*3;j++){
                int sum=image1.originalData[i][j] - image2.originalData[i][j];
                if(  sum<0){
                    substractedImage.originalData[i][j]=sum;
                }
                else    
                    substractedImage.originalData[i][j]=0;
            }
        }

        return substractedImage;

    }
    else
        return ImageEditor(0,0);
}

ostream& operator << (ostream &outputStream ,const ImageEditor &image){
    cout << image.format << endl;/*first line starts with format*/
    cout << image.ColMember << " " << image.RowMember << endl;/*second line includes row and column number*/
    cout << image.maxValueRgb << endl;/*third line includes maxValueOf rgb number*/
    for(int i=0;i<image.RowMember;i++){

        for(int j=0;j<image.ColMember*3;j++){
                    //outfile<< changedData[i][j]<<" ";/* and the last lines is a source of pixel values of the colours*/
                    cout<< image.originalData[i][j]<<" ";
                }
        cout << endl;
    }
    return outputStream;
}

int & ImageEditor::operator () (int iRow, int iColumn,int iColour){
  
    return originalData[iRow-1][iColumn*3-3+iColour-1];
}

int read_ppm(const string source_ppm_file_name, ImageEditor& destination_object){
    
    int Control=destination_object.OpenFile(source_ppm_file_name);

        if(Control==-1){
            return 0;
        }
        else    
            return 1;
}

int write_ppm(const string destination_ppm_file_name, const ImageEditor& source_object) {

    int control=source_object.SaveImage(destination_ppm_file_name);
    
        if(control==-1){
            return 0;
        }
        else    
            return 1;
}

int test_addition(const string filename_image1, const string filename_image2, const string filename_image3){
    ImageEditor obj1(filename_image1);
    ImageEditor obj2(filename_image2);
    if(obj1.GetCharExistence() || obj2.GetCharExistence()){
        return -1;
    }
    ImageEditor obj3=obj1+obj2;
    if(obj3.GetColumn()==0 || obj3.GetRow()==0){
        return -1;
    }
    else 
    {
        obj3.SaveImage(filename_image3);
        return 1;
    }
}
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3){
    ImageEditor obj1(filename_image1);
    ImageEditor obj2(filename_image2);
    if(obj1.GetCharExistence() || obj2.GetCharExistence()){
        return -1;
    }
    ImageEditor obj3=obj1-obj2;
    if(obj3.GetColumn()==0 || obj3.GetRow()==0){
        return -1;
    }
    else {
        obj3.SaveImage(filename_image3);
        return 1;
    }
   
}
int test_print(const string filename_image1){
    ImageEditor obj(filename_image1);
    if(obj.GetCharExistence()){
        return 0;
    }
    if(obj.GetRow()== 0 || obj.GetColumn()==0){
        return 0;
    }
    else{
        cout << obj;
        return 1;
    }

}

int ImageEditor::GetColumn()const{/*returning col member of the private data*/
    return ColMember;
}
int ImageEditor::GetRow()const{/*returning row member of the private data*/
    return RowMember;
}

int swap_channels(ImageEditor& image_object_to_be_modified, int swap_choice){
        int x;
        if(image_object_to_be_modified.GetRow()== 0 || image_object_to_be_modified.GetColumn()==0){
            return 0;
        }
        else {

            for(int i=1;i<=image_object_to_be_modified.GetRow();i++){
                        for(int j=1;j<=image_object_to_be_modified.GetColumn();j++){
                            
                                switch(swap_choice)
                                {
                                    case 1:
                                        x=image_object_to_be_modified(i,j,1);
                                        //printf("%d",x);
                                        /*returns reference() overload and assignin it to to change pixels to make the changes*/
                                        image_object_to_be_modified.ChangePixels(i,j,1,image_object_to_be_modified(i,j,2));
                                        image_object_to_be_modified.ChangePixels(i,j,2,x);
                                        break;
                                    case 2:
                                        x=image_object_to_be_modified(i,j,1);
                                         /*returns reference() overload and assignin it to to change pixels to make the changes*/
                                        image_object_to_be_modified.ChangePixels(i,j,1,image_object_to_be_modified(i,j,3));
                                        image_object_to_be_modified.ChangePixels(i,j,3,x);
                                        break;
                                    case 3:
                                        x=image_object_to_be_modified(i,j,2);
                                         /*returns reference() overload and assignin it to to change pixels to make the changes*/
                                        image_object_to_be_modified.ChangePixels(i,j,2,image_object_to_be_modified(i,j,3));
                                        image_object_to_be_modified.ChangePixels(i,j,3,x);
                                        break;
                                    default:
                                        break;
                                }
                        }
                    }
                    return 1;
        }
        
}

ImageEditor single_color( ImageEditor& source, int color_choice)  {
    ImageEditor newImage(source.GetRow(),source.GetColumn());
    if(newImage.GetColumn()== 0 || newImage.GetRow()==0 ){
        return ImageEditor(0,0);
    }
    else {
        for(int i=1;i<=newImage.GetRow();i++){
            for(int j=1;j<=newImage.GetColumn();j++){
                switch(color_choice)
                {
                    case 1:
                    /*assignin new color pixel to the newImage originalData using () operator overload*/
                        newImage(i,j,1)=source.GetPixelInfo(i,j,1);
                        break;
                    case 2:
                    /*assignin new color pixel to the newImage originalData using () operator overload*/
                        newImage(i,j,2)=source.GetPixelInfo(i,j,2);
                        break;
                    case 3:
                    /*assignin new color pixel to the newImage originalData using () operator overload*/
                        newImage(i,j,3)=source.GetPixelInfo(i,j,3);
                        break;
                    default:
                        break;
                }
            }
        } 
        return newImage;
        }
}

void ImageEditor::GetImageData(){/*printing image data like the writing to the file*/
    for(int i=0;i<RowMember;i++){
        for(int j=0;j<ColMember;j++){
            cout << originalData[i][j] << " ";
        }
        cout << endl;
    }
}
