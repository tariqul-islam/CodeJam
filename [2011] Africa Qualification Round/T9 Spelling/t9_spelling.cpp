#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<string>

using namespace std;


int main()
{
    freopen("C-large-practice.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<char,string> t9map;

    t9map['a']="2";
    t9map['b']="22";
    t9map['c']="222";
    t9map['d']="3";
    t9map['e']="33";
    t9map['f']="333";
    t9map['g']="4";
    t9map['h']="44";
    t9map['i']="444";
    t9map['j']="5";
    t9map['k']="55";
    t9map['l']="555";
    t9map['m']="6";
    t9map['n']="66";
    t9map['o']="666";
    t9map['p']="7";
    t9map['q']="77";
    t9map['r']="777";
    t9map['s']="7777";
    t9map['t']="8";
    t9map['u']="88";
    t9map['v']="888";
    t9map['w']="9";
    t9map['x']="99";
    t9map['y']="999";
    t9map['z']="9999";
    t9map[' ']="0";
    t9map['\0']="";

    int N;
    char msg[1001];

    gets(msg);
    N=atoi(msg);

    for(int n=0; n<N; n++)
    {
        gets(msg);

        int i=0;
        char c;
        char prevc='\0';
        cout<<"Case #"<<n+1<<": ";
        while((c=msg[i++]))
        {
            if(t9map[c][0]==t9map[prevc][0])
                cout<<' ';
            cout<<t9map[c];
            prevc=c;
        }
        cout<<endl;
    }

    return 0;
}
