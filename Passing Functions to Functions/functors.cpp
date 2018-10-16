#include <iostream>
#include <string>

using namespace std;

struct Test{
    virtual bool operator()(string text) const = 0;
    virtual ~Test(){

    }
};

struct MatchTest : public Test{
    virtual bool operator()(string text) const{
        return text == "Nanda";
    }
};

void check(string text,const Test& testObj){
    if(testObj(text)){
        cout << "Match" << endl;
    }
    else{
        cout << "No Match" << endl;
    }
}

int main(int argc, char const *argv[])
{
    string text1 = "Nanda";
    string text2 = "Kavya";

    MatchTest pred;
    cout << pred(text1) << endl;

    check(text1,pred);
    check(text2,pred);
    
    return 0;
}
