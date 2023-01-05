#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void makeSlash(ofstream& oFile, int size, char c);
void makeEight(ofstream& oFile, int size, char c);
void makeTriangle(ofstream& oFile, int size, char c);
void printCharacters(char c, int num);

int main(){
    ofstream outFile;
    outFile.open("test.txt");
    makeEight(outFile, 12, 'A');
}


void makeEight(ofstream& oFile, int size, char c){
    int edgeWidth = size/10;
    if(edgeWidth < 2){
        edgeWidth = 2;
    }
    int specialRowCount = edgeWidth/2;
    int middleWidth = (size - (2*edgeWidth));
    int section1Rows = (size-(specialRowCount * 3)) / 2;
    int section2Rows = section1Rows;
    int count = 1;
    if((specialRowCount * 3) + section1Rows + section2Rows != size){
        section2Rows++;
    }

    cout << "\t";
    for(int i = 1; i <= size; i++){
        cout<<i%10;
    }
    cout << endl << setw(2) << right <<  count << "\t";
    printCharacters(' ', edgeWidth);
    printCharacters(c, middleWidth);
    count++;
    for(int i = 0; i < section1Rows; i++){
        cout << endl << setw(2) << right << count << "\t";
        printCharacters(c, edgeWidth);
        printCharacters(' ', middleWidth);
        printCharacters(c, edgeWidth);
        count++;
    }
    cout << endl << setw(2) << right << count << "\t";
    printCharacters(' ', edgeWidth);
    printCharacters(c, middleWidth);
    count++;
    for(int i = 0; i < section2Rows; i++){
        cout << endl << setw(2) << right << count << "\t";
        printCharacters(c, edgeWidth);
        printCharacters(' ', middleWidth);
        printCharacters(c, edgeWidth);
        count++;
    }
    cout << endl << setw(2) << right << count << "\t";
    printCharacters(' ', edgeWidth);
    printCharacters(c, middleWidth);
    count++;
}

void printCharacters(char c, int num){
    for(int i = 0; i < num; i++){
        cout << c;
    }
}