#include <iostream>
#include <string>

using namespace std;

class Test{
    int _id;
    string _name;

public:
    Test():_id(0),_name(""){

    }
    Test(int id,string name):_id(id),_name(name){

    }
    Test(const Test &other){
        *this = other;
    }
    const Test &operator=(const Test &other){
        _id = other._id;
        _name = other._name;
        return *this;
    }
    friend ostream &operator<<(ostream &out,const Test &test){
        out << test._id << " : " << test._name;
        return out;
    }

    ~Test(){
        //Nothing to be done
    }
};

int main(int argc, char const *argv[])
{
    Test test1(10,"Mike");
    cout << test1 << endl;

    return 0;
}
