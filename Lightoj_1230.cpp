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
///lightoj 1230
#define sz 1001
vector<int>adj_node[sz];
int no_of_node;
ii_pair dp[sz][2];
bool visited[sz]={false};
ii_pair minimum_vertex_cover(int cur_node,bool guard,int par)
{
    visited[cur_node]=true;
    if(dp[cur_node][guard].first!=-1)
    {
        return dp[cur_node][guard];
    }
    int ans = guard;
    int two_lamp_cover = 0;
    for(int i=0;i<adj_node[cur_node].size();i++)
    {
        int v=adj_node[cur_node][i];
        if(v!=par)
        {
            if(guard==false)
            {
                ii_pair temp = minimum_vertex_cover(v,true,cur_node);
                ans+=temp.first;
                two_lamp_cover+=temp.second;
            }
            else
            {
                ii_pair ans1 = minimum_vertex_cover(v,true,cur_node);
                ii_pair ans2 = minimum_vertex_cover(v,false,cur_node);
                int p1=ans1.first;
                int p2=ans2.first;
                int p3=ans1.second;
                int p4=ans2.second;
                int mn = min(ans1.first,ans2.first);
                ans+=mn;
                if(p1==p2)
                {
                    int temp_max = max(p3,p4);
                    if(temp_max==p3)
                        two_lamp_cover+=1+p3;
                    else
                        two_lamp_cover+=p4;
                }
                else
                {
                    if(p1==mn)
                        two_lamp_cover+=1+p3;
                    else
                        two_lamp_cover+=p4;
                }
            }
        }
    }
    dp[cur_node][guard]=make_pair(ans,two_lamp_cover);
    return dp[cur_node][guard];

}
int main()
{
    //fileRead
    //fileWrite
    int test_case;
    cin>>test_case;
    lightoj_test_case_loop(test_case)
    {
        int no_of_node,no_of_edges;
        cin>>no_of_node>>no_of_edges;
        int a,b;
        int mx = INT_MAX;
        int start_point = 1;
        for(int i=0;i<no_of_edges;i++)
        {
            cin>>a>>b;
            a++,b++;
            adj_node[a].pb(b);
            adj_node[b].pb(a);
        }

        memset(dp,-1,sizeof dp);
        memset(visited,0,sizeof visited);
        int res = 0,total_two_lamp=0;

        for(int i=1;i<=no_of_node;i++)
        {
            if(visited[i]==false)
                start_point = i;
            else
                continue;
            int two_lamp_cover;
            ii_pair ans1 = minimum_vertex_cover(start_point,true,start_point);
            ii_pair ans2 = minimum_vertex_cover(start_point,false,start_point);
            int p1=ans1.first;
            int p2=ans2.first;
            int p3=ans1.second;
            int p4=ans2.second;
            int mn = min(ans1.first,ans2.first);
            if(p1==p2)
            {
                two_lamp_cover = max(p3,p4);
            }
            else
            {
                if(p1==mn)
                    two_lamp_cover=p3;
                else
                    two_lamp_cover=p4;
            }
            res+=mn;
            total_two_lamp+=two_lamp_cover;
        }

        lightoj_output<<res<<" "<<total_two_lamp<<" "<<no_of_edges-total_two_lamp<<endl;
        for(int i=1;i<=no_of_node;i++)
            adj_node[i].clear();
    }

}
