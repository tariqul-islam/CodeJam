#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

bool compare_int(int a, int b)
{
    if(a>b)
        return true;
    else
        return false;
}

int main()
{
    freopen("A-large-practice.in", "r", stdin);
    freopen("output2.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int t=0; t<T; t++)
    {
        int n;
        scanf("%d", &n);

        long long* first = new long long[n];
        long long* second = new long long[n];

        for(int i=0; i<n; i++)
        {
            scanf("%lld", &first[i]);
        }
        sort(first, first+n);

        for(int i=0; i<n; i++)
        {
            scanf("%lld", &second[i]);
        }
        sort(second, second+n, compare_int);

        long long sum;
        sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=first[i]*second[i];
        }

        delete [] first;
        delete [] second;

        cout<<"Case #"<<t+1<<": "<<sum<<endl;
    }

    return 0;
}
