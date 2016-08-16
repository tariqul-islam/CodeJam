#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#include "dictionary_data_strurcure.cpp"
#include "permuter.cpp"

using namespace std;


int main()
{
    //taking stdin to a file
    freopen("A-large-practice.in", "r", stdin);
    //taki8ng stdout to output.txt
    freopen("output.txt", "w", stdout);

    //declaring variable
    int L;
    int D;
    int N;

    //size for temporary storage string
    int storage_size = 2001;

    //declaring temporary storage string
    char* storage = (char*)malloc(sizeof(char)*storage_size);

    //getting first line of input
    gets(storage);

    //getting L D N
    sscanf(storage, "%d %d %d", &L, &D, &N);

    //declaring and getting the skeleton of dictionary
    dictionary dict(L, D);

    //storing dictiionary
    for(int i=0; i<D; i++)
    {
        //getting a line (word) from input string
        gets(storage);

        //inserting the word
        dict.insert(storage);
    }

    //processing each test case
    for(int i=0; i<N; i++)
    {
        //getting the line from input stream
        int size=0;
        char c;
        while((c=getc(stdin))!='\n' && c!=EOF)
        {
            if(size==storage_size)
            {
                storage_size=storage_size+1000;
                storage=(char*)realloc(storage, sizeof(char)*storage_size);
            }

            storage[size++]=c;
        }

        storage[size]='\0';

        //creating a permuter fro the line
        permuter per(L, storage);

        int count=0;

        //for each dictionary word checking if it is in the
        //permutations of the data of per
        for(int j=0; j<dict.words; j++)
        {
            if(per.ishere(dict.dict[j]))
                count++;
        }

        cout<<"Case #"<<i+1<<": "<<count<<endl;
    }

    //freeing storage
    free(storage);

    return 0;
}
