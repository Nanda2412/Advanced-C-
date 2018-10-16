#include <iostream>
#include <string>

using namespace std;

class Test{
    int _id;
    string _name;

public:
    Test():_id(0),_name(""){

    }
    Test(int id, string name):_id(id),_name(name){

    }
    Test(const Test &other){
        cout << "Copy constructor running..." << endl;
        _id = other._id;
        _name = other._name;
    }
    // Passing a const ref helps in avoiding additional copy and avoid data corruption
    // returning a ref helps to aviod additional copy during operator chaining. Making it const avoids situations like (a=b)=c
    // But above mentioned chaining works for primitive types so generally it should work for user defined data types as well but if we have a
    // strong reson to avoid such statements from occuring return const ref
    // Generally once you return left hand side object it's common to return by reference since it avoids extra copy during chaining operation.
    // But for '+' operator usually we return by value since addition gives out a new result and it's not okay to pass that result as reference.
    const Test &operator=(const Test &other){
        cout << "Assignment operator running..." << endl;
        _id = other._id;
        _name = other._name;

        return *this;
    }
    void print(){
        cout << _id << " : " << _name << endl;
    }
};

int main(int argc, char const *argv[])
{
    Test test1(10,"Mike");
    cout << "Print test1:" << flush;
    test1.print();

    Test test2(20,"Bob");

    test2 = test1;
    cout << "Print test2:" << flush;
    test2.print();

    Test test3;
    //test3 = test2 = test1; // Possible
    test3.operator=(test2); // Another way of calling assignment operator
    cout << "Print test3:" << flush;
    test3.print();

    Test test4 = test2; // Copy constructor will be called - copy initialization
    cout << "Print test4:" << flush;
    test4.print();

    //(test1 = test2) = test3; returning const ref from assignment operator enforces avoiding these kinds of statements.

    return 0;
}
