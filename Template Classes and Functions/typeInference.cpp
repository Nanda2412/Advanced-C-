#include <iostream>
#include <string>

using namespace std;

template<class T>
void print(T n){
    cout << "Template version : " << n << endl;
}

void print(int value){
    cout << "Non template version : " << value << endl;
}

// Example showing how to enforce the type declaration inside the '<>'(diamond) operator
template<class T>
void show(){
    cout << "Called the constructor of the specified type : " << T() << endl;
}

int main(int argc, char const *argv[])
{
    print<string>("Good Evening!!!");
    print<int>(6);

    print(2); // Function overloading

    print<>(10); // Type inference - type has been deduced from the argument passed

    // Type can't be inferred/deduced without explicitly mentioning the type
    show<double>();//Can't call 'show' just by putting the '<>' operator. Type has to be specified.

    return 0;
}
