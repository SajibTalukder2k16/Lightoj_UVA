#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>segment_vector[390];
vector<int>vec;
int segment_size ;
int cur_index;
int cur_segment=-1;
void preprocess()
{
    for(int i=0;i<390;i++)
        segment_vector[i].clear();
    int sz = vec.size();
    segment_size = sqrt(150010);
    for(int i=0;i<sz;i++)
    {
        if(i%segment_size==0)
        {
            cur_segment++;
        }
        segment_vector[cur_segment].push_back(vec[i]);
    }
}
void remove_element(int pos)
{
    pos--;
    int sz = 0;
    int i = 0;
    while(sz+segment_vector[i].size()<=pos && i<segment_size)
    {
        sz+=segment_vector[i].size();
        i++;
    }
    if(sz+segment_vector[i].size()>pos)
    {
        int value = segment_vector[i][pos-sz];
        segment_vector[i].erase(segment_vector[i].begin()+pos-sz);
        printf("%d\n",value);
    }
    else
        printf("none\n");
}
void add_element(int num)
{
    if(cur_segment==-1)
        cur_segment++;
    int sz = segment_vector[cur_segment].size();
    if(sz<segment_size)
        segment_vector[cur_segment].push_back(num);
    else
    {
        cur_segment++;
        segment_vector[cur_segment].push_back(num);
    }
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int test;
    scanf("%d",&test);
    for(int cs=1;cs<=test;cs++)
    {
        vec.clear();
        int n,q;
        scanf("%d%d",&n,&q);
        int num;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            vec.push_back(num);
        }
        preprocess();
        cur_index = n;
        char ch;
        int k;
        int remove_cnt = 0;
        getchar();
        printf("Case %d:\n",cs);
        for(int i=0;i<q;i++)
        {
            scanf("%c%d",&ch,&k);
            getchar();
            if(ch=='a')
            {
                add_element(k);
            }
            else if(ch=='c')
            {
                remove_element(k);
            }
        }

    }
}
