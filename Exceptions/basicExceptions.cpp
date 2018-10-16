#include <iostream>
#include <string>

using namespace std;

void mightGoWrong(){
    
    bool error1 = false;
    bool error2 = false;
    bool error3 = true;

    if(error1){
        throw 8;
    }
    
    if(error2){
        throw "Something went wrong";
    }

    if(error3){
        throw string("Something else went wrong");
    }
}

void useMightGoWrong(){
    mightGoWrong();
}

int main(int argc, char const *argv[])
{
    try{
        useMightGoWrong();
    }
    catch(int e){
        cout << "Error code : " << e << endl;
    }
    catch(char const * e){
        cout << "Error message : " << e << endl;
    }
    catch(string &e){
        cout << "Error string message : " << e << endl;
    }

    cout << "Still running" << endl;

    return 0;
}
