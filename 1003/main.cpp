#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool isOK(vector<int> v);
int isupheld(vector<int> vhigh,vector<int> vlow);
bool Factor(vector<int> vhigh,vector<int> vlow,int tmp = 1)
{

}

bool canFactor(vector<int> large,int small = 100)
{
    if(isOK(large))
        reture true;
    vector<int>::iterator iter;
    vector<int> vlarge(large);
    for(iter = large.begin();iter != large.end();)
    {
        if(*iter%small == 0 && find(large.begin(),large,end(),small)==large.end() && find(large.begin(),large,end(),*iter/small)==large.end() && *iter/small != small)
        {
            large.push_back(small);
            large.push_back(*iter/small);
            iter = large.erase(iter);
            if(canFactor(large,small-1))
                return true;
            else
                continue;
        }else
        {
            iter++;
        }
    }
    return canFactor(vlarge,small-1);
}

bool isOK(vector<int> v)
{
    vector<int>::iterator vend = v.end();
    for(vector<int>::iterator iter = v.begin(); iter!=vend; iter++)
    {
        if(*iter>100)
            return false;
    }
    return true;
}

int isupheld(vector<int> vhigh,vector<int> vlow)
{
    if(isOK(vhigh) && isOK(vlow))
    {
        vector<int>::iterator vend = vhigh.end();
        vector<int>::iterator findit;
        int index=-1;
        for(vector<int>::iterator iter = vhigh.begin(); iter!=vend; iter++)
        {
            index++;
            findit = find(vlow.begin(),vlow.end(),*iter);
            if(findit != vlow.end())
                return index;
        }
    }
    return -1;
}

bool Referee(vector<int> vhigh,vector<int> vlow,int small = 100)
{

}

bool WinnerIsHigh(vector<int> vhigh,vector<int> vlow)
{
    if(!canFactor(vlow))
    {
        return false;
    }else if(Referee(vhigh,vlow))
    {
        return true;
    }
    return false;

}

int main()
{
    int high,low;
    vector<int>vhigh,vlow;
    while(cin>>high>>low)
    {
        vhigh.reserve(100);
        vlow.reserve(100);
        if(high<low)
        {
            int tmp = high;
            high = low;
            low = tmp;
        }
        vhigh.push_back(high);
        vlow.push_back(low);
        if(WinnerIsHigh(vhigh,vlow))
            cout<<high<<endl;
        else
            cout<<low<<endl;
        vhigh.clear();
        vlow.clear();
    }
    return 0;
}
