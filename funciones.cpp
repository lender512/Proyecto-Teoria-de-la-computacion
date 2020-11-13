#include "funciones.h"

void make_DFAP2(){
    ofstream DFA_P2;
    DFA_P2.open("DFA_P2.txt");
    vector<int> finales;
    int estados, estado_inicial, n_estados_finales;
    cin>>estados;
    cin>>estado_inicial;
    cin>>n_estados_finales;

    for(int i = 0; i < n_estados_finales; i++){
        int esta_fi;
        cin>>esta_fi;
        finales.push_back(esta_fi);
    }

    DFA_P2 << estados << " " << estado_inicial << " " << n_estados_finales << " ";
    for(int i = 0; i < finales.size(); i++){
        DFA_P2 << finales[i] << " ";
    }
    DFA_P2 << endl;

    int a, b, c, d, e, f;
    for(int i=0;i<estados;i++){
        cin>>a;cin>>b;cin>>c;
        cin>>d;cin>>e;cin>>f;
        DFA_P2 << a << " " << b << " " << c << endl;
        DFA_P2 << d << " " << e << " " << f << endl;
    }
    DFA_P2.close();
}

void make_DFAP(){
    ofstream DFA_P;
    DFA_P.open("DFA_P.txt");
    vector<int> finales;
    int estados, estado_inicial, n_estados_finales;
    cout<<"Ingrese numero de estados: "; cin>>estados;
    do{
        cout<<"Ingrese estado inicial: "; cin>>estado_inicial;
        if(estado_inicial >= estados)
            cout<<"El estado esta fuera del rango, vuelva a ingresar"<<endl;
    }while(estado_inicial >= estados);
    do{
        cout<<"Ingrese el numero de estados finales: "; cin>>n_estados_finales;
        if(n_estados_finales >= estados)
            cout<<"El numero de estados esta fuera del rango, vuelva a ingresar"<<endl;
    }while(n_estados_finales >= estados);

    for(int i = 0; i < n_estados_finales; i++){
        int esta_fi;
        do{
            cout<<"Ingrese el numero del estado final: "; cin>>esta_fi;
            if(esta_fi >= estados)
                cout<<"El estado esta fuera del rango, vuelva a ingresar"<<endl;
        } while(esta_fi >= estados);
        finales.push_back(esta_fi);
    }

    DFA_P << estados << " " << estado_inicial << " " << n_estados_finales << " ";
    for(int i = 0; i < finales.size(); i++){
        DFA_P << finales[i] << " ";
    }
    DFA_P << endl;

    int a, b, c, d, e, f;
    cout<<"Completa el estado final para cada transicion"<<endl;
    cout<<"Estado actual\tTransicion\tEstado final"<<endl;
    for(int i=0;i<estados;i++){
        a = i; b = 0;
        d = i; e = 1;
        cout<<"      "<<a<<"             "<<b<<"          ";cin>>c;
        cout<<"      "<<d<<"             "<<e<<"          ";cin>>f;
        DFA_P << a << " " << b << " " << c << endl;
        DFA_P << d << " " << e << " " << f << endl;
    }
    DFA_P.close();
}

void make_DFA(){
    ofstream DFA_random;
    DFA_random.open("DFA_random.txt");
    vector<int> finales;
    int estados, estado_inicial, n_estados_finales;
    srand(time(NULL));
    estados = 4 + rand() % (11 - 4);
    estado_inicial = 0 + rand() % (estados);
    n_estados_finales = 1 + rand() % (4 - 1);
    for(int i = 0; i < n_estados_finales; i++){
        int ffinal = 0 + rand() % (estados);
        finales.push_back(ffinal);
    }

    DFA_random << estados << " " << estado_inicial << " " << n_estados_finales << " ";
    for(int i = 0; i < finales.size(); i++){
        DFA_random << finales[i] << " ";
    }
    DFA_random << endl;

    int a, b, c, d, e, f;
    for(int i=0;i<estados;i++){
        a = i; b = 0; c = 0 + rand() % (estados);
        d = i; e = 1; f = 0 + rand() % (estados);
        DFA_random << a << " " << b << " " << c << endl;
        DFA_random << d << " " << e << " " << f << endl;
    }
    DFA_random.close();
}

void leer(string ruta){
    cout << "Automata Input: \n";
    ifstream file(ruta);
    inputDFA automata;
    string line;

    while(getline(file, line)){
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        if(line.length() > 3){
            for(int i=0; i < line.length(); i++){
                automata.estados.push_back((int)line[i]-48);
            }
        }
        else{
            for(int i=0; i < line.length(); i++){
                automata.transiciones.push_back((int)line[i]-48);
            }
        }
    }

    int n_states;
    int initial_state;
    int n_final;
    cout << automata.estados[0]<<" "<< automata.estados[1]<<" "<< automata.estados[2];
    //cin >> n_states >> initial_state >> n_final;
    DFA test = DFA(automata.estados[0],automata.estados[1],automata.estados[2], automata.estados, automata.transiciones);
    cout << endl;
    auto tesm = test.mindfa();
    cout << "Nuevo automata minimo " << endl;
    cout << tesm.states.size() << " " << tesm.initial_state << " " << tesm.final_states.size();
    for (auto i: tesm.final_states)
        cout<<" " << i ;
    cout << "\n";
    for (auto& x : tesm.transitions){
        cout << x.origin << " " << x.symbol << " " << x.destiny << " " << endl;
    }
    string cadena, txt;
    do{
        cout<<"Ingrese la cadena a testear: "; cin>>cadena;
        if (cadena != "e"){
            for(int i = 0; i < cadena.length(); i++){
                string c(1, cadena[i]);
                test.input(c);
                tesm.input(c);
            }
        }
        if (test.accepted()){
            cout << setw(2) << "  La cadena es aceptada por el automata original"<<endl;
        }
        else{
            cout << setw(2) << "  La cadena no es aceptada por el automata original"<<endl;
        }
        if (tesm.accepted()){
            cout << setw(2) << "  La cadena es aceptada por el automata minimo"<<endl;
        }
        else{
            cout << setw(2) << "  La cadena no es aceptada por el automata minimo"<<endl;
        }
        cout<<"Desea ingresar otra cadena(S/N) "; cin>>txt;
    }while(txt != "N");
}

