#include <iostream>
#include <string>
#include <vector>
#include <map>

#define mp(x,y) make_pair(x,y)

using namespace std;


//check if a word belong to an automata
bool checkWord(const string &word, const string &states, const string &alphabet,
               map<pair<char, char>, char> &transition, const char &initialState, const string &finalStates)
{
    char state = initialState;
    for(char c : word)
        state = transition[mp(state, c)];
    return finalStates.find(state) != string::npos;
}


void example1()
{
    string states = "spqr";
    string alphabet = "ab";
    map<pair<char,char>, char> t;
    t[mp('s','a')] = 'p';
    t[mp('s','b')] = 's';
    t[mp('p','a')] = 'p';
    t[mp('p','b')] = 'q';
    t[mp('q','a')] = 'r';
    t[mp('q','b')] = 's';
    t[mp('r','a')] = 'r';
    t[mp('r','b')] = 'r';
    char initialState = 's';
    string finalStates = "r";

    string word = "baabbbaaababbababb";

    bool rez = checkWord(word,states,alphabet,t,initialState,finalStates);

    cout<<rez;
}

void example2()
{
    string states = "012";
    string alphabet = "ab";
    map<pair<char,char>, char> t;
    t[mp('0','a')] = '1';
    t[mp('0','b')] = '0';
    t[mp('1','a')] = '2';
    t[mp('1','b')] = '0';
    t[mp('2','a')] = '2';
    t[mp('2','b')] = '2';
    char initialState = '0';
    string finalStates = "01";

    string word = "bbababbba";

    bool rez = checkWord(word,states,alphabet,t,initialState,finalStates);

    cout<<rez;
}

int main()
{
    example2();
    return 0;
}
