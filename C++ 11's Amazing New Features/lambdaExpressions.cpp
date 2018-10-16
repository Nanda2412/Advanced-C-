#include <iostream>
#include <string>

using namespace std;

void test(void (*pFunc)(void)){
    pFunc();
}

int main(int argc, char const *argv[])
{
    //The following statement generates warning - expression result unused - commenting as of now
    //[](){}; // won't work with C++98. compiler should atleast be C++11 compatible 
    
    auto func = [](){ cout << "Hello" << endl; };
    func();

    test(func);

    test([](){ cout << "Hello once again!!!" << endl; });

    return 0;
}
