#include<cstring>
#include<algorithm>
using namespace std;

//#include "dictionary_data_structure.h"

class dictionary
{
public:
    char** dict;
    bool* found;
    int words;
    int state;

    dictionary(int length, int count);
    ~dictionary();
    bool insert(const char* str);
    void sort_dict();
    bool search_dict(const char* str);
    void found_reset();
};


bool comp(char* first, char* second)
{
    if(strcmp(first, second)<0)
        return true;
    else
        return false;
}

dictionary::dictionary(int length, int count)
{
    if(length<1 || count<1)
    {
        words=0;
        found=NULL;
        dict=NULL;
    }
    else
    {
        words = count;

        dict = new char*[words];
        found = new bool [words];
        for(int i=0; i<words; i++)
        {
            dict[i]=new char[length+1];
            found[i]=false;
        }
        state=0;
    }
}

dictionary::~dictionary()
{
    for(int i=0; i<words; i++)
    {
        delete [] dict[i];
    }
    delete [] dict;
    delete [] found;
}

bool dictionary::insert(const char* str)
{
    if(dict && state<words)
    {
            strcpy(dict[state], str);
            state++;
            return true;
    }
    else
        return false;
}

void dictionary::sort_dict()
{
    if(dict)
        sort(dict, dict+words, comp);
}

bool dictionary::search_dict(const char* str)
{
    int start = 0;
    int end = words-1;
    int middle;
    int check;
    while(start<=end)
    {
       middle = (start+end)/2;
       check=strcmp(str, dict[middle]);
       if(check==0)
       {
            if(found[middle]==false)
            {
                found[middle]=true;
                return true;
            }
            else
                return false;
       }
       else if(check<0)
            end = middle-1;
       else
            start = middle+1;
    }
    return false;
}

void dictionary::found_reset()
{
    for(int i=0; i<words; i++)
    {
        found[i]=false;
    }
}
