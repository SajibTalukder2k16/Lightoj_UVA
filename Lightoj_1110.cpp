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
///lightoj 1110
string lcs_dp[101][101]={""};
bool visited[101][101]={false};
string longest_common_sub(int i,int j,string &a,string &b)
{
    if(visited[i][j]==true)
        return lcs_dp[i][j];
    visited[i][j]=true;
    string ret="";
    if(i==a.length()||j==b.length())
        return "";

    if(a[i]==b[j])
    {
        ret=a[i]+longest_common_sub(i+1,j+1,a,b);
    }
    else
    {
        string value1=longest_common_sub(i+1,j,a,b);
        string value2=longest_common_sub(i,j+1,a,b);
        int sz1=value1.size();
        int sz2=value2.size();
        if(sz1==sz2)
        {
           if(value1.compare(value2)<0)
                ret=value1;
           else
                ret=value2;
        }
        else if(sz1>sz2)
            ret=value1;
        else
            ret=value2;
    }
    return lcs_dp[i][j]=ret;

}
int main()
{
    //fileRead
    //fileWrite
    int test_case;
    cin>>test_case;
    lightoj_test_case_loop(test_case)
    {
        string a,b;
        cin>>a>>b;
        string ret = longest_common_sub(0,0,a,b);
        if(ret.size()==0)
            lightoj_output<<":("<<endl;
        else
            lightoj_output<<ret<<endl;
        for(int i=0;i<101;i++)
            for(int j=0;j<101;j++)
            {
                lcs_dp[i][j]="";
                visited[i][j]=false;
            }
        //cout<<ret<<" "<<ret.size()<<endl;
    }
}
