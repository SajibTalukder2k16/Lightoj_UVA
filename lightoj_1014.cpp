#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int cs,test;
    cin>>test;
    for(cs=1;cs<=test;cs++)
    {
        int d,p,l;
        cin>>p>>l;
        int rem = p-l;
        int sq=sqrt(rem);
        vector<int>f,b;
        for(d=1;d<=sq;d++)
        {
            if(rem%d==0)
            {
                if(d>l)
                    f.push_back(d);
                int temp = rem/d;
                if(temp!=d)
                    if(temp>l)
                        b.push_back(temp);
            }
        }
        cout<<"Case "<<cs<<": ";
        //cout<<p<<" "<<l<<endl;
        int fsz = f.size();
        int bsz = b.size();
        if(fsz==0 && bsz==0)
        {
            cout<<"impossible"<<endl;
            continue;
        }
        //cout<<fsz<<" "<<bsz<<endl;
        bool chk=false;
        for(int i=0;i<fsz;i++)
        {
            chk=true;
            if(i!=0)
                cout<<" "<<f[i];
            else
                cout<<f[i];
        }
        for(int i=bsz-1;i>=0;i--)
        {
            if(chk==false && i==bsz-1)
                cout<<b[i];
            else
                cout<<" "<<b[i];

        }
        cout<<endl;

    }
}
