#include<bits/stdc++.h>
using namespace std;
#define mx_value 1100000
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int test,cs;
    cin>>test;
    for(cs=1;cs<=test;cs++)
    {
        int nodes,edges;
        cin>>nodes>>edges;
        int matrix[nodes+1][nodes+1];
        int next[nodes+1][nodes+1];
        int u,v;
        for(int i=1;i<=nodes;i++)
        {
            for(int j=1;j<=nodes;j++)
            {
                matrix[i][j]=mx_value;
                next[i][j]=j;
                if(i==j)
                    matrix[i][j]=0;
            }
        }
        for(int i=0;i<edges;i++)
        {
            cin>>u>>v;
            u++;
            v++;
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
        int source,destination;
        cin>>source>>destination;
        source++;
        destination++;
        for(int k=1;k<=nodes;k++)
        {
            for(int i=1;i<=nodes;i++)
            {
                for(int j=1;j<=nodes;j++)
                {
                    if(matrix[i][k]+matrix[k][j]<matrix[i][j])
                    {
                        matrix[i][j]=matrix[i][k]+matrix[k][j];
                        next[i][j]=next[i][k];
                    }
                }
            }
        }
        int temp=matrix[source][destination];
        for(int i=1;i<=nodes;i++)
        {
            temp=max(temp,matrix[source][i]+matrix[i][destination]);
        }
        cout<<"Case "<<cs<<": "<<temp<<endl;
    }
}
