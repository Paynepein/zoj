#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool numberIsUsed[101];

bool CanFactor(int number,int factor = 100)
{
    if(number == 1)
    {
        return true;
    }
    if(factor<2)
    {
        return false;
    }
    for(;factor>1;factor--)
    {
        if(number%factor == 0 && numberIsUsed[factor] == false)
        {
            break;
        }
    }
    if(factor == 1)
    {
        return false;
    }
    numberIsUsed[factor] = true;
    if(CanFactor(number/factor,factor-1))
    {
        return true;
    }else
    {
        numberIsUsed[factor] = false;
    }
    return CanFactor(number,factor-1);
}

bool IsOK(int high,int low,int factor = 100)
{
    if(low == 1 && CanFactor(high))
    {
        return true;
    }
    if(factor == 1)
    {
        return false;
    }
    for(;factor>1;factor--)
    {
        if(low%factor == 0 && numberIsUsed[factor]==false)
        {
            break;
        }
    }
    if(factor == 1)
    {
        return false;
    }
    numberIsUsed[factor] = true;
    if(IsOK(high,low/factor,factor-1))
    {
        return true;
    }
    numberIsUsed[factor] = false;
    return IsOK(high,low,factor-1);
}

bool IsHighWin(int high,int low,int factor = 100)
{
    for(int i=1;i<101;i++)
    {
        numberIsUsed[i] = false;
    }
    if(!CanFactor(low) || IsOK(high,low))
    {
        return true;
    }
    return false;
}

int main()
{
    int high,low;
    cin>>high>>low;
    //^（异或）用于交换
    if(high<low)
    {
        low = high ^ low;
        high = high ^ low;
        low = high ^ low;
    }
    if(IsHighWin(high,low))
    {
        cout<<high<<endl;
    }else
    {
        cout<<low<<endl;
    }
    return 0;
}
