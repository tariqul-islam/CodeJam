#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<stdint.h>

using namespace std;

#define MAX 100

int N, M;
int lawn[100][100];

bool is_achiv(int x, int y)
{
    bool ret1 = true;
    bool ret2 = true;
    for(int i=0; i<N; i++)
    {
        if(lawn[i][y]>lawn[x][y])
        {
            ret1=false;
            break;
        }
    }

    for(int i=0; i<M; i++)
    {
        if(lawn[x][i]>lawn[x][y])
        {
            ret2=false;
            break;
        }
    }

    return ret1 || ret2;
}

int main()
{
    //freopen("B-large.in", "r", stdin);
    //freopen("result.txt", "w", stdout);
    int T;

    scanf("%d", &T);


    for(int t=1; t<=T; t++)
    {
        scanf("%d %d", &N, &M);

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                scanf("%d", &lawn[i][j]);
            }
        }
        bool result=true;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(!is_achiv(i,j))
                    result=false;
            }
        }

        cout<<"Case #"<<t<<": ";
        if(result)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
