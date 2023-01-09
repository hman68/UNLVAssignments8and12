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
