#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<map>

using namespace std;

int main()
{
    freopen("A-large-practice.in", "r", stdin);
    freopen("out.txt", "w", stdout);


    char buf[101];
    int T;
    gets(buf);
    sscanf(buf,"%d",&T);
    for(int t=1; t<=T; t++)
    {
        int S;
        gets(buf);
        sscanf(buf,"%d", &S);
        map<string,int> mp;

        for(int i=0; i<S; i++)
        {
            gets(buf);
            //string str(buf);
            //mp[str]=i;
        }

        int Q;
        gets(buf);
        sscanf(buf,"%d",&Q);
        //int* Qi = new int[Q];
        map<string,int>mp2;

        int seg = 0;
        for(int i=0, j=0; i<Q; i++)
        {
            gets(buf);
            string str(buf);
            mp2[str] = i;
            if(mp2.size() == S)
            {
                mp2.clear();
                mp2[str]=i;
                seg++;
            }
        }

        cout<<"Case #"<<t<<": "<<seg<<endl;

    }

    return 0;
}
