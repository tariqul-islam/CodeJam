/***********
Code Jam - 2009 Round 1C
Center of Mass

Solution Written By,
Mohammad Tariqul Islam
***********/


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

//defining space variable to 3
#define S 3

int main()
{
    freopen("B-large-practice.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    //T - test case
    int T;
    scanf("%d", &T);

    for(int t=1; t<=T; t++)
    {
        //taking number of inputs
        int N;
        scanf("%d", &N);

        //allocating and storing in memory: N space vectors
        //and N velocity vectors each with S dimension
        int** X = new int*[N];
        int** V = new int*[N];

        if(!X || !V) exit(-1);

        for(int i=0; i<N; i++)
        {
            X[i]=new int[S];
            if(!X[i]) exit(-3);
            for(int j=0; j<S; j++)
            {
                scanf("%d", &X[i][j]);
            }

            V[i]=new int[S];
            if(!V[i]) exit(-4);
            for(int j=0; j<S; j++)
            {
                scanf("%d", &V[i][j]);
            }
        }

        //calculating center of mass and velocity of it
        //sumX = center of mass, sumV = velocity of center of mass
        double sumX[S], sumV[S];
        for(int i=0; i<S; i++)
        {
            sumX[i]=0;
            sumV[i]=0;
        }


        for(int i=0; i<N; i++)
        {
            for(int j=0; j<S; j++)
            {
                sumX[j]+=X[i][j];
                sumV[j]+=V[i][j];
            }
        }

        for(int i=0; i<S; i++)
        {
            sumX[i]/=N;
            sumV[i]/=N;
        }

        //calculating minimum time required
        //dtime = minimum time = - nume/deno;
        //nume = summation of (sumX.*sumV);
        //deno = summation of (sumV.*sumV);
        //.* element wise multiplication operator
        double nume=0, deno=0;

        for(int i=0; i<S; i++)
        {
            nume+=sumX[i]*sumV[i];
            deno+=sumV[i]*sumV[i];
        }


        double dtime;

        if(deno==0)
            dtime = 0;
        else
            dtime = - nume/deno;

        if(dtime<0)
            dtime = 0;

        //dmin = minimum distance
        //dmin = modulus of vector (sumX+sumV*dtime)
        double dmin = 0, cont;
        for(int i=0; i<S; i++)
        {
            cont = sumX[i]+sumV[i]*dtime;
            dmin += cont*cont;
        }
        dmin = sqrt(dmin);

        printf("Case #%d: %.8f %.8f\n", t, dmin, dtime);

        //freeing allocated memory
        for(int i=0; i<N; i++)
        {
            delete [] X[i];
            delete [] V[i];
        }
        delete [] X;
        delete [] V;
    }

    return 0;
}
