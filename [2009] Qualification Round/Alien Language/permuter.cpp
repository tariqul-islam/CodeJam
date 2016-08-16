#include<cstring>

using namespace std;

//#include "permuter.h"

class permuter
{
public:
    char** char_bank;
    char* statement;
    int* counts;
    int* pattern;
    int num;
    bool overflow;

    permuter(int length, const char* str);
    ~permuter();
    void increment(int i);
    void next();
    bool ishere(const char* str);
};


bool permuter::ishere(const char* str)
{
    if(strlen(str)!=num || str==NULL || char_bank==NULL)
        return false;
    else
    {
        int flag=1;
        for(int i=0; i<num; i++)
        {
            if(flag==1)
            {
                for(int j=0; j<counts[i]; j++)
                {
                    if(str[i]==char_bank[i][j])
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==0)
                flag=1;
            else
                return false;
        }
        return true;
    }
}


void permuter::next()
{
    increment(num-1);
}

void permuter::increment(int i)
{
    if(i<0)
    {
        overflow=true;
        return;
    }

    pattern[i]=pattern[i]+1;
    if(pattern[i]<counts[i])
    {
        statement[i] = char_bank[i][pattern[i]];
    }
    else
    {
        pattern[i]=0;
        statement[i] = char_bank[i][pattern[i]];
        increment(i-1);
    }


}

permuter::permuter(int length, const char* str)
{
    int len = strlen(str);
    char* temp = new char[len+1];

    counts = new int[length];
    pattern = new int[length];
    char_bank = new char*[length];
    statement = new char[length+1];
    statement[length]='\0';
    num = length;
    overflow=false;

    memset(pattern, 0, sizeof(int)*num);

    char c;
    int j=0;
    int k=0;
    int l=0;
    for(int i=0; i<len; i++)
    {
        c=str[i];
        if(c=='(')
        {
           j=1;
           continue;
        }
        if(c==')')
        {
            j=0;
            temp[k]='\0';

            int n=strlen(temp);
            char_bank[l] = new char[n];
            for(int m=0; m<n; m++)
            {
                char_bank[l][m]=temp[m];
            }
            counts[l]=n;
            l++;
            k=0;
            continue;
        }
        if(j==1)
            temp[k++]=c;
        if(j==0)
        {
            char_bank[l] = new char[1];
            char_bank[l][0] = c;
            counts[l]=1;
            l++;
        }

    }

    for(int i=0; i<num; i++)
    {
        statement[i]=char_bank[i][pattern[i]];
    }

    delete [] temp;

}

permuter::~permuter()
{
    for(int i=0; i<num; i++)
    {
        delete [] char_bank[i];
    }

    delete [] char_bank;

    delete [] counts;
    delete [] pattern;
    delete [] statement;
}
