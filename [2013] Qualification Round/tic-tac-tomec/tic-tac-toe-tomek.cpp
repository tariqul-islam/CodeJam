#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

char get_result(int T, int X, int O, int dot)
{
    if(dot)
        return 'N';
    else if(X==4)
        return 'X';
    else if(O==4)
        return 'O';
    else if(X==3 && T==1)
        return 'X';
    else if(O==3 && T==1)
        return 'O';
    else
        return 'N';
}

int main()
{
    char buf[5];
    int T;

    gets(buf);
    sscanf(buf, "%d", &T);

    for(int t=1; t<=T; t++)
    {
        char board[4][4];

        for(int i=0; i<4; i++)
        {
            gets(buf);
            for(int j=0; j<4; j++)
            {
                board[i][j]=buf[j];
            }
        }
        gets(buf);

        int T=0, X=0, O=0, dot=0, dots=0;
        char result='N';
        //horizontal test
        if(result=='N')
        {
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    if(board[i][j]=='T')
                        T++;
                    else if(board[i][j]=='X')
                        X++;
                    else if(board[i][j]=='O')
                        O++;
                    else
                    {
                        dot++;
                        dots++;
                    }
                }
                result = get_result(T, X, O, dot);
                T=0; X=0; O=0; dot=0;
                if(result == 'X' || result=='O')
                    break;
            }
        }

        //vertical test
        if(result=='N')
        {
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    if(board[j][i]=='T')
                        T++;
                    else if(board[j][i]=='X')
                        X++;
                    else if(board[j][i]=='O')
                        O++;
                    else
                    {
                        dot++;
                        dots++;
                    }
                }
                result = get_result(T, X, O, dot);
                T=0; X=0; O=0; dot=0;
                if(result == 'X' || result=='O')
                    break;
            }
        }

        //diagonal test
        if(result=='N')
        {
            for(int i=0; i<4; i++)
            {
                if(board[i][i]=='T')
                    T++;
                else if(board[i][i]=='X')
                    X++;
                else if(board[i][i]=='O')
                    O++;
                else
                {
                    dot++;
                    dots++;
                }
            }
            result = get_result(T, X, O, dot);
            T=0; X=0; O=0; dot=0;
        }

        //diagonal test
        if(result=='N')
        {
            for(int i=3, j=0; i>=0 && j<=3; i--, j++)
            {

                if(board[i][j]=='T')
                    T++;
                else if(board[i][j]=='X')
                    X++;
                else if(board[i][j]=='O')
                    O++;
                else
                {
                    dot++;
                    dots++;
                }
            }
            result = get_result(T, X, O, dot);
            T=0; X=0; O=0; dot=0;
        }

        cout<<"Case #"<<t<<": ";
        if(result == 'X')
            cout<<"X won";
        else if(result == 'O')
            cout<<"O won";
        else if(result == 'N' && dots)
            cout<<"Game has not completed";
        else
            cout<<"Draw";

        cout<<endl;
    }

    return 0;
}
