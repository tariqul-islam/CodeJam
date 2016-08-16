#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

class word_storage
{
public:
    char** WordBank;
    int WordCount;

    //member functions
    //Constructor: Parses a string and stores words in a string array
    word_storage(const char* str);
    //Destructor: Frees all the memory
    ~word_storage();

};

word_storage::word_storage(const char* str)
{
    int len = strlen(str);

    WordCount=0;
    for(int i=0; i<len; i++)
    {
        if(str[i]==' ')
            WordCount++;
    }
    WordCount++;

    WordBank = new char*[WordCount];

    char* temp = new char[len+1];


    for(int i=0, j=0, k=0; i<len; i++)
    {
        if((temp[j++]=str[i])==' ' || i==len-1)
        {
            if(i!=len-1)
                temp[j-1]='\0';
            else
                temp[j]='\0';

            j=0;

            WordBank[k] = new char[strlen(temp)+1];

            strcpy(WordBank[k++], temp);
        }
    }

    delete [] temp;
}

word_storage::~word_storage()
{
    for(int i = 0; i<WordCount; i++)
    {
        delete [] WordBank[i];
    }
    delete [] WordBank;
}


int main()
{
    freopen("B-large-practice.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    char L[1001];
    int N;
    scanf("%d", &N);
    scanf("%c", &L[0]);
    for(int i=0; i<N; i++)
    {
        gets(L);

        word_storage words(L);

        cout<<"Case #"<<i+1<<":";
        for(int i=words.WordCount-1; i>=0; i--)
        {
            cout<<' '<<words.WordBank[i];
        }
        cout<<endl;
    }
}
