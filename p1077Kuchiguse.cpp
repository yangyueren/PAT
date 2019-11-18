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
    int N;
    cin >>N;
    getchar();
    vector<string> vc(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, vc[i]);
        reverse(vc[i].begin(), vc[i].end());
    }
    int flag=-1;
    int minlen=INT32_MAX;
    for (int j = 0; j < N; ++j) {
        if(vc[j].size() < minlen){
            minlen = vc[j].size();
        }
    }
    for (int k = 0; k < minlen; ++k) {
        char a = vc[0][k];
        int is = 1;
        for (int i = 0; i < N; ++i) {
            if(vc[i][k] != a){
                is = 0;
                break;
            }
        }
        if(is==1) flag=k;
        else break;
    }

    if(flag==-1) printf("nai\n");
    else{
        for (int i = flag; i >=0 ; --i) {
            cout << vc[0][i];
        }
        cout << endl;
    }
    return 0;
}