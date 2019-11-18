//
// Created by yryang on 2019/8/24.
//

#include <iostream>
#include <string>
#include <map>

typedef std::map<int , std::string> mapPeopleType;
void for_each(mapPeopleType &PeopleMap)
{
    mapPeopleType::iterator  itr = PeopleMap.begin();

    std::cout<< "for_each "<<std::endl;
    while(itr != PeopleMap.end())
    {
        std::cout<< " first "<< itr->first << " second "<<itr->second<<std::endl;
        itr++;
    }

}

void reverse_for_each(mapPeopleType &PeopleMap)
{
    mapPeopleType::reverse_iterator  itr = PeopleMap.rbegin();

    std::cout<< "reverse_for_each "<<std::endl;
    while(itr != PeopleMap.rend())
    {
        std::cout<< " first "<< itr->first << " second "<<itr->second<<std::endl;
        itr++;
    }

}

void  add(mapPeopleType &PeopleMap)
{

    std::cout<< " add "<<std::endl;
    PeopleMap[333] = std::string("zhangsan_ver2");//覆盖更新

    PeopleMap[444] = std::string("zhang444new"); //新增

    std::pair< mapPeopleType::iterator, bool >insert_pair;

    insert_pair = PeopleMap.insert(std::make_pair<int ,std::string>(222 ,"zhang liu"));//插入已存在的键值将会失败
    //
    if(insert_pair.second == false)
    {
        std::cout<< " first: "<< insert_pair.first->first << ", second: "<<"false"<<std::endl;
    }

}

void my_find(mapPeopleType &PeopleMap)
{
    std::cout<< " find :"<<std::endl;
    mapPeopleType::iterator  itr;

    itr = PeopleMap.find(222);

    if(itr != PeopleMap.end())
    {
        std::cout<< " first "<< itr->first << " second "<<itr->second<<std::endl;
    }
    else
    {
        std::cout<< "not found  222"<<std::endl;
    }

    itr = PeopleMap.find(22);
    if(itr != PeopleMap.end())
    {
        std::cout<< " first "<< itr->first << " second "<<itr->second<<std::endl;
    }
    else
    {
        std::cout<< "not found 22"<<std::endl;
    }

}

void del(mapPeopleType &PeopleMap)
{
    std::cout<< " 444 :"<<std::endl;
    mapPeopleType::iterator  itr;
    itr = PeopleMap.find(444);

    if(itr != PeopleMap.end())
    {
        PeopleMap.erase(itr);
        std::cout<< " 444 delete success"<<std::endl;
        return ;
    }

}


int main()
{
    mapPeopleType PeopleMap;

    PeopleMap[333] = std::string("zhangsan");
    PeopleMap.insert(std::make_pair<int ,std::string>(222 ,"zhang liu"));

    //遍历
    for_each(PeopleMap);
    //反向遍历
    reverse_for_each(PeopleMap);

    //添加数据
    add(PeopleMap);

    for_each(PeopleMap);

    reverse_for_each(PeopleMap);

    //查找
    my_find(PeopleMap);

    //删除

    del(PeopleMap);
    for_each(PeopleMap);

    //其他
    std::cout<< " size: "<< PeopleMap.size() << ", empty: "<<PeopleMap.empty()<<std::endl;

    PeopleMap.clear();
    std::cout<<"clear after"<< " size: "<< PeopleMap.size() << ", empty: "<<PeopleMap.empty()<<std::endl;

    return 0;
}