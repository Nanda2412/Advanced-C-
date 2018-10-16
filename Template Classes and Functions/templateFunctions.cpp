#include <iostream>
#include <string>

using namespace std;

template<typename T>
void print(T n){
    cout << n << endl;
}

int main(int argc, char const *argv[])
{
    print<string>("Hi Nanda");
    print<int>(8);

    print("Have a good day!!!"); // Type inference in action
    
    return 0;
}
