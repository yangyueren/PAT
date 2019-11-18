//
// Created by yryang on 2019/9/11.
//
#include "iostream"
#include "string"
#include "stdlib.h"
#include "stdio.h"
#include "map"
using namespace std;


//最坑的地方，当为13时候，只用输出tam，不用输出tret
int N;
int main(){
    string nowstr;
    scanf("%d", &N);
    string a1[]={"tret","jan","feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string a2[] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};


    getchar();

    for (int i = 0; i < N; ++i) {
        getline(cin, nowstr);
        if(nowstr[0] >='0' && nowstr[0] <='9'){
            int num = stoi(nowstr);
            int marnum[3];
            int cnt=0;
            do{
                marnum[cnt++] = num%13;
                num/=13;
            }while (num!=0);
            string re;
            if(cnt==2){
                re = a2[marnum[1]]+" "+a1[marnum[0]];
                if(marnum[0]==0){
                    re=a2[marnum[1]];
                }
            }
            if(cnt==1){
                re = a1[marnum[0]];
            }
            printf("%s\n", re.c_str());

        } else{
            int num=0;
            size_t pos = nowstr.find(" ");
            if( pos != string::npos){
                string na = nowstr.substr(0, pos);
                string nb = nowstr.substr(pos+1, nowstr.size()-pos-1);
                for (int j = 0; j < 13; ++j) {
                    if (na==a2[j]) {
                        num=j*13;
                        break;
                    }
                }
                for (int j = 0; j < 13; ++j) {
                    if (nb==a1[j]) {
                        num+=j;
                        break;
                    }
                }
            }else{
                string nb = nowstr;
//                cout << nb;
                for (int j = 0; j < 13; ++j) {
                    if (nb==a1[j]) {
                        num=j;
                        break;
                    }
                }
                for (int j = 0; j < 13; ++j) {
                    if (nb==a2[j]) {
                        num=j*13;
                        break;
                    }
                }
            }
            printf("%d\n", num);
        }
    }

}