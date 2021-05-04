#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define mx 1000005
ll ext_gcd ( ll A, ll B, ll &X, ll &Y ){
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    X = x2; Y = y2;
    if(r2<0)
        X*=-1,Y*=-1,r2*=-1;
    return r2;
}
ll BigMod(ll base,ll power,ll mod)
{
    if(power==0)
        return 1;
    if(power%2==1)
        return (base%mod)*(BigMod(base,power-1,mod)%mod)%mod;
    else
    {
        ll res = (BigMod(base,power/2,mod)%mod);
        return (res*res)%mod;
    }
}
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = ext_gcd(a,b, x0, y0);
    if (c % g) {
        return false;
    }
    if ( g < 0 )
    {
        a *= -1; b *= -1; c *= -1;
    }
    x0 *= c; y0 *= c;
    return true;
}
ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy)
{
    if(a==0 && b==0)
    {
        if(c!=0)
            return 0;
        else
        {
            return (abs(maxx - minx) + 1) * (abs(maxy - miny) + 1);
        }
    }
    if(a==0||b==0)
    {
        if(a!=0)
        {
            if(c%a!=0)
                return 0;
            else
            {
                ll v=c/a;
                if(minx<=v && v<=maxx)
                    return abs(miny-maxy)+1;
                else
                    return 0;
            }
        }
        if(b!=0)
        {
            if(c%b!=0)
                return 0;
            else
            {
                ll v=c/b;
                if(miny<=v && v<=maxy)
                    return abs(minx-maxx)+1;
                else
                    return 0;
            }
        }

    }
    ll x, y,g;
    g=__gcd(a,b);
    if(c%g!=0)
        return 0;
    a /= g;
    b /= g;
    c /= g;
    ext_gcd(a,b,x,y);
    ll x0=x*c,y0=y*c;
    ll lkx=ceil((double)(minx-x0)/(double)(b));
    ll rkx=floor((double)(maxx-x0)/(double)(b));
    ll lky=ceil((double)(y0-maxy)/(double)(a));
    ll rky=floor((double)(y0-miny)/(double)(a));

    ll p=max(lkx,lky);
    ll q=min(rkx,rky);
    if(p>q)
        return 0;
    else
        return q-p+1;
}
int main()
{
    //fileRead
    //fileWrite
    int test;
    cin>>test;
    for(int cs=1;cs<=test;cs++)
    {
        ll a,b,c,x1,x2,y1,y2;
        cin>>a>>b>>c>>x1>>x2>>y1>>y2;
        c*=-1;
        if(a < 0)
        {
            a = -a;
            swap(x1, x2);
            x1 = -x1;
            x2 = -x2;
        }
        if(b < 0)
        {
            b = -b;
            swap(y1, y2);
            y1 = -y1;
            y2 = -y2;
        }
        ll ans=find_all_solutions(a,b,c,x1,x2,y1,y2);
        cout<<"Case "<<cs<<": "<<ans<<endl;
    }
}
