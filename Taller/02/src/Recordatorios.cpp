#include <iostream>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    // Completar declaraciones funciones
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif


    Fecha(int mes, int dia);
    int mes();
    int dia();
  private:
    int _dia;
    int _mes;
};

ostream& operator<<(ostream& os, Fecha r) {

    os << r.dia() << "/" << r.mes();
    return os;
}

Fecha::Fecha(int mes, int dia):_dia(dia),_mes(mes){

}

int Fecha::mes(){
  return _mes;
}

int Fecha::dia(){

  return _dia;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    
    return this->dia() == o.dia() and  this->mes() == o.mes();
}
#endif

// Ejercicio 11, 12

// Clase Horario


// Ejercicio 13

// Clase Recordatorio


// Ejercicio 14

// Clase Agenda

