#include<bits/stdc++.h>
using namespace std;
#define mx 1000001
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tests,cs;
    cin>>tests;
    for(cs=1;cs<=tests;cs++)
    {
        int n,temp;
        cin>>n;
        set<int>st;
        set<int>::iterator it;
        int ara[mx];
        memset(ara,0, sizeof ara);
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            ara[temp]++;
            st.insert(temp);
        }
        long long sum = 0;
        for(it=st.begin();it!=st.end();it++)
        {
            /// example: n = 6 , answer of of 6 people 3 3 3 3 3 3 first 4 person can be a group,  count of 3 is 6, 6/(3+1) = 1 ,then multiply 1*(3+1) = 4 , 6 %(3+1) = 2 ,2 more needed .when the mod value is not zero i add the (3+1) value as some person of same choice remained;
            int ans = ara[*it]/(*it+1);
            ans = ans * (*it+1);
            int mod = ara[*it]%(*it+1);
            if(mod!=0)
                ans+=(*it+1);
            sum += ans;

        }
        cout<<"Case "<<cs<<": "<<sum<<endl;

    }
}
