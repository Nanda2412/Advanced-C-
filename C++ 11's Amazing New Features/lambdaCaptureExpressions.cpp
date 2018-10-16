#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int one = 1;
    int two = 2;
    int three = 3;

    // capture one and two by values - read only can't write to the variables accessed - compile error
    [one,two](){ cout << one << "," << two << endl;}();

    // capture all variables by value
    [=](){ cout << one << "," << two << "," << three << endl; }();

    // capture all variables by value, but two by reference
    [=,&two](){ two = 4; cout << one << "," << two << "," << three << endl;}();

    // capture all variables by reference
    [&](){ one = 6; two = 7; three = 8; cout << one << "," << two << "," << three << endl;}();

    // capture all variables by reference, but three by value
    [&,three](){ one = 9; two = 10; cout << one << "," << two << "," << three << endl;}();

    return 0;
}
