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
///BigMod
/*
ll BigMod(ll base,ll power,ll mod)
{
    if(power==0)
        return 1;
    if(power%2==1)
        return (base%mod)*(BigMod(base,power-1,mod)%mod)%mod;
    else
    {
        ll res = (BigMod(base,power/2,mod)%mod);
        return (res*res)%mod;

    }
}
*/
#define sz 505
char maze[sz][sz];
bool visited[sz][sz]={0};
bool VisitToSet[sz][sz]={0};
int result[sz][sz]={0};
int m,n;
int dfsVisit(int x,int y)
{
    visited[x][y]=true;
    int res=0;
    for(int k=0;k<4;k++)
    {
        int newx=x+fx[k];
        int newy=y+fy[k];
        if(newx>=0 && newx<m && newy>=0 && newy<n)
            if(visited[newx][newy]==false && maze[newx][newy]!='#')
            {
                if(maze[newx][newy]=='C')
                    res+=1+dfsVisit(newx,newy);
                else
                    res+=dfsVisit(newx,newy);
            }
    }
    return res;
}
void dfsToSet(int x,int y,int res)
{
    VisitToSet[x][y]=true;
    result[x][y]=res;
    for(int k=0;k<4;k++)
    {
        int newx=x+fx[k];
        int newy=y+fy[k];
        if(newx>=0 && newx<m && newy>=0 && newy<n)
            if(VisitToSet[newx][newy]==false && maze[newx][newy]!='#')
            {
                dfsToSet(newx,newy,res);
            }
    }
    return;
}
void allVisit()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==false && maze[i][j]!='#')
            {
                int res = dfsVisit(i,j);
                if(maze[i][j]=='C')
                    res+=1;
                dfsToSet(i,j,res);
            }
        }
    }
}
int main()
{
    //fileRead
    //fileWrite
    int test_case;
    scanf("%d",&test_case);
    for(int cs=1;cs<=test_case;cs++)
    {
        int q;
        memset(result,0,sizeof result);
        memset(visited,false,sizeof visited);
        memset(VisitToSet,false,sizeof VisitToSet);
        scanf("%d%d%d\n",&m,&n,&q);
        for(int i=0;i<m;i++)
        {
            scanf("%s",maze[i]);
        }
        int x,y;
        printf("Case %d:\n",cs);
        allVisit();
        while(q--)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",result[x-1][y-1]);
        }
    }
}
