#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("result.txt", "w", stdout);
    int T;
    scanf("%d", &T);

    for(int tt=1; tt<=T; tt++)
    {
        int A, N;
        scanf("%d %d", &A, &N);

        long long* array = new long long[N];
        for(int i=0; i<N; i++)
        {
            scanf("%lld", &array[i]);
        }
        sort(array, array+N);

        long long sum=A;
        vector<int> vect;
        vect.reserve(100);
        int ops=0;
        for(int i=0; i<N; i++)
        {
            if(sum>array[i])
            {
                sum+=array[i];
            }
            else
            {
                if(sum!=1)
                {
                    int n = floor( log2( (array[i]-1) / (sum - 1) ) ) + 1;
                    sum = pow(2,n)*(sum-1)+1+array[i];
                    vect.push_back(ops+N-i);
                    ops+=n;
                }
                else
                {
                    vect.push_back(ops+N-i);
                    break;
                }
            }
        }
        if(sum!=1)
            vect.push_back(ops);
        sort(vect.begin(),vect.end());

        printf("Case #%d: %d\n", tt, vect[0]);

        delete [] array;
    }
}
