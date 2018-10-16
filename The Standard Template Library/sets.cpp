#include <iostream>
#include <string>
#include <set>

using namespace std;

class Test{
    int _id;
    string _name;

public:
    Test():_id(0),_name(""){

    }
    
    Test(int id, string name) : _id(id), _name(name){

    }

    void print() const{
        cout << _id << " : " << _name << endl;
    }

    bool operator<(const Test& other) const{

        if(_name == other._name){
            return _id < other._id;
        }
        else{
            return _name < other._name;
        }
    }
};

int main(int argc, char const *argv[])
{
    set<int> numbers;

    numbers.insert(30);
    numbers.insert(20);
    numbers.insert(50);
    numbers.insert(10);
    numbers.insert(50);

    for(set<int>::iterator it = numbers.begin(); it != numbers.end(); ++it){
        cout << *it << endl;
    }

    set<int>::iterator itFind = numbers.find(30);

    if(itFind != numbers.end()){
        cout << "Found : " << *itFind << endl;
    }
    else{
        cout << "Not Found" << endl;
    }

    if(numbers.count(50)){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }

    //Custom element
    set<Test> tests;

    tests.insert(Test(30,"Mike"));
    tests.insert(Test(30,"Mike"));
    tests.insert(Test(10,"Mike"));
    tests.insert(Test(30,"Sam"));
    tests.insert(Test(40,"Ram"));
    tests.insert(Test(50,"Jose"));

    for(set<Test>::iterator it = tests.begin(); it != tests.end(); ++it){
        it->print();
    }

    set<Test>::iterator itFind1 = tests.find(Test(50,"Jose"));

    if(itFind1 != tests.end()){
        itFind1->print();
    }
    else{
        cout << "Not Found" << endl;
    }

    if(tests.count(Test(10,"Mike"))){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }

    return 0;
}
