#include <iostream>
#include <list>

using namespace std;

int main(){

    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);

    list<int>::iterator it = numbers.begin();
    it++;
    numbers.insert(it,100);
    cout << "Element(Insert) : " << *it << endl;

    list<int>::iterator eraseIt = numbers.begin();
    eraseIt++;
    eraseIt = numbers.erase(eraseIt); // erase() method invalidates the iterator so it's always a good
                            // practice to set the iterator after the method call
    cout << "Element(Erase) : " << *it << endl;

    for(list<int>::iterator it = numbers.begin(); it != numbers.end();){
        if(*it == 2){
            numbers.insert(it,1234);
        }

        if(*it == 1){
            it = numbers.erase(it);
        }
        else{
            it++;
        }
    }

    for(list<int>::iterator it = numbers.begin(); it != numbers.end(); it++ ){
        cout << *it << endl;
    }

    return 0;
}