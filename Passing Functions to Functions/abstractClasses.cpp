#include <iostream>
#include <string>

using namespace std;

class Animal{
public:
    virtual void speak() = 0; // pure virtual function - class can't be instantiated
    virtual void run() = 0;
    virtual ~Animal(){
        cout << "Animal destructed " << endl;
    };
};

class Dog : public Animal{
// class extending from abstract classes should have implementation of all the pure virtual 
// functions declared in the super class otherwise instantiation is not possible
public:
    virtual void speak(){
        cout << "Woof!!!" << endl;
    }
    ~Dog(){
        cout << "Dog destructed " << endl;
    }
};

class Labrador : public Dog{
public:
    Labrador(){
        cout << "Construct Labrador " << endl;
    }
    virtual void run(){
        cout << "Running!!!" << endl;
    }
    ~Labrador(){
        cout << "Labrador destructed " << endl;
    }
};

void test(Animal& animal){
    animal.run();
}

int main(int argc, char const *argv[])
{
    Labrador lab; // Labrador can be instantiated since it has implementation for both the pure virtual functions declared in 
    lab.speak();  // Animal. But Dog can't be instantiated since it doesn't implement run method.
    lab.run();

    Animal* animals[5];
    animals[0] = &lab;
    animals[0]->speak();

    test(lab);
    test(*animals[0]);

    return 0;
}
