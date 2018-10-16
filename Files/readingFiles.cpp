#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    string inFileName = "test.txt";
    ifstream inFile;

    inFile.open(inFileName);

    if(inFile.is_open()){
        string line;
        //inFile >> line; - read till the first occurrence of white space
        //getline(inFile,line); - read only the first line

        // while(!inFile.eof()){
        while(inFile){ // power of operator overloading - do not have to call eof() function explicitly
            getline(inFile,line);
            cout << line << endl;
        }

        inFile.close();
    }
    else{
        cout << "Could not open the file : " << inFileName << endl;
    }

    return 0;
}