#include "class.h"
//PREGUNTA 2


//Matrix comparison function
bool m_is_equal(vector<vector<char>> a, vector<vector<char>> b) {
  if (a.size() != b.size() | a[0].size() != b[0].size() ) {
    return false;
  }
  
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[0].size(); j++) {
      if (a[i][j] != b[i][j]) {
        return false;
      }
    }
  }
  return true; //Return true if M_a == M_b
}

void DFA::equivalencia() {
  int size = states.size();
  vector<vector<char>> M(size, vector<char>(size));

  //Initialize equivalence matrix
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++){
      M[i][j]='1';
    }
  }
  
  vector<int> diff; //Stores non final states

  set_difference(states.begin(), states.end(), final_states.begin(), final_states.end(), std::inserter(diff, diff.begin()));
  
  //Base case
  for (int i = 0; i < final_states.size(); i++) {
    for (int j = 0; j < diff.size(); j++) {
      int p = final_states[i];
      int q = diff[j];  
      //Set every trivial equivalence to 0
      M[q][p] = '0';
      M[p][q] = '0';
    }
  }

  vector<vector<char>> temp = M; //backup matrix for latere comparison

  //itative algorith
  bool equal = false;
  while (!equal){ //Stops when none new 0 value is set
    for (auto t1: transitions) {
      for (auto t2: transitions) {
        //cout << t1.destiny << " and " << t2.destiny << " compare " <<  get<0>(c) << " and " << get<1>(c) << endl;
        if (M[t1.destiny][t2.destiny] == '0' && t1.symbol == t2.symbol) {
          int p = t1.origin;
          int q = t2.origin;  
          M[p][q] = '0';
          M[q][p] = '0';
        }
      }
    }
    if (m_is_equal(temp,M)) {
      equal = true;
    }
    else {
      temp = M;
    }
  }

  //printing
  cout << setw(8);
  for (int i = 0; i < states.size(); i++)
    cout << i << "."<< setw(2);
  cout << endl;
  int c = 0;
  for (auto i: M) {
      cout << setw(5) << c << "." << setw(2);
      c++;
    for (auto j: i) {
      cout << j << setw(3);
    }
    cout << endl;
  }

}