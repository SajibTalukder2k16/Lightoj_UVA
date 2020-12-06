#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define lightoj_test_case_loop(test) for(int cs=1;cs<=test;cs++)
#define lightoj_output cout<<"Case "<<cs<<": "
#define pb push_back
#define mp make_pair
#define white 0
#define grey 1
#define black 2
#define ll long long
#define ii_pair pair<int,int>
int fx[]={+1,-1,0,0};
int fy[]={0,0,+1,-1};
int turnOn(int x,int pos) {
    return x | (1<<pos-1);
}
bool isOn(int N,int pos) {
    return (bool)(N & (1<<pos-1));
}
int main()
{
    int d1,v1,d2,v2,p;
    cin>>d1>>v1>>d2>>v2>>p;
    int mn=min(d1,d2);
    int sum=0;
    int temp;
    if(d1==d2)
    {
        sum=(p/(v1+v2));
        if(p%(v1+v2)!=0)
            sum++;
        sum+=d1-1;
    }
    else
    {
        int res;
        if(mn==d1)
            temp=(p/v1);
        else
            temp=(p/v2);
        if(mn==d1&& p%v1!=0)
            temp++;
        else if(mn==d2 && p%v2!=0)
            temp++;
        int single = abs(d2-d1);
        if(single>=temp)
            sum=temp;
        else
        {
            sum=single;
        }
        //cout<<temp<<" "<<single<<" "<<sum<<endl;
        if(mn==d1)
            res=sum*v1;
        else
            res=sum*v2;

        //cout<<"Res: "<<res<<endl;
        int ans=p-res;
        sum+=(ans/(v1+v2));
        if(ans%(v1+v2)!=0)
            sum++;
        sum+=mn-1;
    }
    cout<<sum<<endl;
}
