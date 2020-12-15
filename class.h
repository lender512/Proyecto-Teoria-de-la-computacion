#include "tipos.h"

struct inputDFA{
  vector<int> estados;
  vector<int> transiciones;
  inputDFA();
};

struct transition{
  int origin;
  int destiny;
  string symbol;
  transition();
  transition(int origin, int destiny, string symbol);
};

struct DFA{
  vector<int> states = {};
  vector<string> symbols = {"0","1"};
  vector<int> final_states = {};
  vector<transition> transitions = {};
  int initial_state;
  //
  int current_state;
  //constructor
  DFA(int n, int initial, int n_final, vector<int>& estados, vector<int>& transiciones);
  DFA(int n, int initial, int n_final);
  DFA();
  //input
  void input(string symbol);
  bool accepted();
  //2da pregunta
  void equivalencia();
  //3ra pregunta
  set<vector<int>> dependencia(int a, int b);
  vector<vector<char>>  equivalencian2();
  //4ta pregunta
  set<int> reachable(int s);
  set<int> initial_reachable();
  void min_hm();
  //1ra pregunta
  DFA mindfa();

};

struct NFA{
  vector<int> states = {};
  vector<string> symbols = {"0","1","e"};
  vector<int> final_states = {};
  vector<transition> transitions = {};
  int initial_state;
  //
  int current_state;
  //constructor
  NFA();
  //methods
  void closure_sub(int state, set<int>& result);
  set<int> closure(int state);
};

DFA determinization(NFA input);
NFA reverse(DFA input);