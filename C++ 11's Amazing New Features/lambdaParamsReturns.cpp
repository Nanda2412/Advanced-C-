#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point3D{
private:
    float x;
    float w;
private:
    float y;
private:
    float z;

public:
    template<class class_type,
         class data_type1,
         class data_type2>
    const char* access_order(data_type1 class_type::*mem1, data_type2 class_type::*mem2){
        assert(mem1 != mem2);
        //return mem1 < mem2 ? "member 1 occurs first" : "member 2 occurs first";
        if(std::less<void*>()(&(mem1),&(mem2))){
            return "member 1 occurs first";
        }
        else{
            return "member 2 occurs first";
        }
    }

    const char* showAccessOrder(){
        return access_order(&Point3D::x,&Point3D::w);
    }
    float getZ() const{
        return z;
    }
    float getY() const{
        return y;
    }
};

class Base{
public:

    char* str;
    Base() = default;
    Base(const char* name):str(new char[strlen(name)]){
        std::copy(name,name+strlen(name),str);
    }
    virtual ~Base(){}
};
class Derived : public Base{

};

template<class class_type,
         class data_type1,
         class data_type2>
const char* access_order(data_type1 class_type::*mem1, data_type2 class_type::*mem2){
    assert(mem1 != mem2);
    if(mem1 < mem2) return "member 1 occurs first" ;
    else return "member 2 occurs first";
}

int g;

// lambda function receivers
void receiveGreeting(void (*greeting)(string)){
    greeting("Kavya");
}

void receiveDivide(double (*divide)(double,double)){
    auto rval = divide(9,3);
    cout << rval << endl;
}

int main(int argc, char const *argv[])
{ 
    int myints[]{10,20,30,40,50,60,70};
    size_t arraySize = end(myints) - begin(myints);
    cout << "Array size : " << arraySize << endl;

    int *pInt = new int[arraySize];

    std::copy ( begin(myints), end(myints), pInt );

    std::cout << "my pointer contains:";
    for (int i = 0; i < arraySize; i++){
        cout << " " << pInt[i] ;
    }

    std::cout << '\n';

    Point3D pt;
    cout << pt.showAccessOrder() << endl;
    int a = 2;
    int& b = a; //ref b acts as an alias for variable a
    b = 3; // since b refers to a any changes to that modify what it refers as well.
    int one = 1;
    int two = 2;
    int* c = &g;
    int* d = &two;
    float f = 9.0;
    float* e = &f;

    if(c == d){
        cout << "Equals" << endl;
    }
    else{
        cout << "Unequal" << endl;
    }

    if(c > d){
        //this case should be unspecified
        //no promise of what exactly can happen. 
    }

    if(b == a){
        cout << "Equals" << endl;
    }

    cout << "a : " << a << " - " << "b : " << b << endl;

    int const nu = 0;

    Base* ba = new Derived();
    Derived* der = dynamic_cast<Derived*>(ba); // this works on if classes have a polymorphic relationship
                                               // if 'ba' doesn't point to the type it's checking for then the check returns NULL.

    if(der){
        //do what you want with the derived object.
    }

    //but if it was derived to base conversion there won't be any compiler error for not having a polymorphic relationship - normal inheritance suffice.
    //static_cast throws error when classes involved are not at all related to each other i.e. there is no inheritance hierarchy involved

    delete ba;

    Base aBa("Nanda");
    cout << "Char : " << aBa.str << endl;

    /**
    * lambda paramas returns 
    **/

    auto greeting = [](string name){cout << "Hello " << name << endl;};

    greeting("Nanda");
    receiveGreeting(greeting);

    auto pDivide = [](double a,double b) -> double{

        if(b == 0.0){
            return 0;
        }

        return a/b;
    };

    cout << pDivide(10.0,5.0) << endl;
    cout << pDivide(10.0,0) << endl;
    receiveDivide(pDivide);

    return 0;
}

