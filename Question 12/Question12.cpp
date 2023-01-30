#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
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
int searchForIngredient( vector<itemType> & oldList, string ingredient, bool printEnable );
void printRecord( itemType & item );
void sort(vector<itemType>& myList);

int numItems = 0;

int main(){
    ifstream inFile;
    vector<itemType> items;
    if(!openInputFile(inFile)){
        return 0;
    }
    readFile(inFile, items);
    cout << items.size() << " records read"<<endl;

    while(true){
        string input;
        cout << "*****************"<<endl<<"New Search"<<endl<<"Enter ingredient: ";
        cin >> input;
        if(input == "q"){
            return 0;
        }else{
            string showList;
            cout << "Searching for items containing "<<input << endl << "***********************"<< endl;
            cout << "Would you like to see a list of items with "<< input<<" as an ingredient? (y/Y)";
            cin >> showList;
            if(makeStringUpper(showList) == "Y"){
                cout << searchForIngredient(items, input, true );
            }else{
                cout << searchForIngredient(items, input, false );
            }

        }
    }
}

void readFile( ifstream & inFile, vector<itemType> &item){
    itemType temp;
    string line,
           current;
    while(!inFile.eof()){ // While there is still data left in the file
        getline(inFile, line, '\n'); // Get the next row of data
        int i = 0, 
            data = 0;//The current datatype that is being parsed
        while(getQuotedString(line, i, current)){ //While the current line of data still has data in it
            istringstream ss(current); //Create a string stream to handle any scientific notation
            switch(data){
                case 0:
                    ss >> temp.NBD_No;
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
                    ss >> temp.GTIN_UPC;
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
            }
        }
    temp.Ingredients = current;
    data++;
    temp.itemNumber = numItems;
    numItems++;
    item.push_back(temp);
    temp = itemType{};
    }
    cout << "-----------\n----End of File Reached----------";
    return;
}
bool openInputFile( ifstream & inFile ){
    cout << "Enter input File Name/(q-quit):";
    string fileName;
    cin >> fileName;
    if (fileName == "q")
    {
        return false;
    }else
    {
        inFile.open(fileName);
        cout << "File Opened Successfully";
        return true;
    }
}
bool getQuotedString( string& line, int &index, string & subString){
    size_t pos, posEnd;
    if(index == 0){
        posEnd = line.find(',', index);
        if(line[index] == '"'){
            subString = line.substr(index + 1, (posEnd - index - 1));
        }else{
            subString = line.substr(index, (posEnd - index));
        }
        index = posEnd+1;
        return true;
    }
    pos = index;
    if(line[pos] == '"'){
        index++;
        posEnd = line.find('"',pos+1);
    }else{
        posEnd = line.find(',', pos);
    }
    char c = line[posEnd];
    if(posEnd != string::npos){
        subString = line.substr(index, (posEnd - index ));
        char test = line[index];
        if(line[index-1] != '"'){
            index = posEnd+1;
        }else{
            index = posEnd+2;
        }
    }else{
            subString = line.substr(index, string::npos);
            index = line.length() + 1;
    }
    if(index <= line.length()-1){
        return true;
    }else{
        return false;
    }
}
bool findIngredient( itemType item, string ingredient){
    if(item.Ingredients.find(ingredient) > -1){
        return true;
    }else{
        return false;
    }
}
string makeStringUpper( string s){
    int length = s.length();
    for (int i = 0; i < length; i++) {
        int sindex = s[i];
        if (islower(sindex)){
            s[i] = toupper(sindex);
        }
    }
    return s;
}
int searchForIngredient( vector<itemType> & oldList, string ingredient, bool printEnable ){
    vector<itemType> foundList;
    int foundNum = 0;
    for(int i = 0; i < oldList.size();i++){
        if (findIngredient(oldList[i],makeStringUpper(ingredient)) == true){
            foundList.push_back(oldList[i]);
            foundNum++;
        }
    }
    if ( printEnable == true){
        for(int i = 0; i < foundList.size();i++){
            printRecord(foundList[i]);
        }
    }
    return foundNum;

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
