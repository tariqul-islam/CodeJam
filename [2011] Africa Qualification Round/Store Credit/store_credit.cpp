/*
** If one has C money and buys an item for
** P1 price.
** To buy the 2nd item he must spend
** C-P1 money.
*/


#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

/*
 *  Introduces a class that contains
 *  two integers: price (to include price
 *  of a Item), index (in which place the
 *  item is stored)
 *
 *  The class also has operators < and ==
 */
class p_pair
{
public:
    int price;
    int index;

    p_pair(){price=0;index=0;}
    p_pair(int a, int b){price=a;index=b;}

    bool operator<(const p_pair& p) const
    {
        if(price<p.price)
            return true;
        else
            return false;
    }

    bool operator==(const p_pair& p) const
    {
        if(price==p.price)
            return true;
        else
            return false;
    }
};


int main()
{
        //redirecting stdin to a file
        freopen("input-large.txt", "r", stdin);
        //redirecting stdout to a file
        freopen("output.txt", "w", stdout);

        int N; //N test cases
        scanf("%d", &N);

        for(int n=0; n<N; n++)
        {
            int C; //Total credit
            scanf("%d", &C);

            int I; //number of items
            scanf("%d", &I);

            //creating price,index pairs for each item
            p_pair* prices = new p_pair[I];

            //taking inputs
            for(int i=0; i<I; i++)
            {
                scanf("%d", &prices[i].price);
                prices[i].index = i+1;
            }

            //sorting
            sort(prices, prices+I);

            int flag=0;
            int one;
            int two;

            //Iterating over the prices
            for(int i=0; i<I-1; i++)
            {
                //making a p_pair for the target price
                p_pair key(C - prices[i].price,0);

                //looking for the target price and if found getting their indices
                //Try replacing this with a better search function [AMAR TEL NAI]
                if(binary_search(prices+i+1, prices+I, key))
                {
                    for(int j=i+1; j<I; j++)
                    {
                        if(prices[j]==key)
                        {
                            one = prices[i].index;
                            two = prices[j].index;
                            flag=1;
                            break;
                        }
                    }
                }

                if(flag) break;
            }

            delete [] prices;

            if(one>two)
            {
                one = one^two;
                two = one^two;
                one = one^two;
            }

            printf("Case #%d: %d %d\n", n+1, one, two);
        }
}
