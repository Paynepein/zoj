#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int Factor(int tmp)
{
    for(int i=100;i>1;i--)
    {
        if(tmp%i==0)
        {
            return i;
        }
    }
    return -1;
}

bool Slice(vector<int> &large)
{
    int tmp,fac;
    for(vector<int>::iterator iter=large.begin();iter!=large.end();)
    {
        if(*iter>100)
        {
            tmp = *iter;
            fac = Factor(tmp);
            if(fac == -1)
                return false;
            large.push_back(fac);
            large.push_back(tmp/fac);
            iter = large.erase(iter);
            if(tmp/fac>100)
                return Slice(large);
        }else
        {
            iter++;
        }
    }
    return true;
}

bool Slice(vector<int> &large,int big)
{
    vector<int>::iterator findit = find(large.begin(),large.end(),big);
    if(findit==large.end())
    {
        cout<<"error"<<endl;
        return false;
    }else
    {
        int tmp = Factor(big);
        if(tmp == -1)
            return false;
        large.erase(findit);
        large.push_back(tmp);
        large.push_back(big/tmp);
        return true;

    }
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

bool Referee(vector<int> &vhigh,vector<int> &vlow)
{
    if(!isOK(vlow))
    {
        if(!Slice(vlow))
        {
            return true;
        }
    }
    if(!isOK(vhigh))
    {
        if(!Slice(vhigh))
        {
            return false;
        }
    }
    int index = isupheld(vhigh,vlow);
    if(index != -1)
    {
        Slice(vhigh,vhigh.at(index));
        return Referee(vhigh,vlow);
    }else
    {
        return false;
    }
}

int main()
{
    int high,low;
    vector<int>vhigh,vlow;
    while(scanf("%d%d",&high,&low) == 2)
    {
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

//        for(vector<int>::iterator iter = vhigh.begin();iter!=vhigh.end();iter++)
//        {
//            cout<<*iter<<endl;
//        }
    }

    return 0;
}
