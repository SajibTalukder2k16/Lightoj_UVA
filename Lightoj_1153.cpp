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

///lightoj 1153 trying
#define sz 101
int matrix[sz][sz];
int source,destination;
bool visited[sz]={false};
int no_of_node;
int dfs_visit(int u,int mn)
{
    visited[u]=true;
    if(u==destination)
    {
        return mn;
    }
    for(int i=1;i<=no_of_node;i++)
    {
        if(matrix[u][i]==-1)
            continue;
        int v=i;
        int c=matrix[u][i];
        if(visited[v]==false && visited[destination]==false && min(mn,c)>0)
        {
            int res = dfs_visit(v,min(mn,c));
            //cout<<"Res: "<<res<<endl;
            if(visited[destination]==true)
            {
                //cout<<"Cost komar age: "<<matrix[u][v]<<endl;
                matrix[u][v]-=res;
                matrix[v][u]+=res;
                //cout<<u<<" "<<v<<" cost kombe: "<<res<<" cost komar por: "<<matrix[u][v]<<endl;
                return res;
            }
        }
    }
    return 0;
}
int main()
{
    //fileRead
    //fileWrite
    int test_case;
    cin>>test_case;
    lightoj_test_case_loop(test_case)
    {
        cin>>no_of_node;
        int routes;
        cin>>source>>destination>>routes;
        int n1,n2,cost;
        memset(matrix,-1,sizeof matrix);
        for(int i=0;i<routes;i++)
        {
            cin>>n1>>n2>>cost;
            if(matrix[n1][n2]!=-1)
            {
                matrix[n1][n2]+=cost;
                matrix[n2][n1]+=cost;
            }
            else
            {
                matrix[n1][n2]=cost;
                matrix[n2][n1]=cost;
            }
        }
        int total = 0;
        while(true)
        {
            memset(visited,false,sizeof visited);
            int res = dfs_visit(source,INT_MAX);
            //cout<<"This res: "<<res<<endl;
            if(res<=0 || visited[destination]==false)
                break;
            total+=res;
        }
        lightoj_output<<total<<endl;
        //cout<<endl<<endl<<total<<endl;;

    }
}
