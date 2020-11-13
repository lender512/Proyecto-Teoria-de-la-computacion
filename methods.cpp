#include "class.h"

transition::transition(int _origin, int _destiny, string _symbol){
  origin = _origin;
  destiny = _destiny;
  symbol = _symbol;
}

transition::transition() {
  origin = 0;
  destiny = 0;
  symbol = " ";
}

DFA::DFA(){

}

NFA::NFA(){

}

inputDFA::inputDFA(){

}

DFA::DFA(int n, int initial, int n_final){
  int final;
  for (int i=0;i<n;i++){
    states.push_back(i);
  }
  current_state = initial;
  initial_state = initial;
  for (int i=0;i<n_final;i++){
    cin >> final;
    final_states.push_back(final);
  }
  int origin;
  int destiny;
  string symbol;
  for (int i=0;i<2*n;i++){
    cin >> origin  >> symbol >> destiny;
    transition add = transition(origin,destiny,symbol);
    transitions.push_back(add);
  }
}

DFA::DFA(int n, int initial, int n_final, vector<int>& estados, vector<int>& transiciones){
  int final;
  for (int i=0;i<n;i++){
    states.push_back(i);
  }
  current_state = initial;
  initial_state = initial;
  for (int i=0;i<n_final;i++){
    cout<<" "<<estados[3+i];
    //cin >> final;
    final_states.push_back(estados[3+i]);
  }
  cout<<endl;
  int origin;
  int destiny;
  string symbol;
  int a=0, b=1, c=2;
  for (int i=0;i<2*n;i++){
    //cin >> origin  >> symbol >> destiny;
    cout << transiciones[a] << " " << transiciones[b] << " " << transiciones[c] << endl;
    transition add = transition(transiciones[a], transiciones[c], to_string(transiciones[b]));
    transitions.push_back(add);
    a += 3; b += 3; c += 3;
  }
}

void DFA::input(string _symbol){
  auto it = find_if(transitions.begin(), transitions.end(), [_symbol,this](transition m) {return (current_state == m.origin && _symbol==m.symbol);});
  transition trans = *it;
  current_state = trans.destiny;
}

bool DFA::accepted(){
  return find(final_states.begin(),final_states.end(),current_state) != final_states.end();
}

DFA DFA::mindfa(){
  DFA result = determinization(reverse(determinization(reverse(*this))));
  return result;
}

NFA reverse(DFA input){
    NFA suj = NFA();
    suj.states = input.states;
    suj.final_states = {input.initial_state};
    //-1 is the start state for DFA
    if (input.final_states.size() == 1){
        suj.initial_state = input.final_states[0];
        for (int i=0;i<input.transitions.size();i++){
            transition temp = transition(input.transitions[i].destiny,input.transitions[i].origin,input.transitions[i].symbol);
            suj.transitions.push_back(temp);
        }
        /*cout << "Transiciones reversas: \n";
        for (auto i: suj.transitions) {
            cout << i.origin << " " << i.symbol << " " << i.destiny << endl;
        }
        cout << endl;*/
        return suj;
    }
    else{
        suj.states.push_back(-1);
        suj.initial_state = -1;
        for (int i=0;i<input.final_states.size();i++){
            transition temp = transition(-1,input.final_states[i],"e");
            suj.transitions.push_back(temp);
        }
        for (int i=0;i<input.transitions.size();i++){
            transition temp = transition(input.transitions[i].destiny,input.transitions[i].origin,input.transitions[i].symbol);
            suj.transitions.push_back(temp);
        }
        /*cout << "Transiciones reversas: \n";
        for (auto i: suj.transitions) {
            cout << i.origin << " " << i.symbol << " " << i.destiny << endl;
        }
        cout << endl;*/
        return suj;
    }
}


//TODO
void NFA::closure_sub(int state, set<int>& result){
  set<int> e_find = {};
  for (int i=0;i<transitions.size();i++){
    if (transitions[i].origin==state && transitions[i].symbol=="e" && find(result.begin(),result.end(),transitions[i].destiny) == result.end()){
      e_find.insert(transitions[i].destiny);
      result.insert(transitions[i].destiny);
    }    
  }
  for (auto it = e_find.begin();it != e_find.end();advance(it,1)){
    closure_sub(*it,result);
  }
}

