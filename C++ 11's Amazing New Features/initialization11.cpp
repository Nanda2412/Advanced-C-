#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s{"Nanda"};
    cout << s << endl;

    int values[]{2,4,5,7,8,9};
    cout << values[1] << endl;

    int* pInteger = new int[3]{3,6,9};
    cout << pInteger[2] << endl;
    delete [] pInteger;

    int* pAnotherInteger{}; // equivalent to initializing 'pAnotherInteger' to 'nullptr'
    cout << pAnotherInteger << endl;

    int anotherSetofValues[6]{};
    cout << anotherSetofValues[3] << endl;

    struct {
        int id;
        string text;
    }s1{27,"Kavya"};

    cout << s1.text << endl;

    vector<string> strings{"one","two","three"};

    for(auto s : strings){
        cout << s << endl;
    }


    return 0;
}
