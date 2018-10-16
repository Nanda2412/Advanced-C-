#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person{
private:
    string _name;
    int _age;

public:
    Person():_name(""),_age(0){

    }

    Person(string name,int age):_name(name),_age(age){

    }

    Person(const Person &other){
        cout << "Copy constructor running!!!" << endl;
        _name = other._name;
        _age = other._age;
    }

    void print() const{ // if it's not specified as constant we will get compile time error - Point to be noted once using custom objects as keys in map
        cout << _name << " : " << _age << endl;
    }

    // Without overloading the '<' operator we can't compile the code while using custom object as key - it need to compare keys while inserting
    bool operator<(const Person &other) const{

        if(_name == other._name){
            return _age < other._age; // Or else age won't have any impact on the comparison
        }
        else{
            return _name < other._name;
        }
    }
};

int main(){

    map<Person,int> people;

    people[Person("Mike",40)] = 40;
    people[Person("Mike",60)] = 50;
    people[Person("Raj",30)] = 30;
    people[Person("Vicky",40)] = 20;


    for(map<Person,int>::iterator it = people.begin(); it != people.end(); it++){
        cout << it->second << " - " << flush; 
        it->first.print();
    }

    return 0;
}