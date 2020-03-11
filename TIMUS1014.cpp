#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
int main()
{
    int n;
    cin>>n;
    if(n==0)
        cout<<10<<endl;///as 0 is not a positive number so minimum q is 10 . which products of digit is 0
    else if(n==1)
        cout<<1<<endl;///as 1 is not handle in the loop so it is specially handled
    else
    {
        vector<char>vec;
        for(int i=9;i>1;i--)
        {
            while(n%i==0)
            {
                vec.push_back(i+48);
                n/=i;
            }
        }
        if(n!=1)
            cout<<-1<<endl;
        else
        {
            sort(vec.begin(),vec.end());
            for(int i=0;i<vec.size();i++)
                cout<<vec[i];
            cout<<endl;
        }
    }
}
