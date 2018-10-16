#include <iostream>
#include <string>

using namespace std;

class Parent{
private:
    int _one;

public:
    Parent(): _one(0){

    }
    Parent(const Parent& other){
        cout << "copy parent " << endl;
        _one = other._one;
    }
    virtual void print(){
        cout << "Print Parent " << endl;
    }

    virtual ~Parent(){ // Once you have any virtual function in the class never forget to 
                       // declare the destructor as virtual
    }
};

class Child : public Parent{
private:
    int _two;

public:
    void print(){
        cout << "Print Child " << endl;
    }
};

int main(int argc, char const *argv[])
{
    Child c1;
    Parent &p1 = c1;
    p1.print(); // virtual keyword plays the trick of doing the lookup to confirm which object the base pointer is holding
                // if the function is not declared as virtual irrespective of which object address the base pointe is holding 
                //the function called will be from the base class since the compiler has no mechanism in place for lookup

    Parent p2 = Child(); // Object slicing - discard the child members, basically this is an upcast operation
    p2.print();         

    return 0;
}
