//
// Created by yryang on 2019/8/27.
//

#include "iostream"
#include "map"
#include "vector"
#include "string"
#include "set"
#include "limits.h"
#include "stdlib.h"
using namespace std;

struct cmpStruct{
    bool operator () (const string & string1, const  string & string2 ) const{
        return string1 < string2;
    }
};
void sortByKey(){
    map<string, string, cmpStruct> m;
    m.insert(make_pair("12", "kk"));
    m.insert(make_pair("1234", "kk"));
    m.insert(make_pair("1", "kk"));
    m.insert(make_pair("1223", "kk"));
    m.insert(make_pair("1213", "kk"));
    m.insert(make_pair("1523", "kk"));
    map<string, string>::iterator it;
    m.erase("1234");
    for (it = m.begin(); it!=m.end() ; it++) {
        cout << it->first << endl;
    }


}
//bool cmp(const  map<string, string>::iterator & it1, const  map<string, string>::iterator & it2){
//    return it1->second < it2->second;
//}
int cmp(const  pair<string, string>& it1, const  pair<string, string> & it2){
    return it1.second < it2.second;
}
void sortByValue(){
    map<string, string> m;
    m.insert(make_pair("12", "1"));
    m.insert(make_pair("1234", "123"));
    m.insert(make_pair("1", "23"));
    m.insert(make_pair("1223", "43"));
    m.insert(make_pair("1213", "122"));
    m.insert(make_pair("1523", "222"));
    vector<pair<string, string>> ve;
    map<string, string>::iterator it;

    for (it = m.begin(); it!=m.end() ; it++) {
        ve.push_back(make_pair(it->first, it->second));
    }
    sort(ve.begin(), ve.end(), cmp);

    for (int i = 0; i < ve.size(); ++i) {
        cout << ve[i].second << endl;
    }
};
int main(){
    sortByKey();
//    sortByValue();
    return 0;
}