#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "vector"
using namespace std;

struct cmp  //自定义比较规则
{
    bool operator () (const string& str1, const string& str2) const
    {
        return str1.length() < str2.length();
    }
};
struct nodes{
    int val;
    nodes(int a){
        val = a;
    }
};
void test1(){
    map<string, int, cmp > scoreMap;  //这边调用cmp
    map<string, int, cmp >::iterator iter;

    scoreMap["LiMin"] = 90;
    scoreMap["ZZihsf"] = 95;
    scoreMap["Kim"] = 100;
    scoreMap.insert(map<string, int>::value_type("Jack", 88));

    for(iter=scoreMap.begin(); iter!=scoreMap.end(); iter++)
        cout<<iter->first<<' '<<iter->second<<endl;
    string a = "kjkd";
    size_t b = a.find('3');
    for (auto sss: a) {
        cout << sss << " ";
    }
    cout << b<<endl;
    cout << a.npos << endl;

    nodes* nod = new nodes(3);
    cout << nod->val;
    double dd = 23.4345;
    cout << floor(dd);
    cout << round(dd)<<endl;
    printf("%04d\n", 21);
    map<int, int> mp;
    mp[3]++;
    cout << mp[3] <<endl;

    char ca[100] = "6237334";
    string ts = to_string(34276654);
    cout << ts << endl;
    cout << stod(ts) << endl;
    strcpy(ca, ts.c_str());
    sort(ca, ca+7);
    cout << ca << endl;
    printf("%3.2e", stod(ca));

}

void test2(){
//    long的长度范围
    long long a = pow(2, 32)+1;
    cout << a <<endl;
//    遍历数字的每一位
    int b = 1234;
    int b1=0;
    while(b!=0){
        b1 = b1*10 + b%10;
        b/=10;
    }
    cout << b1 <<endl;
//    计算hh:mm:ss 并且四舍五入, 1s = 100 CLK_TCK
    int c1 = 123, c2 = 4577973;

    int c3 = c2-c1;
    if (c3%100>=50) c3 = c3/100+1;
    else c3/=100;
    printf("%02d:%02d:%02d\n", c3/3600,c3%3600/60, c3%60);
}

//数组循环右移M
//(i+M)%N
void test3(){
    int N=23;
    int M = 2;
    int arr[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = i;
    }
    M = M % N;
    for (int j = N-M; j < N; ++j) {
        cout << arr[j] << " ";
    }
    for (int k = 0; k < N-M; ++k) {
        cout << arr[k] << " ";
    }


}
//copy(begin(a), end(a), begin(b))   begin(a)就是&a
// and memcpy
void test4(){
    int a[] = {1,2,3,4,5};
    int b[5];
    cout << begin(a)<<endl;
    copy(begin(a),end(a), begin(b));

    copy(a,a+5, b);//这里的5代表个数
//    memcpy(b, a, sizeof(a));
    for (int i = 0; i < sizeof(b)/ sizeof(int); ++i) {
        cout << b[i] << " ";
    }
    vector<int> c(a, a+5);
    vector<int> d = c;
    c.erase(c.begin());
    for (int j = 0; j < d.size(); ++j) {
        cout << d[j] << " ";
    }
}
//扑克牌排序；
// 给全部元素标号，(i-1)%13代表所在的组
//牢牢记住0和1的区别 看看要输出的是什么
//
//2
//36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
void test5(){
    int N = 54;
    char mp[] = {'S','H','C','D','J'};
    int begin[57], end[57], next[57];
    int step = 0;
    scanf("%d", &step);
    for (int j = 1; j <= N; ++j) {
        begin[j] = j;
    }
    for (int j = 1; j <= N; ++j) {
        scanf("%d", &next[j]);
    }
    for (int i = 0; i < step; ++i) {
        for (int k = 1; k <= N; ++k) {
            end[next[k]] = begin[k];
        }
        for (int j = 1; j <= N; ++j) {
            begin[j] = end[j];
        }
    }
    for (int l = 1; l <= N; ++l) {
        printf("%c%d ", mp[(begin[l]-1)/13], ((begin[l]-1)%13)+1);
    }
}
void test6(){
    int N;
    scanf("%d", &N);
    int adjdis[N+1];
    int dis[N+1];
    int sum=0;
    dis[1] = 0;
    for (int i = 2; i <= N+1; ++i) {
        scanf("%d", &adjdis[i]);
        sum += adjdis[i];
        dis[i] = sum;
    }
    int re;
    cin >> re;
    for (int j = 0; j < re; ++j) {
        int be, end;
        cin >> be >> end;
        if(be > end) {
            swap(be,end);
        }
        int left = dis[end] - dis[be];
        int right = sum - left;
        if(left<right) cout<<left<<" ";
        else cout << right<<" ";
    }

}
/*
4 4 0.5 2 5.6 1 -2.7 0 3.6
3 3 -2.1 2 -5.6 1 2.7
 * */
