#include <iostream>
#include <string>

using namespace std;

//C++ 98 initialization
int main(int argc, char const *argv[])
{
    int values[] = {1,2,3};
    cout << values[0] << endl;

    class C{
        public:
            string text;
            int id;
    };

    C c1 = {"Nanda", 28};

    cout << c1.text << endl;

    struct S{
        string text;
        int id;
    };

    S s1 = {"Kavya", 27};

    cout << s1.text << endl;

    struct {
        string text;
        int id;
    }r1={"asd",6},r2={"fgh",12};

    cout << r1.text << " - " << r2.text << endl;

    return 0;
}
