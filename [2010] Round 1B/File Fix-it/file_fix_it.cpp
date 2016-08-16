#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<string>

using namespace std;

int main()
{
    freopen("A-large-practice.in", "r", stdin);
    freopen("result.txt", "w", stdout);
    char buffer[101];
    gets(buffer);

    int T;
    sscanf(buffer, "%d", &T);

    for(int t=1; t<=T; t++)
    {
        gets(buffer);
        int N, M;
        sscanf(buffer, "%d %d", &N, &M);

        map<string, bool> dirlist;
        dirlist[""]=true;

        for(int i=0; i<N; i++)
        {
            gets(buffer);
            dirlist[buffer] = true;
        }

        int count=0;

        for(int i=0; i<M; i++)
        {
            gets(buffer);
            while(!dirlist[buffer])
            {
                count++;
                dirlist[buffer]=true;

                for(int i=strlen(buffer)-1; i>=0; i--)
                {
                    if(buffer[i]=='/')
                    {
                        buffer[i]='\0';
                        break;
                    }
                }
                if(buffer[0]=='\0')
                    break;
            }
        }

        cout<<"Case #"<<t<<": "<<count<<endl;
    }

    return 0;
}
