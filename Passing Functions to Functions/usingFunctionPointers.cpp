#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool match(string text){
    return text.size() == 3;
}

int countString(const vector<string>& texts, bool (*match)(string)){
    int count = 0;
    for(vector<string>::const_iterator it = texts.begin(); it != texts.end(); it++){
        if(match(*it)){
            count++;
        }
    }

    return count; 
}

int main(int argc, char const *argv[])
{
    vector<string> stringVector;

    stringVector.push_back("one");
    stringVector.push_back("two");
    stringVector.push_back("three");
    stringVector.push_back("four");
    stringVector.push_back("five");
    stringVector.push_back("six");
    stringVector.push_back("seven");
    stringVector.push_back("eight");
    stringVector.push_back("nine");
    stringVector.push_back("ten");

    cout << "Std Lib algorithm : " << count_if(stringVector.begin(),stringVector.end(),match) << endl;
    cout << "Custom algorithm : " << countString(stringVector,match) << endl;
    
    return 0;
}
