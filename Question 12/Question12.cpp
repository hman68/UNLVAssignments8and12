#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct itemType {
    int itemNumber;
    unsigned int NBD_No;
    string Long_Name;
    string Data_Source;
    unsigned long long int GTIN_UPC;
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
    ifstream inFile;
    inFile.open("ProductsC.csv");
    inFile.ignore(2e+13, '\n');
    vector<itemType> items;
    readFile(inFile, items);
    for(itemType i : items){
        printRecord(i);
    }
}

void readFile( ifstream & inFile, vector<itemType> &item){
    itemType temp;
    string line,
           current;
    while(!inFile.eof()){ // While there is still data left in the file
        getline(inFile, line, '\n'); // Get the next row of data
        cout << line;
        int i = 0, 
            data = 0;//The current datatype that the 
        while(getQuotedString(line, i, current)){ //While the current line of data still has data in it
            cout << current;
            switch(data){
                case 0:
                    temp.NBD_No = stoi(current);
                    data++;
                    break;
                case 1:
                    temp.Long_Name = current;
                    data++;
                    break;
                case 2:
                    temp.Data_Source = current;
                    data++;
                    break;
                case 3:
                    temp.GTIN_UPC = stoll(current);
                    data++;
                    break;
                case 4:
                    temp.Manufacturer = current;
                    data++;
                    break;
                case 5:
                    temp.Date_Modified = current;
                    data++;
                    break;
                case 6:
                    temp.Date_Available_Date = current;
                    data++;
                    break;
                case 7:
                    temp.Ingredients = current;
                    data++;
                    break;
            }
        }
    temp.itemNumber = numItems;
    cout << numItems;
    numItems++;
    item.push_back(temp);
    temp = itemType{};
    }

}
bool openInputFile( ifstream & inFile ){
    return false;
}
bool getQuotedString( string& line, int &index, string & subString){
    size_t pos, posEnd;
    if(index == 0){
        posEnd = line.find(',', index);
        //cout << posEnd << line[posEnd];
        if(line[index] == '"'){
            subString = line.substr(index + 1, (posEnd - index - 1));
        }else{
            subString = line.substr(index, (posEnd - index));
        }
        index = posEnd+1;
        return true;
    }
    pos = index;
    //cout << pos << line[pos];
    if(line[pos+1] == '"'){
        index++;
        posEnd = line.find('"',pos+1);
    }else{
        posEnd = line.find(',', pos);
    }
    //cout << posEnd << line[posEnd];
    if(pos != string::npos){
        subString = line.substr(index, (posEnd - index ));
        index = posEnd+1;
    }
    if(index != line.length()){
        return true;
    }else{
        return false;
    }
}
bool findIngredient( itemType item, string ingredient){
 return false;
}
string makeStringUpper( string s){
    return s;
}
int searchForIngredient( vector<itemType> & itemType, string ingredient, bool printEnable ){
    return 0;
}
void printRecord( itemType & item ){
    cout << "Item # " << item.NBD_No<< endl;
    cout << setprecision(14) << fixed;
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
