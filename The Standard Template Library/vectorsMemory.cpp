#include <iostream> 
#include <vector>

using namespace std;

int main(){

    vector<double> numbers(0);

    cout << "Size : " << numbers.size() << endl;
    int capacity = numbers.capacity();
    cout << "Capacity : " << capacity << endl;

    for(int i = 0; i < numbers.size(); i++){

        if(numbers.capacity() != capacity){
            capacity = numbers.capacity();
            cout << "Capacity : " << capacity << endl;
        }

        numbers.push_back(i);
    }

    numbers.clear(); // This will reset the size but not the actual internal array
    numbers.resize(100); // This will resize but won't impact the capacity of the internal array
    numbers.reserve(100000); // This will impact the capacity of the array
    cout << numbers[2] << endl;
    cout << "Size : " << numbers.size() << endl;
    cout << "Capacity : " << capacity << endl;

    return 0;
}