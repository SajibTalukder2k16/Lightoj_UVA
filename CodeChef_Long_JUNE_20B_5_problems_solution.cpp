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
#define sz 1001
vector<int>adj_node[sz];
int no_of_node;
int minimum_vertex_cover()
int main()
{
    while(true)
    {
        cin>>no_of_node;
        if(no_of_node==0)
            break;
        for(int i=1;i<=no_of_node;i++)
        {
            int n,node;
            cin>>n
            for(int j=0;j<n;j++)
            {
                cin>>node;
                adj_node[i].pb(node);
            }
        }

    }
}
///JUNE 20B
///EVENM
/*
#define sz 1002
int matrix[sz][sz];
int cur_value=0;
int row;
void SetValueDown(int x,int y);
void SetValueLeft(int x,int y);
void SetValueUp(int x,int y);
void SetValueRight(int from_row,int from_col)
{
    bool check = false;
    while(matrix[from_row][from_col]==-1 && from_col<=row)
    {
        matrix[from_row][from_col]=++cur_value;
        from_col++;
        check = true;
    }
    if(check==false)
        return;
    SetValueDown(from_row+1,from_col-1);
}
void SetValueDown(int from_row,int from_col)
{
    bool check = false;
    while(matrix[from_row][from_col]==-1 && from_row<=row)
    {
        matrix[from_row][from_col]=++cur_value;
        from_row++;
        check = true;
    }
    if(check==false)
        return;
    SetValueLeft(from_row-1,from_col-1);
}
void SetValueLeft(int from_row,int from_col)
{
    bool check = false;
    while(matrix[from_row][from_col]==-1 && from_col>=1)
    {
        matrix[from_row][from_col]=++cur_value;
        from_col--;
        check = true;
    }
    if(check==false)
        return;
    SetValueUp(from_row-1,from_col+1);
}
void SetValueUp(int from_row,int from_col)
{
    bool check = false;
    while(matrix[from_row][from_col]==-1 && from_row>=1)
    {
        matrix[from_row][from_col]=++cur_value;
        from_row--;
        check=true;
    }
    if(check==false)
        return;
    SetValueRight(from_row+1,from_col+1);
}
void printMatrix()
{
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=row;j++)
        {
            if(j==1)
                printf("%d",matrix[i][j]);
            else
                printf(" %d",matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int test_case;
    scanf("%d",&test_case);
    while(test_case--)
    {
        scanf("%d",&row);
        memset(matrix,-1,sizeof matrix);
        cur_value=0;
        SetValueRight(1,1);
        printMatrix();
    }
}
*/
///EOEO
/*
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        ll num;
        cin>>num;
        if(num%2==1)
        {
            cout<<num/2<<endl;
        }
        else
        {
            while(num%2==0)
                num/=2;
            cout<<num/2<<endl;
        }
    }
}
*/
///CHFICRM
/*
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int no_of_people;
        cin>>no_of_people;
        int coin_value;
        int ara[3]={0,0,0};
        int peoples_coin[no_of_people];
        for(int i=0;i<no_of_people;i++)
            cin>>peoples_coin[i];
        bool printed = false;
        for(int i=0;i<no_of_people;i++)
        {
            coin_value=peoples_coin[i];
            if(coin_value==15)
            {
                if(ara[1]>0)
                {
                    ara[1]-=1;
                    ara[2]++;
                }
                else if(ara[0]>1)
                {
                    ara[0]-=2;
                    ara[2]++;
                }
                else
                {
                    cout<<"NO"<<endl;
                    printed=true;
                    break;
                }
            }
            else if(coin_value==10)
            {
                if(ara[0]>0)
                {
                    ara[0]-=1;
                    ara[1]+=1;
                }
                else
                {
                    cout<<"NO"<<endl;
                    printed=true;
                    break;
                }
            }
            else
                ara[0]++;
        }
        if(printed==false)
            cout<<"YES"<<endl;
    }
}
*/
///XYSTR
/*
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        string s;
        cin>>s;
        int l = s.length();
        int cnt=0;
        for(int i=1;i<l;i++)
        {
            if(s[i]!=s[i-1])
            {
                cnt++;i++;
            }
        }
        cout<<cnt<<endl;
    }
}
*/
///pricecon
/*
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int n,k;
        cin>>n>>k;
        int num;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            if(num>k)
                sum+=num-k;
        }
        cout<<sum<<endl;
    }
}
*/
