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

    void print(){
        cout << _name << " : " << _age << endl;
    }
};

int main(){

    map<int,Person> people;

    people[0] = Person("Mike",40);
    people[1] = Person("Raj",20);
    people[2] = Person("Vicky",30);

    people.insert(make_pair(55,Person("Bob",56)));
    people.insert(make_pair(12,Person("Alice",24)));

    for(map<int,Person>::iterator it = people.begin(); it != people.end(); it++){
        cout << it->first << " - " << flush; 
        it->second.print();
    }

    return 0;
}