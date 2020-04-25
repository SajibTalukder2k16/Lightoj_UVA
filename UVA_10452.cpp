#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
#define white 0
#define grey 1
#define black 2
char grid[8][8];
int m,n;
///IEHOVA
///UVA 10452
bool check = false;
string dfs_visit(int x,int y,string str,string direction)
{
    //cout<<str<<" "<<direction<<endl;
    if(str=="@IEHOVA#")
    {
        check = true;
        return direction;
    }
    if(check==false && y-1>=0 && (str+grid[x][y-1]=="@I"||str+grid[x][y-1]=="@IE"||str+grid[x][y-1]=="@IEH"|| str+grid[x][y-1]=="@IEHO"||str+grid[x][y-1]=="@IEHOV"||str+grid[x][y-1]=="@IEHOVA"||str+grid[x][y-1]=="@IEHOVA#"))
        return dfs_visit(x,y-1,str+grid[x][y-1],direction+="L");
    if(check==false && y+1<n && (str+grid[x][y+1]=="@I"||str+grid[x][y+1]=="@IE"||str+grid[x][y+1]=="@IEH"|| str+grid[x][y+1]=="@IEHO"||str+grid[x][y+1]=="@IEHOV"||str+grid[x][y+1]=="@IEHOVA"||str+grid[x][y+1]=="@IEHOVA#"))
        return dfs_visit(x,y+1,str+grid[x][y+1],direction+="R");
    if(check==false && x-1>=0 && (str+grid[x-1][y]=="@I"||str+grid[x-1][y]=="@IE"||str+grid[x-1][y]=="@IEH"|| str+grid[x-1][y]=="@IEHO"||str+grid[x-1][y]=="@IEHOV"||str+grid[x-1][y]=="@IEHOVA"||str+grid[x-1][y]=="@IEHOVA#"))
        return dfs_visit(x-1,y,str+grid[x-1][y],direction+="F");
}

int main()
{
    fastread
    //fileRead
    //fileWrite
    int test;
    cin>>test;
    while(test--)
    {
        cin>>m>>n;
        int x,y;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='@')
                    x=i,y=j;
            }
        string direction = dfs_visit(x,y,"@","");
        for(int i=0;i<direction.length();i++)
        {
            if(direction[i]=='R')
                if(i==0)
                    cout<<"right";
                else
                    cout<<" right";//<<endl;
            else if(direction[i]=='L')
                if(i==0)
                    cout<<"left";
                else
                    cout<<" left";//<<endl;
            else if(direction[i]=='F')
                if(i==0)
                    cout<<"forth";
                else
                    cout<<" forth";//<<endl;
        }
        //cout<<direction<<endl;
        cout<<endl;
        check = false;

    }
}
