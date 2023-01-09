#include <fstream>
#include <iostream>
#include <iomanip>
#include<string>
#include<vector>

using namespace std;

void makeSlash(ofstream& oFile, int size, char c);
void makeEight(ofstream& oFile, int size, char c);
void makeTriangle(ofstream& oFile, int size, char c);
bool readRecord (ifstream& iFile, string& typeString, int& lSize, char& c);
void openInputFile(ifstream& iFile, string prompt);
bool openOutputFile(ofstream& oFile, string fname);
string createOutputFilename(string typeString, int labelSize);

int main(){
    ifstream iFile;
    ofstream oFile;
    string type, title;
    int size;
    char c;
    openInputFile(iFile, "AS8Data.txt");
    while(readRecord(iFile, type, size, c)){
        title = createOutputFilename( type, size);
        openOutputFile(oFile, title);
        if(type == "figureEight"){
            makeEight(oFile, size, c);
        }else if(type == "slash"){
            makeSlash(oFile, size, c);
        }else if(type == "triangle"){
            makeTriangle(oFile, size, c);
        }
        oFile.close();
    }
    iFile.close();
    return 0;
}

bool readRecord (ifstream& iFile, string& typeString, int& lSize, char& c){
    if(iFile.eof()){
        return false;
    }else{
        if(iFile.peek() == '\n'){
            iFile.ignore(100, '\n');
        }
        iFile >> typeString;
        iFile >> lSize;
        iFile >> c;
        return true;
    }
}

void openInputFile(ifstream& iFile, string prompt){
    iFile.open(prompt);
}
void makeTriangle(ofstream& oFile, int size, char c){
    
    int width = 2;
    int endLine = size *2;
    vector<vector<string>> vec;
    string str(1,c);
    oFile << "Symbol: Triangle\tSize: "<<size<<"\tCharacter: "<<c<<endl;
    


    // sets numbers at top, add 1 to end line for space 
    oFile << " " << "\t";
    for (int i = 1; i < endLine + 1; i++){
        oFile << i%10;
    }
    oFile << endl;
    oFile << endl;

bool openOutputFile(ofstream& oFile, string fname){
    oFile.open(fname);
    if (oFile.is_open()){
        return true;
    }else{
        return false;
    }
}

string createOutputFilename(string typeString, int labelSize){
    string filename;
    string labelSizeString;
    labelSizeString = to_string(labelSize);
    filename = typeString + "_" + labelSizeString + ".txt";
    return filename;
}
void makeSlash(ofstream& oFile, int size, char c)
{

    int countLength = size;
    int countWidth = 1;
    int collumSpaces = 1;
    int blankSpaces;

    //prints header with all info regarding shape being made 
    oFile << "Symbol: Slash   Size: " << size << "   Character:  '" << c << "''" << endl;

    //prints size header at the top of the screen
  oFile<<" "<<"\t";
    for (int j = 0; j < size; j++)
    {
        oFile << countWidth%10;
        countWidth++;
    }
    oFile << endl;

    //prints slash shape
    for (int i = 1; i <= size; i++)
    {
        oFile << i<<"\t";
        blankSpaces = size - i;
        
      for(int j = 0; j < blankSpaces; j++)
        {
          oFile<<" ";
        }
      oFile<< c << endl;

    }
  countWidth = 1;
    //prints size header at the top of the screen
    oFile<<" "<<"\t";
    for (int j = 0; j < size; j++)
    {
        oFile << countWidth%10;
        countWidth++;
    }
    oFile << endl;

}