set<int> NFA::closure(int state){
  set<int> result  = {state};
  closure_sub(state, result);
  /*cout << state << " llega a: ";
  for (auto i: result) {
    cout << i << ", ";
  }
  cout << "\n"; */
  return result;
}

DFA determinization(NFA input){
    auto tempm = input.closure(input.initial_state);
    vector<transition> transitions = input.transitions;
    set<int> new_initial(tempm.begin(),tempm.end());
    set<set<int>> passed = {new_initial};
    set<set<int>> done = {};
    int postinitial = 0;
    vector<vector<set<int>>> newtransitions = {}; // {{{1,2},{2,3}},{{4,3},{1,2}}}
    vector<string> symbolst = {};
    do{
        auto ceb = passed;
        for (auto i = ceb.begin();i!=ceb.end();advance(i,1)){
            auto temp = *i;
            if (done.find(temp) == done.end()){
                //0
                done.insert(temp);
                set<int> temp2 = {};
                for (auto i2 = temp.begin();i2!=temp.end();advance(i2,1)) {
                    //0
                    for (auto &transition : transitions) {
                        if (transition.origin == *i2 && transition.symbol == "0") {
                            temp2.insert(transition.destiny);
                        }
                    }
                    for (auto l = temp2.begin(); l != temp2.end(); advance(l, 1)) {
                        auto temp3 = input.closure(*l);
                        for (auto k = temp3.begin(); k != temp3.end(); advance(k, 1)) {
                            temp2.insert(*k);
                        }
                    }
                }
                vector<set<int>> temp5 = {temp,temp2};
                newtransitions.push_back(temp5); //temp2 puede ser vacio
                passed.insert(temp2);
                symbolst.emplace_back("0");
                //1
                temp2 = {};
                for (auto i2 = temp.begin();i2!=temp.end();advance(i2,1)) {
                    for (int m=0;m<transitions.size();m++){
                        if (transitions[m].origin == *i2 && transitions[m].symbol == "1"){
                            temp2.insert(transitions[m].destiny);
                        }
                    }
                    for (auto l=temp2.begin();l!=temp2.end();advance(l,1)){
                        auto temp3 = input.closure(*l);
                        for (auto k = temp3.begin();k != temp3.end();advance(k,1)){
                            temp2.insert(*k);
                        }
                    }
                }
                temp5 = {temp,temp2};
                newtransitions.push_back(temp5); //temp2 puede ser vacio
                passed.insert(temp2);
                symbolst.emplace_back("1");
            }
        }
    }
    while(done != passed);
    //mapeo dic
    map<set<int>,int> dic_new;
    vector<int> renamed_states;
    vector<int> renamed_final_states;
    int i =0;
    for (auto it = passed.begin();it!=passed.end();advance(it,1)){
        if (*it == new_initial){
            postinitial = i;
        }
        bool final = false;
        set<int> temp4 = *it;
        dic_new[temp4] = i;
        renamed_states.push_back(i);
        for (auto it2 = temp4.begin(); it2 != temp4.end(); advance(it2,1)){
            if (find(input.final_states.begin(),input.final_states.end(),*it2)!=input.final_states.end()){
                final = true;
            }
        }
        if (final){
            renamed_final_states.push_back(i);
        }
        i += 1;
    }
    //DEJA DE MOVERTE CTMR
    vector<transition> renamed_transitions;
    for (auto it = newtransitions.begin(); it != newtransitions.end(); advance(it,1)){
        auto temp1 = *it;
        int n_origin = dic_new[temp1[0]];
        int n_destiny = dic_new[temp1[1]];
        string symbol = symbolst[it-newtransitions.begin()];
        transition n_tra = transition(n_origin,n_destiny,symbol);
        renamed_transitions.push_back(n_tra);
    }
    DFA result = DFA();
    result.states = renamed_states;
    result.final_states = renamed_final_states;
    result.transitions = renamed_transitions;
    result.initial_state = postinitial;
    //rename
    /*cout << " Resultado \n";
    for (auto i: result.transitions) {
        cout << i.origin << " " << i.symbol << " " << i.destiny << endl;
    }
    cout << "\n";*/
    return result;
}
