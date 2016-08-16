#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

#define RED 'R'
#define BLUE 'B'

using namespace std;

//Applying Gravity to left (instead of down)
//and an anticlockwise rotation would make the
//thing faster


//Rotates the array
void rotate(char ** a, int N);
//Applies gravity on an array
void gravity(char** a, int N);

//searches horizontally
bool hor_search(char** a, int N, int K, char S);
//searches vertically
bool ver_search(char** a, int N, int K, char S);
//searches diagonally
bool diag_search(char** a, int N, int K, char S);
//general search
bool search(char** a, int N, int K, char S);


int main()
{
    freopen("A-small-practice.in", "r", stdin);
    freopen("output.txt","w", stdout);

    int T;
    char buffer[51];
    gets(buffer);
    sscanf(buffer, "%d", &T);

    for(int t=1; t<=T; t++)
    {
        int N,K;

        gets(buffer);
        sscanf(buffer, "%d %d", &N, &K);

        char** A=new char*[N];

        for(int i=0; i<N; i++)
            A[i]=new char[N];

        for(int i=0; i<N; i++)
        {
            gets(buffer);
            for(int j=0; j<N; j++)
                A[i][j]=buffer[j];
        }

        rotate(A,N);
        gravity(A,N);
        rotate(A,N);
        rotate(A,N);

        bool red = search(A,N,K,RED);
        bool blue = search(A,N,K,BLUE);

        cout<<"Case #"<<t<<": ";
        if(red && blue)
            cout<<"Both";
        else if(red)
            cout<<"Red";
        else if(blue)
            cout<<"Blue";
        else
            cout<<"Neither";

        cout<<endl;

        for(int i=0; i<N; i++)
            delete [] A[i];
        delete [] A;
    }
}

void rotate(char** a, int N)
{
    char** x = new char*[N];
    for(int i=0; i<N; i++)
        x[i]=new char[N];

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            x[i][j] = a[i][j];
        }
    }

    for(int i=0, j=N-1; i<N; i++, j--)
    {
        for(int k=0; k<N; k++)
        {
            a[k][j]=x[i][k];
        }
    }

    for(int i=0; i<N; i++)
    {
        delete [] x[i];
    }
    delete [] x;
}

void gravity(char** a, int N)
{
    char** x = new char*[N];
    for(int i=0; i<N; i++)
    {
        x[i]=new char[N];
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            x[i][j] = a[i][j];
            a[i][j] = '.';
        }
    }

    for(int i=0; i<N; i++)
    {
        int k=N-1;
        for(int j=N-1; j>=0; j--)
        {
            if(x[j][i]!='.')
            {
                a[k][i]=x[j][i];
                k--;
            }
        }
    }

    for(int i=0; i<N; i++)
    {
        delete [] x[i];
    }
    delete [] x;
}

bool hor_search(char** a, int N, int K, char S)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<=N-K; j++)
        {
            bool s=true;
            for(int k=j; k-j<K; k++)
            {
                if(a[i][k]!=S)
                {
                    s=false;
                    break;
                }
            }

            if(s)
                return true;
        }
    }

    return false;
}

bool ver_search(char** a, int N, int K, char S)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<=N-K; j++)
        {
            bool s=true;
            for(int k=j; k-j<K; k++)
            {
                if(a[k][i]!=S)
                {
                    s=false;
                    break;
                }
            }

            if(s)
                return true;
        }
    }
    return false;
}

bool diag_search(char** a, int N, int K, char S)
{
    for(int i=0; i<=N-K; i++)
    {
        for(int j=0; j<=N-K; j++)
        {
            bool s=true;
            for(int k=i, l=j; k-i<K; k++,l++)
            {
                if(a[k][l]!=S)
                {
                    s=false;
                    break;
                }
            }

            if(s)
                return true;
        }
    }

    for(int i=0; i<=N-K; i++)
    {
        for(int j=N-1; j>=K-1; j--)
        {
            bool s=true;
            for(int k=i,l=j; k-i<K; k++,l--)
            {
                if(a[k][l]!=S)
                {
                    s=false;
                    break;
                }
            }

            if(s)
                return true;
        }
    }

    return false;
}

bool search(char** a, int N, int K, char S)
{
    if(hor_search(a,N,K,S))
        return true;
    else if(ver_search(a,N,K,S))
        return true;
    else if(diag_search(a,N,K,S))
        return true;
    else
        return false;
}
