#include<bits/stdc++.h>
using namespace std;
#define mx 201
int nodes,edges;
int parent[mx];
struct edge_prop{

    int from_node,to_node,cost;

    edge_prop(int x,int y,int z)
    {
        from_node=x;
        to_node=y;
        cost=z;
    }
};
class compare
{
public:
    bool operator()(edge_prop &p,edge_prop &q)
    {
        return p.cost<q.cost;
    }
};
vector<edge_prop>vec_of_edges;
int find_parent(int u)
{
    if(u==parent[u])
        return u;
    else
    {
        parent[u]=find_parent(parent[u]);
        return parent[u];
    }
}
int kruskal_mst()
{
    sort(vec_of_edges.begin(),vec_of_edges.end(),compare());
    for(int i=1;i<=nodes;i++)
        parent[i]=i;
    int counting=0;
    int sum=0;
    int sz=vec_of_edges.size();
    vector<edge_prop>temp_vec;
    int u,v;
    for(int i=0;i<sz;i++)
    {
        edge_prop temp = vec_of_edges[i];
        u = find_parent(temp.from_node);
        v = find_parent(temp.to_node);
        if(u!=v)
        {
            temp_vec.push_back(temp);
            parent[u]=v;
            sum+=temp.cost;
            counting++;
            if(counting==nodes-1)
                break;
        }
    }
    vec_of_edges.clear();
    vec_of_edges=temp_vec;///Here updating the vector of lowest cost of edges , by doing this I ignore those edges which cost is greater
    if(counting==nodes-1)
        return sum;
    else
        return -1;

}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test,cs;
    //cin>>test;
    scanf("%d",&test);
    for(cs=1;cs<=test;cs++)
    {
        //cin>>nodes>>edges;
        scanf("%d%d",&nodes,&edges);
        int x,y,z;
        //cout<<"Case "<<cs<<":"<<endl;
        printf("Case %d:\n",cs);
        for(int i=0;i<edges;i++)
        {
            //cin>>x>>y>>z;
            scanf("%d%d%d",&x,&y,&z);
            edge_prop temp(x,y,z);
            vec_of_edges.push_back(temp);
            printf("%d\n",kruskal_mst());
            //cout<<kruskal_mst()<<endl;
        }
        vec_of_edges.clear();
    }

}
