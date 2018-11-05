#include <iostream>
#include <string>

using namespace std;

#define ADINTERVAL 4
#define BANINTERVAL 9

inline
void updateBanner(const int& index){
    if(index%9 == 0){
        //insert banner
        cout << "9's : " << index << endl;
    }
}

inline
void updateAdvertisement(const int& index, bool &isUpdated, int &conflictCount,const bool status){
    if(index%BANINTERVAL == 0 && (index-conflictCount)%ADINTERVAL == 0){
        isUpdated = status;
        conflictCount++;
    }
    else if((index-conflictCount)%ADINTERVAL == 0){
        //insert advertisement
        cout << "4's : "<< index << endl;
    }
}

class Point3d { 
    public:    
    virtual ~Point3d(){};    
    // ... 
    protected:    
    static Point3d origin;    
    float x, y, z; 
};

Point3d pt;

int main(int argc, char const *argv[])
{
    bool isUpdated = false;
    int conflictCount = 0; //do modulus for keeping this variables in check, same goes for list iteration

    for(int i = 1;i <= 100;i++){

        updateBanner(i);

        if(isUpdated){
            updateAdvertisement(i,isUpdated,conflictCount,false);
        }
        else{
            updateAdvertisement(i,isUpdated,conflictCount,true);
        }

    }

    return 0;
}
