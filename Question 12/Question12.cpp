#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct itemType {
    unsigned int NBD_No;
    string Long_Name;
    string Data_Source;
    unsigned long GTIN_UPC;
    string Manufacturer;
    string Date_Modified;
    string Date_Available_Date;
    string Ingredients;
};

void readFile( ifstream & inFile, vector<itemType> &item);
bool openInputFile( ifstream & inFile );
bool getQuotedString( string& line, int &index, string & subString);
bool findIngredient( itemType item, string ingredient);
string makeStringUpper( string s);
int searchForIngredient( vector<itemType> & itemType, string ingredient, bool printEnable );
void printRecord( itemType & item );
void sort(vector<itemType>& myList);



int main(){

}
void readFile( ifstream & inFile, vector<itemType> &item){

}
bool openInputFile( ifstream & inFile ){

}
bool getQuotedString( string& line, int &index, string & subString){

}
bool findIngredient( itemType item, string ingredient){

}
string makeStringUpper( string s){

}
int searchForIngredient( vector<itemType> & itemType, string ingredient, bool printEnable ){

}
void printRecord( itemType & item ){

}
void sort(vector<itemType>& myList){
    
}
