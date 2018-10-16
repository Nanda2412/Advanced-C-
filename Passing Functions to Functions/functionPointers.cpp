#include <iostream>
#include <string>

using namespace std;

void test(string name){
    cout << "Hello, " << name << endl; 
}

int main(int argc, char const *argv[])
{
    test("Nanda");

    void (*pTest)(string) = test;

    (*pTest)("Nandakumar");
    pTest("Mike");

    return 0;
}
