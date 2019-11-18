//
// Created by yryang on 2019/8/24.
//


#include "iostream"


#include "string"
#include "map"
#include "vector"
using namespace std;

//vector 默认从小到大排，所以 真不变，假交换
bool compare(int a, int b){ return a<b;}
int main(){
    vector<int> a;
    vector<int>::iterator itve;
    cout << typeid(itve).name() << endl;
    a.insert(a.begin(),4);
    a.insert(a.begin(),5);
    a.insert(a.begin(),2);
    a.insert(a.begin(),8);
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << endl;
    }
//    sort(a.begin(), a.end(), compare);
    sort(a.begin(), a.end(), [](int x, int y){ return x < y;});
    for(auto it: a){
        cout << it << endl;
    }

    string str = "wodjsl";
    cout << str.length() << endl;

    map<int, string> m;

    m.insert(pair<int,string>(3, "333j"));//如果已经存在这个key，插入失败
    m[2] = "sdjj";
    for(auto it: m){
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}