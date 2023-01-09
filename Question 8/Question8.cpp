#include <fstream>
#include <iostream>
#include<string>
#include<vector>

using namespace std;

void makeSlash(ofstream& oFile, int size, char c);
void makeEight(ofstream& oFile, int size, char c);
void makeTriangle(ofstream& oFile, int size, char c);

int main(){
<<<<<<< HEAD

=======
   
    
>>>>>>> 75cba86b410961b92ecc51482a8e39721bb8d06f
}
void makeTriangle(ofstream& oFile, int size, char c){
    
    int width = 2;
    int endLine = size *2;
    vector<vector<string>> vec;
    string str(1,c);
    


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
