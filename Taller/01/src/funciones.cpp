#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int>res;

    for(int i: s){

        int j = 0;
        while(j<res.size() and i != res[j])
            j++;

        if(j == res.size())
            res.push_back(i);
    }

    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {

    vector<int>res;
    set<int> c;

    for(int i:s){
        c.insert(i);
    }

    for(int j:c)
        res.push_back(j);

    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {

    bool res = true;
    for (int i = 0; i < a.size(); ++i){
        
        int j = 0;
        while(j < b.size() and  a[i] != b[j]){
            j++;
        }
        if(j == b.size())
            res = false;
    }
    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {

    set<int> x,y;

    for(int i:a)
        x.insert(i);

    for(int j:b)
        y.insert(j);



    return x == y;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int>res;

    for(int i:s)
        res[i]++;

    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    map<int,int> m = contar_apariciones(s);
    vector<int>res;

    map<int,int>::iterator it = m.begin();
    while(it  != m.end()){
        if(it->second == 1)
            res.push_back(it->first);

        it++;
    }
    
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {

    set<int> intersecc;

    for(int i:a){
        if(b.count(i) > 0)
            intersecc.insert(i);
    }
    return intersecc;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {

    map<int, set<int>>res;


    for(int i:s){

        res[ i%10 ].insert( i );
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {

    vector<char>res = str;
    map<char,char>dicc;
    for(pair<char, char> p : tr){
        dicc[p.first] = p.second;
    }

    for(int i=0; i < str.size(); i++){
        if(dicc.count(str[i]) > 0)
            res[i] = dicc[str[i]];

    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {

    set<LU> lib, curso;
    map< LU, set<LU> > grupos;
    bool repetidos = false;

    for(Mail m:s){

        lib = m.libretas();
        
        for(LU l:lib){
            grupos[l] = lib;
        }
    }

    for(Mail m:s){

        lib = m.libretas();
        
        for(LU l:lib){
            if( lib != grupos[l])
                repetidos |= true;

        }
    }

    return repetidos;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {

    map<set<LU>, Mail>res;

    for(Mail m:s){
        if(m.adjunto())
            res[ m.libretas()] = m;
    }
    return res;
}
