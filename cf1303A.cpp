#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        string s;
        cin>>s;
        int l=s.length();
        int sum = 0;
        int prevone=-1,curone=-1;
        bool check = false;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='1')
            {
                prevone=curone;
                curone=i;
                if(check==true)
                {
                    sum+=curone-prevone-1;
                    //cout<<curone<<" "<<prevone<<" "<<sum<<endl;
                    prevone=curone;
                }
                check=true;
            }
 
        }
        cout<<sum<<endl;
    }
}
