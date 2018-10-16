#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    //ofstream outFile;
    fstream outFile;
    string outFilename = "text.txt";

    //outFile.open(outFilename);
    outFile.open(outFilename,ios::out);

    if(outFile.is_open()){
        outFile << "Hello" << endl;
        outFile << 123 << endl;
        outFile.close();
    }
    else{
        cout << "Could not open : " << outFilename << endl;
    }

    return 0;
}