#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define mp(x,y) make_pair(x,y)

using namespace std;

class DFA
{
    vector<string> states, alphabet, finalStates;
    map<pair<string, string>, string> transition;
    string initialState;


public:
    DFA(const vector<string> &_states, const vector<string> &_alphabet,const map<pair<string, string>, string> &_transition,
        const string &_initialState, const vector<string> &_finalStates)
    {
        states = _states;
        alphabet = _alphabet;
        transition = _transition;
        initialState = _initialState;
        finalStates = _finalStates;
    }

    bool checkWord(const vector<string> &word)
    {
        string state = initialState;
        for(string c : word)
            state = transition[mp(state, c)];
        return find(finalStates.begin(), finalStates.end(), state) != finalStates.end();
    }

    void check()
    {
        cout<<"hello world! :D";
    }
};

vector<string> split(string s)
{
    vector<string> rez;
    string buff;

    for(char c : s)
    {
        if(c != ' ')
            buff += c;

        else if(buff != "")
        {
            rez.push_back(buff);
            buff = "";
        }
    }

    if(buff != "")
        rez.push_back(buff);

    return rez;
}


DFA readDFA(string fileName)
{
    /*
     * read format:
     * line 1: states
     * line 2: alphabet
     * line 3: initial state
     * line 4: final states
     * rest of lines: transition function
    */

    ifstream fin(fileName);
    vector<string> states, alphabet, finalStates, word;
    string initialState, line;
    map<pair<string, string>, string> t;


    getline(fin, line);
    states = split(line);

    getline(fin, line);
    alphabet = split(line);

    getline(fin, initialState);

    getline(fin, line);
    finalStates = split(line);

    string s1, s2, s3;
    while(!fin.eof())
    {
        fin >> s1 >> s2 >> s3;
        t[mp(s1,s2)] = s3;
    }

    fin.close();

    DFA d(states,alphabet,t,initialState,finalStates);

    return d;
}


int main()
{
    DFA D = readDFA("dfa1.txt");

    string word = "";

    cout<<D.checkWord(split(word));


    return 0;
}
