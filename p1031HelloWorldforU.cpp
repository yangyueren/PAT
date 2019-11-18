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

char s[90];
char m[90][90];
int main(){
    int len;
    char c;
    scanf("%s", s);
    string st = s;
    len = st.size();
    int a, b;
    int n = len+2;
    for (int b = 3; b <= n ; ++b) {
        int tmp = n-b -2;
        if(tmp%2!=0){
            continue;
        }
        a = tmp/2;
        if(a<=b){
            break;
        }
    }
    b = len-2*a;
    for (int i = 0; i < len; ++i) {
        if(i<a) m[i][0] = s[i];
        if(i>=a+b) m[2*a+b-i-1][b-1] = s[i];
        else m[a][i-a] = s[i];
    }
    for (int j = 0; j <= a; ++j) {
        for (int i = 0; i <= b-1; ++i) {
            if(m[j][i] == 0) printf(" ");
            else printf("%c", m[j][i]);
        }
        printf("\n");
    }
    return 0;
}