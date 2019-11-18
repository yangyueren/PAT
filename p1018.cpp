//
// Created by yryang on 2019/8/25.
//

#include "stdio.h"
#include "iostream"
#include "string"
#include "map"
#include "vector"
#include "limits.h"

using namespace std;

int n, k;
int countn=0;
vector<int> num;
void convert(int n, int k){
    for (int i = 0; n!=0; ++i) {
        num.insert(num.begin(), n%k);
        n/=k;
        countn++;
    }
}
int main(){
    cin >> n >> k;
    convert(n, k);
    vector<int>::iterator it = num.begin();
    int flag = 1;
    for (int i = 0; i < countn; ++i) {
        if (num[i] != num[countn-1-i]){
            flag = 0;
            break;
        }
    }
    if (flag == 1){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
    for (int i = 0; i < countn-1; ++i) {
        cout << num[i] << " ";
    }
    cout << num[countn-1];
    return 0;
}