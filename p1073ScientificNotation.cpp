//
// Created by yryang on 2019/9/14.
//

#include "iostream"
#include "string.h"
#include "string"
#include "stdlib.h"
#include "stdio.h"
#include "map"
#include "vector"
#include "set"
#include "math.h"
#include "queue"
#include "algorithm"
using namespace std;

int main(){

    char fuhao;
    scanf("%c",&fuhao);
    if(fuhao == '-') cout<<fuhao;
    string s;
    cin >> s;
    size_t e = s.find('E');
    string re = s.substr(0, e);
    string exp = s.substr(e+1);
    int n = stoi(exp);
    if(n<0){
        cout << "0.";
        while (++n) cout << "0";
        for (int i = 0; i < re.size(); ++i) {
            if(re[i]!='.') cout << re[i];
        }
    } else{
        //no point
        if(n +2 >= re.size()){
            int zero = n+2-re.size();
            re.erase(1,1);
            cout << re;
            for (int i = 0; i <zero; ++i) {
                cout << "0";
            }
        }
        else{
            re.erase(1,1);
            int p = n;
            for (int i = 0; i < re.size(); ++i) {
                cout << re[i];
                if(i==p) cout <<".";
            }
        }
    }

    return 0;
}