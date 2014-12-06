#include <iostream>

using namespace std;

void Init(char **a,char **b,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[i][j] = a[i][j];
        }
    }
}

void Calculate(char **b,int n,int *max)
{
    int tmp=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j] == 'o')
                tmp++;
        }
    }
    if(tmp > *max)
    {
        *max = tmp;
    }
}

void Choose(char **a,int i,int j,int n,int *max)
{
    char **b = new char*[n];
    for(int i=0;i<n;i++)
    {
        b[i] = new char[n];
    }
    Init(a,b,n);
    if(b[i][j] == '.')
    {
        b[i][j]='o';
        for(int p=j+1;p<n;p++)
        {
            if(b[i][p]=='.')
            {
                b[i][p]='X';
            }else
            {
                break;
            }
        }
        for(int p=i+1;p<n;p++)
        {
            if(b[p][j]=='.')
            {
                b[p][j]='X';
            }else
            {
                break;
            }
        }
        for(int p=j-1;p>-1;p--)
        {
            if(b[i][p]=='.')
            {
                b[i][p]='X';
            }else
            {
                break;
            }
        }
        for(int p=i-1;p>-1;p--)
        {
            if(b[p][j]=='.')
            {
                b[p][j]='X';
            }else
            {
                break;
            }
        }
    }
    for(int k=i;k<n;k++)
    {
        int l;
        if(k==i)
        {
            l = j;
        }else
        {
            l = 0;
        }
        for(;l<n;l++)
        {
            if(k==n-1 && l==n-1)
            {
                Calculate(b,n,max);
                return;
            }else if(l == n-1)
            {
                Choose(b,k+1,0,n,max);
            }else
            {
                Choose(b,k,l+1,n,max);
            }
        }
    }

    for(int i=0;i<j;i++)
    {
        delete[]b[i];
    }
    delete[]b;
}

int main()
{
    char **a;
    int n,max=0;
    while(1)
    {
        cin>>n;
        if(n == 0)
        {
            break;
        }
        a = new char*[n];
        for(int i=0;i<n;i++)
        {
            a[i] = new char[n];
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                Choose(a,i,j,n,&max);
            }
        }
        cout<<max<<endl;
        max = 0;
    }
    for(int i=0;i<n;i++)
    {
        delete[]a[i];
    }
    delete[]a;
    return 0;
}
