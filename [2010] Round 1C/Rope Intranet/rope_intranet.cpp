/*
    The Method I was using was okay, but took a long time.
    This method uses the solution given in the website
    And it easier, and faster.
    Why I couldn't think of that? shame on me.
*/


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int main()
{
    freopen("A-large-practice.in", "r", stdin);
    freopen("result.txt", "w", stdout);
    int T;
    scanf("%d", &T);

    for(int t=1; t<=T; t++)
    {
        int N;
        scanf("%d", &N);

        int* first = new int[N];
        int* second = new int[N];

        int count=0;

        for(int i=0; i<N; i++)
        {
            scanf("%d %d", &first[i], &second[i]);

            int flag=1;
            float y, y1, y2, y3, y4;
            if(first[i]-second[i])
            {
                y3 = first[i];
                y4 = second[i];
                flag = 0;
            }

            for(int j=0; j<i; j++)
            {
                count+= first[i]<first[j] != second[i]<second[j];
            }
        }

        cout<<"Case #"<<t<<": "<<count<<endl;

        delete [] first;
        delete [] second;
    }
}
