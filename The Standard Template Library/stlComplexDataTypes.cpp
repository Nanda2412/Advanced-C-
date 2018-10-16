#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    set<map<string, vector<int> > > scores;

    /*
    scores["Mike"].push_back(10);
    scores["Mike"].push_back(20);
    scores["Vicky"].push_back(15);
    */
    map<string,vector<int> > score1;
    map<string,vector<int> > score2;
    score1.insert(make_pair("Mike",vector<int>{10,20}));
    score2.insert(make_pair("Lisa",vector<int>{15,25}));
    scores.insert(score1);
    scores.insert(score2);

    for(set<map<string,vector<int> >>::iterator it = scores.begin();it != scores.end();it++){
        map<string,vector<int> > score = *it;
        map<string,vector<int> >::iterator it1 = score.begin();
        string name = it1->first;
        vector<int> scoreList = it1->second;

        cout << name << " : " << flush;

        for(int i=0;i<scoreList.size();i++){
            cout << scoreList[i] << " " << flush;
        }

        cout << endl;
    }

    return 0;
}
