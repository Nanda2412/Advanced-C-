#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//Another STL skipped - deque : double ended queue
// push_back() and push_front() as well as pop_back() and pop_front()

class Test{
    int _id;
    string _name;

public:
    Test(int id,string name):_id(id),_name(name){

    }
    void print(){
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
    friend bool compare(const Test& a, const Test& b); // friend functions can access private attributes
};

bool compare(const Test& a, const Test& b){
    if(a._name == b._name){
        return a._id < b._id;
    }
    else{
        return a._name < b._name;
    }
}

int main(int argc, char const *argv[])
{
    vector<Test> testVector;

    testVector.push_back(Test(3,"Mike"));
    testVector.push_back(Test(12,"Sam"));
    testVector.push_back(Test(54,"Edwin"));
    testVector.push_back(Test(233,"Vincent"));

    //Two ways of sorting
    // 1. '<' operator overload
    // 2. define separate compare function

    sort(testVector.begin(),testVector.end());
    sort(testVector.begin(),testVector.end(),compare); 

    for(int i=0;i<testVector.size();i++){
        testVector[i].print();
    }

    return 0;
}
