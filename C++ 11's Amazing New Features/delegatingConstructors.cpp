#include <iostream>
#include <string>

using namespace std;

class Parent{
    int dogs{5};
    string text{"Hello"};

public:
    Parent() : Parent("Hi"){ // calling another constructor within constructor. Not supported in C++ 98
        cout << "No parameter constructor" << endl;
    }
    Parent(string text){
        cout << "String parameter constructor" << endl;
    }
};

class Child : public Parent{
public:
    Child() = default;
};

int main(int argc, char const *argv[])
{
    Parent parent1;
    Child child1;

    cout << endl;

    Parent parent2("Hi Nanda");
    Child child2;

    return 0;
}
