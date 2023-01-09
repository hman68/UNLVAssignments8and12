#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void makeSlash(ofstream& oFile, int size, char c);
void makeEight(ofstream& oFile, int size, char c);
void makeTriangle(ofstream& oFile, int size, char c);
void outputChar(ofstream& oFile,  int count, char outChar);


int main(){
    ofstream outFile;
    makeEight(outFile, 31, 'A');
}


void makeEight(ofstream& oFile, int size, char c){
    //All variables are assigned as detailed in the instructions
    int edgeWidth = size/10; // The width of the "sides" of the Figure Eight
    if(edgeWidth < 2){ 
        edgeWidth = 2;
    }
    int specialRowCount = edgeWidth/2; // Determine the width of the top, middle, and bottom rows
    int middleWidth = (size - (2*edgeWidth));//The number of spaces between the two vertical "sides" of the figure
    int section1Rows = (size-(specialRowCount * 3)) / 2;//The number of rows in the top of the figure eight
    int section2Rows = section1Rows; //The number of rows in the bottom of the figure eight
    int count = 1;//Current row being printed
    if((specialRowCount * 3) + section1Rows + section2Rows != size){//If there are not enough rows, add one to the bottom section
        section2Rows++;
    }

    cout << "Symbol: Figure Eight\tSize: "<<size<<"\tCharacter: "<<c<<endl;
    //Prints Column Count
    cout << "\t";
    for(int i = 1; i <= size; i++){
        cout<<i%10;
    }
    //Print the top row of the Figure Eight
    cout << endl << setw(2) << right <<  count << "\t";
    outputChar(oFile, edgeWidth, ' ');
    outputChar(oFile, middleWidth, c);
    count++;

    //Print out the "vertical" rows of the top section of the Figure Eight
    for(int i = 0; i < section1Rows; i++){
        cout << endl << setw(2) << right << count << "\t";
        outputChar( oFile, edgeWidth, c);
        outputChar( oFile, middleWidth, ' ');
        outputChar( oFile, edgeWidth, c);
        count++;
    }

    //Print the middle row of the Figure Eight
    cout << endl << setw(2) << right << count << "\t";
    outputChar( oFile, edgeWidth, ' ');
    outputChar( oFile, middleWidth, c);
    count++;

    //Print out the "vertical" rows of the bottom section of the Figure Eight
    for(int i = 0; i < section2Rows; i++){
        cout << endl << setw(2) << right << count << "\t";
        outputChar( oFile, edgeWidth, c);
        outputChar( oFile, middleWidth, ' ');
        outputChar( oFile, edgeWidth, c);
        count++;
    }

    //Print out the bottom row of the Figure Eight
    cout << endl << setw(2) << right << count << "\t";
    outputChar( oFile, edgeWidth, ' ');
    outputChar( oFile, middleWidth, c);
    count++;
}

void outputChar(ofstream& oFile, int count, char outChar){
    for(int i = 0; i < count; i++){
        cout << outChar;
    }
}