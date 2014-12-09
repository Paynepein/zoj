#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool isOK(vector<int> v);
int isupheld(vector<int> vhigh,vector<int> vlow);
bool isFactor(vector<int> vhigh,vector<int> vlow,int tmp = 1)
{
    if(!isOK(vlow))
        return false;
    vector<int> vmhigh(vhigh);
    vmhigh.reserve(100);
    for(vector<int>::iterator iter = vhigh.begin();iter!=vhigh.end();)
    {
        if(tmp == 1 || *iter/tmp == 0 && find(vhigh.begin(),vhigh.end(),tmp) == vhigh.end() && find(vhigh.begin(),vhigh.end(),*iter/tmp) == vhigh.end() && tmp != *iter/tmp)
        {
            vhigh.push_back(tmp);
            vhigh.push_back(*iter/tmp);
            iter = vhigh.erase(iter);
            if(isupheld(vhigh,vlow))
                return true;
            else if(isFactor(vhigh,vlow))
            {
                return true;
            }
        }else
        {
            iter++;
        }
    }
    if(isFactor(vmhigh,vlow,tmp+1))
        return true;
    return false;
}

bool isOK(vector<int> v)
{
    vector<int>::iterator vend = v.end();
    for(vector<int>::iterator iter = v.begin();iter!=vend;iter++)
    {
        if(*iter>100)
            return false;
    }
    return true;
}

int isupheld(vector<int> vhigh,vector<int> vlow)
{
    vector<int>::iterator vend = vhigh.end();
    vector<int>::iterator findit;
    int index=-1;
    for(vector<int>::iterator iter = vhigh.begin();iter!=vend;iter++)
    {
        index++;
        findit = find(vlow.begin(),vlow.end(),*iter);
        if(findit != vlow.end())
            return index;
    }
    return -1;
}

bool Referee(vector<int> vhigh,vector<int> vlow,int small = 1)
{
    vector<int> vmlow(vlow);
    vmlow.reserve(100);
    vector<int>::iterator iter;
    for(iter = vmlow.begin();iter!=vmlow.end();)
    {
        if(small == 1 || *iter%small == 0 && find(vmlow.begin(),vmlow.end(),small) == vmlow.end() && find(vmlow.begin(),vmlow.end(),*iter/small) == vmlow.end() && small != *iter/small)
        {
            vmlow.push_back(small);
            vmlow.push_back(*iter/small);
            iter = vmlow.erase(iter);
            if(isFactor(vhigh,vmlow))
            {
                return true;
            }else if(Referee(vhigh,vmlow))
            {
                return true;
            }
        }else
        {
            iter++;
        }
    }
    if(Referee(vhigh,vlow,small+1))
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
        if(Referee(vhigh,vlow))
            cout<<high<<endl;
        else
            cout<<low<<endl;
        vhigh.clear();
        vlow.clear();
    }
    return 0;
}
