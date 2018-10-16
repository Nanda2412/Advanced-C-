#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    auto texts = {"One","Two","Three"};

    for(auto text : texts){
        cout << text << endl;
    }

    vector<int> numbers;
    numbers.push_back(6);
    numbers.push_back(8);
    numbers.push_back(10);
    numbers.push_back(12);

    for(auto number : numbers){
        cout << number << endl;
    }

    string hello = "Hello";

    for(auto c : hello){
        cout << c << endl;
    }
    
    return 0;
}
