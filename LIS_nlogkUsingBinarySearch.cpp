#include<bits/stdc++.h>
using namespace std;
#define mx 100001
#define inf INT_MAX
int sequence[mx];
int LIS[mx];
int III[mx];
int n;
int LISnlogk()
{
    III[0]=-inf;
    for(int i=1;i<=n;i++)
    {
        III[i]=inf;
    }
    int lislength = 0;
    for(int i=0;i<n;i++)
    {
        int low,mid,high;
        low = 0;
        high = lislength;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(III[mid]<sequence[i])
                low = mid+1;
            else
                high = mid-1;
        }
        III[low]=sequence[i];
        if(lislength<low)
            lislength=low;
    }
    return lislength;
}
