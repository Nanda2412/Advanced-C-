#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#pragma pack(push,1)
struct Person{
    char name[50];
    int age;
    double height;
};
#pragma pack(pop)

int main(){

    Person someone = {"Nanda",29,186};

    string filename = "test.bin";
    ofstream outFile;
    // Writing binary
    outFile.open(filename,ios::binary);

    if(outFile.is_open()){
        //outFile.write((char *)&someone,sizeof(Person));
        outFile.write(reinterpret_cast<char *>(&someone),sizeof(Person));
        outFile.close();
    }
    else{
        cout << "Could not open the file " + filename << endl;
    }

    Person someoneElse = {};
    ifstream inFile;
    // Reading binary
    inFile.open(filename,ios::binary);

    if(inFile.is_open()){
        //outFile.write((char *)&someone,sizeof(Person));
        inFile.read(reinterpret_cast<char *>(&someoneElse),sizeof(Person));
        inFile.close();
    }
    else{
        cout << "Could not open the file " + filename << endl;
    }

    cout << someoneElse.name << "," << someoneElse.age << "," << someoneElse.height << endl;

    return 0;
}