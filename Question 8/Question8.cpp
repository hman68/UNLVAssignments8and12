#include <fstream>
#include <iostream>

using namespace std;

void makeSlash(ofstream& oFile, int size, char c);
void makeEight(ofstream& oFile, int size, char c);
void makeTriangle(ofstream& oFile, int size, char c);

int main(){

}


void makeEight(ofstream& oFile, int size, char c){
    int edgeWidth = size/10;
    if(edgeWidth < 2){
        edgeWidth = 2;
    }
    int specialRowCount = edgeWidth/2;
    int section1Rows = size-(specialRowCount * 3) / 2;
    int section2Rows = section1Rows;
    if((specialRowCount * 3) + section1Rows + section2Rows != size){
        section2Rows++;
    }

    cout << section2Rows;
}
