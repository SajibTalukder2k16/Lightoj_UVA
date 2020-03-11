#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
string firstcube,secondcube;
void rotate_xwise()
{
    char carry = firstcube[4];
    firstcube[4]=firstcube[5];
    firstcube[5]=firstcube[1];
    firstcube[1]=firstcube[0];
    firstcube[0]=carry;
}
void rotate_ywise()
{
    char temp = firstcube[4];
    firstcube[4]=firstcube[3];
    firstcube[3]=firstcube[1];
    firstcube[1]=firstcube[2];
    firstcube[2]=temp;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string str;
    while(cin>>str)
    {
        firstcube="";
        secondcube="";
        for(int i=0;i<6;i++)
            firstcube+=str[i];
        for(int i=6;i<12;i++)
            secondcube+=str[i];
        bool check = false;
        for(int i=0;i<6;i++)
        {
            if(firstcube==secondcube)
            {
                check=true;
                break;
            }
            else if(i<4)
            {
                rotate_xwise();
            }
            else if(i==4)
            {
                rotate_ywise();
                rotate_xwise();
            }
            else
            {
                rotate_xwise();
                rotate_xwise();
            }
            for(int j=0;j<4;j++)
            {
                if(firstcube==secondcube)
                {
                    check=true;
                    break;
                }
                rotate_ywise();
            }
        }
        if(check)
        {
            cout<<"TRUE"<<endl;
        }
        else
        {
            cout<<"FALSE"<<endl;
        }
    }
}
