#include "class.h"
//PREGUNTA 3


bool searchV(set<vector<int>> v, vector<int> d) {
    for (auto i: v) {
        if ((i[0] == d[0] && i[1] == d[1]) || (i[1] == d[0] && i[0] == d[1])) {
            return true;
        }
    }
    return false;
}

set<vector<int>> DFA::dependencia(int a, int b) {
    set<vector<int>> dep;
    for (auto t1: transitions) {
        for (auto t2: transitions) {
            if ((t1.destiny == a && t2.destiny == b && t1.symbol == t2.symbol && t1.origin != t2.origin && t1.destiny != t2.destiny)) {
                vector<int> d1 = {t1.origin, t2.origin};
                vector<int> d2 = {t2.origin, t1.origin};
                    dep.insert(d1);
                    dep.insert(d2);
               // cout << t1.origin << " va a " << t1.destiny << " con " << t1.symbol << endl;
               //cout << t2.origin << " va a " << t2.destiny << " con " << t2.symbol << endl;
            }
        }
    }
   /* for (auto i: dep) {
        for (auto j: dep)
            cout << j[0] << " " << j[1] << endl;
    }*/
    return dep;
}

vector<vector<char>>  DFA::equivalencian2() {
  int size = states.size();
  vector<vector<char>> M(size, vector<char>(size));

  //Initialize equivalence matrix
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++){
      M[i][j]='1';
    }
  }
    for (auto s : final_states) cout << s << " ";
    cout << endl;

    set<int> diff; //Stores non final states
    //differencia entre conjuntos.
    for (auto s : states) {
        bool found = false;
        for (auto fs : final_states) {
            if (s == fs) {
                found = true;
            }
        }
        if (!found) {
            diff.insert(s);
        }
    }

    for (auto s : diff) cout << s << " ";
    cout << endl;
    queue<vector<int>> revisar;
    set<vector<int>> done;

    for (auto i: diff) {
        for (auto j: final_states) {
                vector<int> s = {i,j};
                revisar.push(s);
            }
    }

    while (!revisar.empty()) {
        M[revisar.front()[0]][revisar.front()[1]] = '0';
        M[revisar.front()[1]][revisar.front()[0]] = '0';
        set<vector<int>> dep = dependencia(revisar.front()[0],revisar.front()[1]);
        for (auto par: dep) {
            if (!searchV(done,par)) {
                revisar.push(par);
                done.insert(par);
            }
        }
        revisar.pop();
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

    return M;
}