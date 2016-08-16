/********
Code Jam 2008 - Qualifier
B. Train Timetable

Solution Written By
Mohammad Tariqul Islam

Solution running time approximately O(n^2)
*********/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

#define A2B 'a'
#define B2A 'b'


class mypair
{
public:
    int start; //contains the startinf time
    int reach; //the time it reaches the destination
    char ab; //remembers whether it's going From A to B or the other wat
    bool flag; //a flag to remember whether it's reach time has been processed in the algorithm

    bool operator<(const mypair& ob) const
    {
        if(start<ob.start)
        {
            return true;
        }
        else if(start==ob.start)
        {
            if(reach<ob.reach)
                return true;
            else
                return false;
        }
        else
        {
            return false;
        }
    }

};

int main()
{
    freopen("a.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char c;
    int N;
    scanf("%d", &N);
    for(int n=1; n<=N; n++)
    {
        int T;
        scanf("%d", &T);
        int NA, NB;
        scanf("%d %d",&NA,&NB);
        int NN = NA+NB; //total number of trips
        mypair* pp = new mypair[NN];
        int HH,MM;

        //taing each input from time table
        for(int i=0; i<NN; i++)
        {
            scanf("%d:%d", &HH,&MM);
            pp[i].start = HH*100+MM;s

            scanf("%d:%d", &HH,&MM);

            MM+=T; //adding reach time + rest time
            pp[i].reach = (HH+MM/60)*100+(MM%60);
            pp[i].flag=true;
            if(i<NA)
                pp[i].ab=A2B;
            else
                pp[i].ab=B2A;
        }

        sort(pp,pp+NN); //soritn according to < operator of mypair class

        int Ga=0, //trains that must be in the station A from begining
        Gb=0, //trains that must be in the station B from begining
        na=0, //trains that have reached station A from B and are ready to start return trip
        nb=0; //^above but B from A.

        for(int i=0; i<NN; i++)
        {
            for(int j=0; j<i; j++)
            {
                //if the previous times (j-s) of the schdeule has not been processed
                //and does not belong to same dest of the current time schedule (i-s)
                //and j's reach time is lower than i's start time then i's start
                //station must have this train ready.
                if(pp[j].flag && pp[j].ab!=pp[i].ab && pp[j].reach<=pp[i].start)
                {
                    if(pp[j].ab==A2B)
                        nb++;
                    else
                        na++;

                    pp[j].flag=false; //make the flag false so it is not processed again
                }
            }

            //now if it's going A to B
            if(pp[i].ab==A2B)
            {
                //if no trains available then we must have an already stationed train from morning.
                if(na==0)
                    Ga++;
                //otherwise we use the stationed train and reduce the stationed train by 1
                else
                    na--;
            }
            //else the train is going B to A
            else
            {
                if(nb==0)
                    Gb++;
                else
                    nb--;
            }
        }


        delete [] pp; //freeing memory


        cout<<"Case #"<<n<<": "<<Ga<<" "<<Gb<<endl;
    }

    return 0;
}
