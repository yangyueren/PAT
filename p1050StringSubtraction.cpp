//
// Created by yryang on 2019/9/13.
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

char ss[10005];
char aa[10005];
set<char> st;
int main(){
    string s,a;
    getline(cin ,s);
    getline(cin, a);
    for (int i = 0; i < a.size(); ++i) {
        st.insert(a[i]);
    }
    for (int j = 0; j < s.size(); ++j) {
        if(st.find(s[j]) == st.end()){
            printf("%c", s[j]);
        }
    }
    printf("\n");
    return 0;
}