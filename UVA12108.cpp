#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int gcd(int a, int b) {
    if(a % b == 0) return b;
    else return gcd(b,a%b);
}

int lcm(int a, int b) {
    return a*b/gcd(a,b);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    int cs=1;
    while(true)
    {
        cin>>n;
        if(n==0)
            break;
        int a[n],b[n],c[n];
        int lcmvalue = 1;
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            lcmvalue = lcm(lcmvalue,a[i]+b[i]);
        }
        int extendedawaken[n]={0};
        bool sleep[n]={0};
        int prevsleeper;
        int time=-1;
        for(int j=1;j<=lcmvalue;j++)
        {
            int sleeper = 0;
            for(int i=0;i<n;i++)
            {
                if(j==1)
                {
                    int temp = c[i]%(a[i]+b[i]);
                    if(temp==0)
                        temp=a[i]+b[i];
                    if(temp>a[i])
                    {
                        sleep[i]=true;
                    }
                }
                else
                {
                    int temp = c[i]%(a[i]+b[i]);
                    if(temp==0)
                        temp=a[i]+b[i];
                    if(extendedawaken[i])
                    {
                        sleep[i]=false;
                        extendedawaken[i]--;
                    }
                    else if(temp==a[i]+1 && prevsleeper>(n/2))
                    {
                        sleep[i]=true;
                    }
                    else if(temp>a[i]+1)
                    {
                        sleep[i]=true;
                    }
                    else if(temp<=a[i])
                    {
                        sleep[i]=false;
                    }
                    else
                    {
                        extendedawaken[i]=b[i];
                        extendedawaken[i]--;
                        sleep[i]=false;
                    }
                }
                if(sleep[i]==true)
                    sleeper++;
                //cout<<"\t pos: "<<i<<" "<<sleep[i]<<endl;
                c[i]++;
            }
            if(sleeper==0)
            {
                time = j;
                break;
            }
            prevsleeper=sleeper;
        }
        cout<<"Case "<<cs++<<": "<<time<<endl;
    }
}
