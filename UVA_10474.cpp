#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
int main()
{
    fastread
    int cs=1;
    while(true)
    {
        int n,q;
        cin>>n>>q;
        if(n==0 && q==0)
            break;
        vector<int>vec;
        int num;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            vec.push_back(num);
        }
        sort(vec.begin(),vec.end());
        cout<<"CASE# "<<cs++<<":"<<endl;
        for(int i=0;i<q;i++)
        {
            cin>>num;
            int pos = lower_bound(vec.begin(),vec.end(),num)-vec.begin();
            if(vec[pos]==num)
            {
                cout<<num<<" found at "<<pos+1<<endl;
            }
            else
            {
                cout<<num<<" not found"<<endl;
            }
        }
    }
}
