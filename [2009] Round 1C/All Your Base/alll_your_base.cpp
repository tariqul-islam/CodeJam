/*
CODE JAM: 2009: Round 1C
ALL YOUR BASE

-Written by
Mohammad Tariqul Islam
ponir.bd (at) hotmail.com
*/


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>

using namespace std;

int main()
{
    freopen("A-large-practice.in","r",stdin);
    freopen("output.txt","w",stdout);

    char buffer[62];
    int T;

    gets(buffer);
    sscanf(buffer, "%d", &T);

    for(int t=1; t<=T; t++)
    {
        gets(buffer);
        int len=strlen(buffer);
        map<char,int> m;
        long long base=2;

        //introduces the first caracter to 1
        m[buffer[0]]=1;

        int iter=1;

        //if more than one character then the next
        //un-introduced character mst be 0
        //finds it and introduces it to zero
        if(len>1)
        {
            for(int i=iter; i<len; i++)
            {
                if(m.find(buffer[i])==m.end())
                {
                    m[buffer[i]]=0;
                    iter=i;
                    break;
                }
            }
        }

        //introduces other un-introduced characters to
        //2 3 .... and increments base as well
        for(int i=iter+1; i<len; i++)
        {
            if(m.find(buffer[i])==m.end())
            {
                m[buffer[i]]=base;
                base++;
            }
        }


        //computes the number in decimal according
        //to the base
        long long result=0;
        long long power=1;
        for(int i=len-1,j=0; i>=0; i--)
        {
            result+=m[buffer[i]]*power;
            power*=base;
        }

        cout<<"Case #"<<t<<": "<<result<<endl;
    }

    return 0;
}
