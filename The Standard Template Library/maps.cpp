#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

    map<string,int> ages;

    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicky"] = 30;
    //ages["Mike"] = 50;

    cout << ages["Mike"] << endl;

    pair<string,int> addToMap("Peter",100);
    ages.insert(addToMap);
    ages.insert(pair<string,int>("Peter",100));
    ages.insert(make_pair("Peter",100));

    if(ages.find("Vicky") != ages.end()){
        cout << "Key found" << endl;
    }
    else{
        cout << "Key not found" << endl;
    }

    for(map<string,int>::iterator it = ages.begin(); it != ages.end(); it++){
        pair<string,int> nameAgePair = *it;

        cout << nameAgePair.first << " : " << nameAgePair.second << endl;
    }

    for(map<string,int>::iterator it = ages.begin(); it != ages.end(); it++){
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}