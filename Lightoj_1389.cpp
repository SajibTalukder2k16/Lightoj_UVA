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
int fx[]={+1,-1,0,0};
int fy[]={0,0,+1,-1};
int turnOn(int x,int pos) {
    return x | (1<<pos-1);
}
bool isOn(int N,int pos) {
    return (bool)(N & (1<<pos-1));
}
///lcs using dp
/*
int lcs_dp[31][31]={0};
int longest_common_sub(int i,int j,string &a,string &b)
{
    if(i==a.length()||j==b.length())
        return 0;
    if(lcs_dp[i][j]!=-1)
        return lcs_dp[i][j];
    int ans=0;
    if(a[i]==b[j])
        ans=1+longest_common_sub(i+1,j+1,a,b);
    else
        ans=max(longest_common_sub(i+1,j,a,b),longest_common_sub(i,j+1,a,b));
    return lcs_dp[i][j]=ans;

}
*/
///lightoj 1389
int main()
{
    int test_case;
    cin>>test_case;
    lightoj_test_case_loop(test_case)
    {
        int n;
        cin>>n;
        string ara;
        cin>>ara;
        int prev=-1;
        int ans=0;
        bool done = true;
        int lastdotindex=-1;
        for(int i=0;i<n;i++)
        {
            if(ara[i]=='.')
                lastdotindex=i;
            if(done==true && ara[i]=='.')
            {
                prev=i;
                done=false;
            }
            else if(done==false && ara[i]=='#')
            {
                int temp = i-prev;
                if((i==n-1)||(i+1<n && ara[i+1]=='#'))
                {
                    ans+=ceil(temp/3.0);
                    done=true;
                    continue;
                }
                if(temp%3==0 || temp%3==2)
                {
                    ans+=ceil(temp/3.0);
                    done=true;
                    continue;
                }
            }
        }
        if(done==false)
        {
            ans+=ceil((lastdotindex-prev+1)/3.0);
        }
        lightoj_output<<ans<<endl;
    }
}
