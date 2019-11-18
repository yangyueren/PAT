//
// Created by yryang on 2019/9/7.
//

#include "iostream"
#include "map"
#include "string"
#include "vector"
#include "algorithm"
#include "limits.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
using namespace std;

bool isprime(int n){
    if(n<2) return false;
    if(n==2) return true;
    for (int i = 2; i*i <= n; ++i) {
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    int N, K;
    string s;
    cin >> N >> K;
    cin >> s;
    for (int i = 0; i <= N-K; ++i) {
        string a = s.substr(i,K);
        int b = stoi(a);
        if(isprime(b)){
            cout << a;
            return 0;
        }
    }
    cout << "404\n";

    return 0;
}