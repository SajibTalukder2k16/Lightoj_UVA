#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

///find_by_order(), order_of_key()
int main()
{
    ordered_set os;
    ordered_set ::iterator it;
    os.insert(15);
    os.insert(15);
    os.insert(15);
    os.insert(15);
    os.insert(10);
    os.insert(12);
    os.insert(13);
    os.insert(1);
    os.insert(20);
    for(it=os.begin();it!=os.end();it++)
        cout<<*it<<endl;
    cout<<"Find by order: "<< *(os.find_by_order(1)) <<endl;
    cout<<"Order of key: "<< os.order_of_key(15)<<endl;
}
