//
// Created by yryang on 2019/8/24.
//
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "set"
#include "string"
using namespace std;
struct cmpBy{
    bool operator () (const string & a, const string & b) const{
        return a > b;
    }
};

struct Info
{
    string name;
    double score;
    bool operator < (const Info &a) const // 重载“<”操作符，自定义排序规则
    {
        //按score由大到小排序。如果要由小到大排序，使用“>”即可。
        return a.score < score;
    }
};

int main(){
    set<Info> infos;//自带排序
    set<string, cmpBy> a;
    a.insert("233");
    a.insert("jk");
    set<string, cmpBy>::iterator it;
    for (it = a.begin();  it != a.end() ; it++) {
        cout << *it << endl;
    }
    for(string aa: a){
        cout << aa << endl;
    }
    cout << a.size();

    return 0;
}
