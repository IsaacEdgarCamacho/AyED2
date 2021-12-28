#include <utility>

using namespace std;

// Ejercicio 15

// Juego

using Pos = pair<int, int>;

char ARRIBA = '^';
char ABAJO = 'v'; 
char DERECHA = '<';
char IZQUIERDA = '>';



class Juego {
  public:
    Juego(uint casilleros, Pos pos_inicial);
    Pos posicion_jugador();
    uint turno_actual();
    void mover_jugador(char dir);
    void ingerir_pocion(uint movimientos, uint turnos);    
  private:
    uint _casilleros;
    Pos _pos_inicial;
    uint _turno;
};


Juego::Juego(uint casilleros, Pos pos_inicial):_casilleros(casilleros),
                                               _pos_inicial(pos_inicial),
                                               _turno(0) {}

Pos Juego::posicion_jugador(){
  return _pos_inicial;
}

uint Juego::turno_actual(){
  return _turno;
}

void Juego::mover_jugador(char dir){

    if(dir == ARRIBA)
      _pos_inicial.first--;


    if(dir == ABAJO)
      _pos_inicial.first++;


    if(dir == IZQUIERDA)
      _pos_inicial.second--;


    if(dir == DERECHA)
      _pos_inicial.second++;

    _turno++;
}

void Juego::ingerir_pocion(uint movimientos, uint turnos){

}