void leer2(string ruta){
    cout << "Automata Input: \n";
    ifstream file(ruta);
    inputDFA automata;
    string line;

    while(getline(file, line)){
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        if(line.length() > 3){
            for(int i=0; i < line.length(); i++){
                automata.estados.push_back((int)line[i]-48);
            }
        }
        else{
            for(int i=0; i < line.length(); i++){
                automata.transiciones.push_back((int)line[i]-48);
            }
        }
    }

    int n_states;
    int initial_state;
    int n_final;
    cout << automata.estados[0]<<" "<< automata.estados[1]<<" "<< automata.estados[2];
    //cin >> n_states >> initial_state >> n_final;
    DFA test = DFA(automata.estados[0],automata.estados[1],automata.estados[2], automata.estados, automata.transiciones);
    cout << endl;
    auto test2 = reverse(test);
    cout << "Matriz de equivalencia: " << endl;
    test.equivalencia();

}

void pregunta1(){
    int op2;
    do {
        cout<<"\tMenu"<<endl;
        cout<<"1. DFA1(Figura 4.8)"<<endl;
        cout<<"2. DFA2(Figura 4.10)"<<endl;
        cout<<"3. DFA3(Figura 4.14)"<<endl;
        cout<<"4. DFA4(Figura 4.15)"<<endl;
        cout<<"5. DFA random"<<endl;
        cout<<"6. DFA personalizado"<<endl;
        cout<<"7. DFA personalizado manual"<<endl;
        cout<<"8. Regresar al menu anterior"<<endl;
        cout<<"Ingrese opcion: "; cin>>op2;
        switch (op2) {
            case 1:
                leer("DFA1.txt");
                break;

            case 2:
                leer("DFAextra.txt");
                break ;

            case 3:
                leer("DFA2.txt");
                break ;

            case 4:
                leer("DFA3.txt");
                break;

            case 5:
                make_DFA();
                leer("DFA_random.txt");
                break;

            case 6:
                make_DFAP();
                leer("DFA_P.txt");
                break;

            case 7:
                make_DFAP2();
                leer("DFA_P2.txt");
                break;

            case 8:
                cout << "Salio del menu"<<endl;
                break;

            default:
                cout << "Ingreso una opcion incorrecta"<<endl;
        }
    } while (op2 == 1 || op2 == 2 || op2 == 3 || op2 == 4 || op2 == 5);
}

void pregunta2(){
    int op2;
    do {
        cout<<"\tMenu"<<endl;
        cout<<"1. DFA1(Figura 4.8)"<<endl;
        cout<<"2. DFA2(Figura 4.10)"<<endl;
        cout<<"3. DFA3(Figura 4.14)"<<endl;
        cout<<"4. DFA4(Figura 4.15)"<<endl;
        cout<<"5. DFA random"<<endl;
        cout<<"6. DFA personalizado"<<endl;
        cout<<"7. DFA personalizado manual"<<endl;
        cout<<"8. Regresar al menu anterior"<<endl;
        cout<<"Ingrese opcion: "; cin>>op2;
        switch (op2) {
            case 1:
                leer2("DFA1.txt");
                break;

            case 2:
                leer2("DFAextra.txt");
                break ;

            case 3:
                leer2("DFA2.txt");
                break ;

            case 4:
                leer2("DFA3.txt");
                break;

            case 5:
                make_DFA();
                leer2("DFA_random.txt");
                break;

            case 6:
                make_DFAP();
                leer2("DFA_P.txt");
                break;

            case 7:
                make_DFAP2();
                leer2("DFA_P2.txt");
                break;

            case 8:
                cout << "Salio del menu"<<endl;
                break;

            default:
                cout << "Ingreso una opcion incorrecta"<<endl;
        }
    } while (op2 == 1 || op2 == 2 || op2 == 3 || op2 == 4 || op2 == 5);
}

void menu(){
    int op;

    do {
        cout<<"\tMenu"<<endl;
        cout<<"1. Pregunta 1"<<endl;
        cout<<"2. Pregunta 2"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Ingrese opcion: "; cin>>op;
        switch (op) {
            case 1:
                pregunta1();
                break;

            case 2:
                pregunta2();
                break;

            case 3:
                cout << "Salio del programa"<<endl;
                break;

            default:
                cout << "Ingreso una opcion incorrecta"<<endl;
        }
    } while (op == 1 || op == 2);
    return;
}