//多项式求和
void test7(){
    const int max_n = 1006;
    double exp2coe[max_n] = {0.0};
//    memset(exp2coe, 0, sizeof(exp2coe));
    int k;
    double  c;
    int e;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        cin >> e >> c;
        exp2coe[e] += c;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        cin >> e >> c;
        exp2coe[e] += c;
    }
    int count = 0;
    for (int j = 0; j < max_n; ++j) {
        if(exp2coe[j] != 0) count++;
    }
    printf("%d ",count);
    for (int l = max_n-1; l >= 0; --l) {
        if(exp2coe[l] != 0) cout << l << " " << exp2coe[l] << " ";
    }

}

/*
1.1 2.5 1.7
1.2 3.0 1.6
4.1 1.2 1.1
 */
void test8(){
    char s[3] = {'W', 'T', 'L'};
    int tmp=-1;
    double ans = 1.0;
    for (int i = 0; i < 3; ++i) {
        int inx = -1;
        double max = INT8_MIN;
        double score;
        for (int j = 0; j < 3; ++j) {
            scanf("%lf", &score);
            if(score > max){
                max = score;
                inx = j;
            }
        }
        printf("%c ", s[inx]);
        ans *= max;
    }
    printf("%.2lf", (ans*0.65-1)*2+0.005);
}


//日期选择
struct node{
    char name[18];
    int hh;
    int mm;
    int ss;
};

//不等于 返回两个的比较值
bool great(node a, node b){
    if (a.hh != b.hh) return a.hh>b.hh;
    if (a.mm != b.mm) return a.mm>b.mm;
    if (a.ss != b.ss) return a.ss > b.ss;
}
void test9(){
    int N;
    node ans1;
    ans1.hh = 24;
    ans1.mm = 60;
    ans1.ss = 60;
    node ans2;
    ans2.hh = 00;
    ans2.mm = 0;
    ans2.ss = 0;
    node temp;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", &temp.name);
        scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
        if(great(ans1, temp) == true) ans1 = temp;
        scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
        if(great(ans2, temp) == false) ans2 = temp;
    }
    cout << ans1.name << " " << ans2.name;
}

struct node10{
    int val;
    node10 * next;
    node10(int val){
        this->val = val;
        this->next = NULL;
    }
};
void test10(){
    map<string, node10*> mp;
    map<node10*, string> mp2;
    int N;
    string head1;
    cin >> N >> head1;
    string be;
    int val;
    string end;
    mp["-1"] = NULL;
    mp2[NULL] = "-1";

    for (int i = 0; i < N; ++i) {
        cin >> be >> val >> end;
        node10* tmp;
        node10* tmp2;
        if(mp.find(be) == mp.end()) {
            tmp = new node10(val);
            mp[be] = tmp;
        }
        else tmp = mp[be];
        if(mp.find(end) == mp.end()) {
            tmp2 = new node10(val);
            mp[end] = tmp2;
        }
        else tmp2 = mp[end];

        tmp->next = tmp2;
        tmp->val = val;
        mp2[tmp] = be;
        mp2[tmp2] = end;
    }
    node10* phead1 = mp[head1];
    while (phead1!=NULL){
        cout << mp2[phead1] << " ";
        phead1 = phead1->next;
    }
}
void test11(){
    int a = 15;
}

int gcd(int a, int b){
    return (a==0) ? b : gcd(b%a, a);
}
void test12(){
    int a[100];
    memset(a, 0, sizeof(a));
    fill(a, a+100, 3);
    for (int i = 0; i < 3; ++i) {
        cout << a[i] << " ";
    }
}

//scanf() 返回1 成功
void test13(){
    int a;
    char c[23];
    cout << scanf("%d",&a);
    cout << EOF;
}
int main()
{
    test13();
//    vector<int> vc(5);
//    cout << (vc.end()-vc.begin());
//    vector<int>::iterator it = vc.begin();
//    it++;
//    cout << it-vc.begin();
//    test12();
    return 0;
}