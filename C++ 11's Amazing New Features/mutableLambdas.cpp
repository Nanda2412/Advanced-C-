#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    //mutable keyword usage in lambda
    int cats = 5;

    [cats]() mutable {
        cats = 8;
        cout << cats << endl;
    }();

    cout << cats << endl; // local variable retains it's original value
    return 0;
}
