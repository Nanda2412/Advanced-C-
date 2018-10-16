#include <iostream>
#include <string>

#define DEFAULT 0

using namespace std;

class Test{
    int _id{3};
    string _name{"Nanda"};

public:
    // explicitly stating that we are using the default constructor, copy constructor and assignment operator
    Test() = default;
#if DEFAULT
    Test(const Test& other) = default;
    Test& operator=(const Test& other) = default;
#else
    // explicitly stating that the class is non copyable
    Test(const Test& other) = delete;
    Test& operator=(const Test& other) = delete;
#endif

    Test(int id) : _id(id){

    }
    void print() const{
        cout << _id << " : " << _name << endl;
    }
};

int main(int argc, char const *argv[])
{
    Test test;
    test.print();

    Test test1(6);
    test1.print();

#if DEFAULT
    Test test2 = test1; // default copy initialization gets invoked
    test2 = test; // default assignment gets invoked
#endif

    return 0;
}
