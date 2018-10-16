#include <iostream>
#include <string>

using namespace std;

class Test{
private:
    int one{1};
    int two{2};

public:
    void run(){
        int three{3};
        int four{4};

        auto pLambda = [&,this](){ // 'this' is passed as reference. 'this' can't be passed along with '=' (pass by value) - produces compile error.
            cout<< one << endl;
            one = 100;
            cout << one << endl;
            cout << two << endl;
            cout << three << "," << four << endl;
        };

        pLambda();
    }
};

int main(int argc, char const *argv[])
{
    Test test;
    test.run();

    return 0;
}
