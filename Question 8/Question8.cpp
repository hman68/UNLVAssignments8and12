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
void outputChar(ofstream& oFile, int count, char outChar);
bool openOutputFile(ofstream& oFile, string fname);
string createOutputFilename(string typeString, int labelSize);

int main(){
    ifstream iFile;
    ofstream oFile;
    string type, title, file;
    int size;
    char c;
    cout << "Welcome to the Rebel Alliance Computational Support"<<endl;
    cout << "     ,    ,^.    .\n";
    cout << "   ,'|  _ \\ / _  |`.\n";
    cout << "  / /   `\\| |/,'  \\ \\\n";
    cout << " / :     `. ,'     : \\  \n";
    cout << ":  |      | |      |  :\n";
    cout << "|  :      ; :      ;  |\n";
    cout << ":   `.__,'   `.__,'   ;\n";
    cout << " \\                   /\n";
    cout << " \\                 /\n";
    cout << "  `.             ,'\n";
    cout <<"     `-._______,-'  SSt";
    cout << endl<<endl<<"Input Specification File: ";
    cin >> file;
    openInputFile(iFile, file);
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
    return 0;
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

    oFile << "Symbol: Figure Eight\tSize: "<<size<<"\tCharacter: "<<c<<endl;
    //Prints Column Count
    oFile << "\t";
    for(int i = 1; i <= size; i++){
        oFile<<i%10;
    }
    //Print the top row of the Figure Eight
    oFile << endl << setw(2) << right <<  count << "\t";
    outputChar(oFile, edgeWidth, ' ');
    outputChar(oFile, middleWidth, c);
    count++;

    //Print out the "vertical" rows of the top section of the Figure Eight
    for(int i = 0; i < section1Rows; i++){
        oFile << endl << setw(2) << right << count << "\t";
        outputChar( oFile, edgeWidth, c);
        outputChar( oFile, middleWidth, ' ');
        outputChar( oFile, edgeWidth, c);
        count++;
    }

    //Print the middle row of the Figure Eight
    oFile << endl << setw(2) << right << count << "\t";
    outputChar( oFile, edgeWidth, ' ');
    outputChar( oFile, middleWidth, c);
    count++;

    //Print out the "vertical" rows of the bottom section of the Figure Eight
    for(int i = 0; i < section2Rows; i++){
        oFile << endl << setw(2) << right << count << "\t";
        outputChar( oFile, edgeWidth, c);
        outputChar( oFile, middleWidth, ' ');
        outputChar( oFile, edgeWidth, c);
        count++;
    }

    //Print out the bottom row of the Figure Eight
    oFile << endl << setw(2) << right << count << "\t";
    outputChar( oFile, edgeWidth, ' ');
    outputChar( oFile, middleWidth, c);
    count++;

    oFile << endl << "\t";
    for(int i = 1; i <= size; i++){
        oFile<<i%10;
     }
}

void outputChar(ofstream& oFile, int count, char outChar){
    for(int i = 0; i < count; i++){
        oFile << outChar;
    }
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

    //to add numbers and tab, add 3 to endline, and 1 to size
    endLine +=3;
    size ++;
    for (int i = 1; i < size;i++){
        vector<string> vec2;
        for (int j =0; j <endLine-1; j++){
            if (j == 0){
                vec2.push_back(to_string(i));
            }else if (j == 1){
                vec2.push_back("\t");
            }else if(i == size -1){
                vec2.push_back(str);
            }else{
                int canvas = endLine -2;
                // canvas is new 0 starting point
                j-=2;
                // j is decreased so starting as if 0 point
                int row = i-1;
                int space_between = row * 2;
                int blank = ((canvas - space_between) / 2 )-2;
                if (j < blank){
                    vec2.push_back(" ");
                } else if(j>=blank && j < (blank+2)){
                    vec2.push_back(str);
                }else if (j >= (blank+2) && j< (blank+2+space_between)){
                    vec2.push_back(" ");
                }else if(j >=(blank+2+space_between) && j < (blank+4+space_between)){
                    vec2.push_back(str);
                }else if (j >= (blank+4+space_between) ){
                    vec2.push_back(" ");
                }
                j+=2;
                //starts us out back correctly
            }
        }
        vec.push_back(vec2);
    }
    for (int i = 0; i < vec.size(); i++){
        for (int j= 0; j < vec[i].size(); j++){
            oFile << vec[i][j];
        }
        oFile << endl;
    }

    oFile << endl;
    oFile << " " << "\t";
    for (int i = 1; i < endLine -2; i++){
        oFile << i%10;
    }
    oFile << endl;
    //same function like in start, sub 2 to counteract previous
}

bool openOutputFile(ofstream& oFile, string fname){
    oFile.open(fname);
    cout << "File \""<<fname<<"\" successfully opened"<<endl;
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
