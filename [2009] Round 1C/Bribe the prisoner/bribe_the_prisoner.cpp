/***********
Code Jam 2009: Round 1C
Bribe the Prisoner

Solution Written by,
Mohammad Tariqul Islam
***********/

/*
Apparently this is a dynamic programming problem.
My first thought was, the problem will be easily solved if divide and conquere method
and provided that the partitioning is done for which the tow parts are mostly equal.

But later turns out this is not the case. By help of the contest analysis I solved it
using DP. Turn, partitioning had to be done anyway.

I used to skip DP problems in the past. But after reading the analysis this seemed
easier.... My be more DP in the future... anyway....

My Very first DP programming.
T_T T_T

*/


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<utility> //std::pair
#include<map>

using namespace std;

#define MAX 500000

//saving dynamic programming data structure and
//the function that solves it.
class data
{
public:
    map<pair<int,int>, int> mp;
    int solve(int Pstart, int Pend, int* Rstart, int* Rend);
};

int main()
{
    freopen("C-large-practice.in", "r", stdin);
    freopen("output2.txt", "w", stdout);

    //number of test cases
    int T;
    scanf("%d", &T);

    for(int t=1; t<=T; t++)
    {
        //P & Q
        int P;
        int Q;
        scanf("%d %d", &P, &Q);

        //Prisoners to be releases R
        int* R = new int[Q];
        if(!R) exit(-1);
        for(int i=0; i<Q; i++)
        {
            scanf("%d", &R[i]);
        }

        //data class
        data da;

        //solving the problem
        int result = da.solve(1, P, R, R+Q);
        cout<<"Case #"<<t<<": "<<result<<endl;

        //deleting memory
        delete [] R;
    }

    return 0;
}

int data::solve(int Pstart, int Pend, int* Rstart, int* Rend)
{
    //number of R
    int N = Rend-Rstart;

    pair<int,int> pp(Pstart,Pend);

    //checks if the pair has been already computed
    if(mp.find(pp) != mp.end())
        return mp[pp];

    //if prisoners to be released is zero then no bribes are given
    if(N==0)
    {
        mp[pp]=0;
        return mp[pp];
    }

    //else starts the computation
    int min = MAX;
    int* Rind = NULL;
    for(int i=0; i<N; i++)
    {
        Rind = Rstart+i;
        int diff = (Pend-Pstart)+solve(Pstart,Rind[0]-1,Rstart,Rind)+solve(Rind[0]+1,Pend,Rind+1,Rend);
        if(diff<min)
        {
            min = diff;
        }
    }

    mp[pp] = min;
    return min;
}
