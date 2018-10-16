#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

using namespace std;

class Test{
public:
    Test(initializer_list<string> texts){
        for(auto text : texts){
            cout << text << endl;
        }
    }

    void print(initializer_list<string> texts){
        for(auto text : texts){
            cout << text << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> numbers{1,2,3,4};
    cout << numbers[3] << endl;

    Test test{"Nanda","Kavya"};
    cout << endl;
    test.print({"Nanda","Kavya"});

    return 0;
}
