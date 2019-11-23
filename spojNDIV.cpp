#include<bits/stdc++.h>
using namespace std;
int nod(int num)
{
    //cout<<num<<endl;
   int sqrtn=sqrt(num);
   int i;
   int res=1;
   for(i=2;i<=sqrtn;i++)
   {
       int cnt=0;
       if(num%i==0)
       {
           while(num%i==0)
           {
               num/=i;
               cnt++;
           }
           cnt++;
           res*=cnt;
           sqrtn=sqrt(num);
       //cout<<res<<" "<<cnt<<" "<<sqrtn<<endl;
       }
   }
   if(num!=1)
    res*=2;
   return res;
}
int main()
{
   int a,b,n;
   cin>>a>>b>>n;
   int i;
   int cnt=0;
   for(i=a;i<=b;i++)
   {
       if(nod(i)==n)
        cnt++;
   }
   cout<<cnt<<endl;
}
