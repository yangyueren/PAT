//功能：输入单词，统计单词出现次数并按照单词出现次数从多到少排序
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int cmp(const pair<string, int>& x, const pair<string, int>& y)
{
    return x.second > y.second;
}

void sortMapByValue(map<string, int>& tMap,vector<pair<string, int> >& tVector)
{
    for (map<string, int>::iterator curr = tMap.begin(); curr != tMap.end(); curr++)
        tVector.push_back(make_pair(curr->first, curr->second));

    sort(tVector.begin(), tVector.end()-1, cmp);
}

struct cmpByKey  //自定义比较规则
{
    bool operator () (const string& str1, const string& str2) const
    {
        return str1.length() < str2.length();
    }
};
void sortMapByKey(){

    map<string, int, cmpByKey > scoreMap;  //这边调用cmp
    map<string, int, cmpByKey >::iterator iter;

    scoreMap["LiMin"] = 90;
    scoreMap["ZZihsf"] = 95;
    scoreMap["Kim"] = 100;
    scoreMap.insert(map<string, int>::value_type("Jack", 88));

    for(iter=scoreMap.begin(); iter!=scoreMap.end(); iter++)
        cout<<iter->first<<' '<<iter->second<<endl;

}

int main()
{
    sortMapByKey();
    map<string, int> tMap;
    string word;
    int re = 3;
    while (re-- > 0)
    {
        cin >> word;
        pair<map<string,int>::iterator,bool> ret = tMap.insert(make_pair(word, 1));
        if (!ret.second)
            ++ret.first->second;
    }

    vector<pair<string,int>> tVector;
    sortMapByValue(tMap,tVector);
    for(int i=0;i<tVector.size();i++)
        cout<<tVector[i].first<<": "<<tVector[i].second<<endl;

    return 0;
}