#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct itemType {
    int itemNumber;
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

int numItems = 0;

int main(){

}

void readFile( ifstream & inFile, vector<itemType> &item){
    itemType temp;
    string line,
           current;
    while(!inFile.eof()){ // While there is still data left in the file
        getline(inFile, line, '\n'); // Get the next row of data
        int i = 0, 
            data = 0;//The current datatype that the 
        while(getQuotedString(line, i, current)){ //While the current line of data still has data in it
            switch(data){
                case 0:
                    temp.NBD_No = stoi(current);
                    break;
                case 1:
                    temp.Long_Name = current;
                    break;
                case 2:
                    temp.Data_Source = current;
                    break;
                case 3:
                    temp.GTIN_UPC = stol(current);
                    break;
                case 4:
                    temp.Manufacturer = current;
                    break;
                case 5:
                    temp.Date_Modified = current;
                    break;
                case 6:
                    temp.Date_Available_Date = current;
                    break;
                case 7:
                    temp.Ingredients = current;
                    break;
            }
        }
    temp.itemNumber = numItems;
    numItems++;
    item.push_back(temp);
    temp = itemType{};
    }

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
    cout << "Item # " << item.NDB_No<< endl;
    cout << setprecision(14) << fixed();
    cout << "Name:" << item.Long_Name << endl;
    cout << "Manufacturer:" << item.Manufacturer<< endl;
    cout << "UPC:" << item.GTIN_UPC<< endl;
    cout << "Ingredients:" << item.Ingredients<< endl;
}
void sort(vector<itemType>& myList){
    bool bubble = true;
    while (bubble){
        bubble = false;
        for (size_t i = 0; i < myList.size() - 1; i++){
            if (myList[i].GTIN_UPC > myList[i+1].GTIN_UPC){
                myList[i].GTIN_UPC += myList[i+1].GTIN_UPC;
                myList[i+1].GTIN_UPC = myList[i].GTIN_UPC - myList[i+1].GTIN_UPC;
                myList[i].GTIN_UPC -= myList[i+1].GTIN_UPC;
                bubble = true;
            }
        }
    }
}
