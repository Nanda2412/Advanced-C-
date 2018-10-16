#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

#define X(p,xval) (p.x) = (xval)

class Point3d { 
public:    
    Point3d( float x = 0.0,float y = 0.0, float z = 0.0 ) : _x( x ), _y( y ), _z( z ) {}    
    float x() const{ return _x; }    
    float y() const{ return _y; }    
    float z() const{ return _z; }    
    void x( float xval ) { _x = xval; }    // ... etc ... 
private:    
    float _x;    
    float _y;    
    float _z; 
}; 

inline ostream& operator<<( ostream &os, const Point3d &pt ) {    
    os << "( " << pt.x() << ", " << pt.y() << ", " << pt.z() << " ) "; 
    return os;
}

int main(int argc, char const *argv[])
{
    string value;
    int num;
    double anotherNum;

    cout << typeid(value).name() << endl;
    cout << typeid(num).name() << endl;
    cout << typeid(anotherNum).name() << endl;

    decltype(value) myName = "Nanda"; // decltype helps to extract the type information from the variable 

    cout << myName << endl;

    return 0;
}
