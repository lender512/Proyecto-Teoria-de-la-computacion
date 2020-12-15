#include "class.h"

set<int> DFA::reachable(int s) {
    set<int> reach;
    for (auto t: transitions) {
        if (t.origin == s) {
            reach.insert(t.destiny);
        }
    }
}

set<int> DFA::initial_reachable() {
    set<int> reach;
    queue<int> revisar;
    set<int> done;
    done.insert(initial_state);
    reach.insert(initial_state);
    revisar.push(initial_state);
    while (!revisar.empty()) {
        set<int> r = reachable(revisar.front());
        for (auto s:r) {
            if (done.find(s) == done.end()) {
                reach.insert(s);
                revisar.push(s);

            }
            done.insert(revisar.front());
        }
        revisar.pop();
    }
    return reach;
}

void DFA::min_hm() {
    vector<vector<char>> matrix = equivalencian2();
    set<int> reach = initial_reachable();

    set<set<int>> bloques;
    for (auto it = reach.begin(); it != reach.end(); ++it) {
        set<int> sub_bloque;
        sub_bloque.insert(*it);
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[*it][j] == '1') {
                sub_bloque.insert(j);
            }
        }
        /*cout << "subloque: " << endl;
        for (auto c: sub_bloque) cout << c << " ";
        cout << endl;
        bloques.insert(sub_bloque);*/
    }
    /*for (auto bloque: bloques) {
        cout << "{";
        for (auto i : bloque) {
            cout << i << " ";
        }
        cout << "}";
    }
    cout << endl;*/
}
