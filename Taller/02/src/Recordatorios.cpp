#include <iostream>
#include <list>

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

    void incrementar_dia();
    Fecha(int mes, int dia);
    int mes();
    int dia();
  private:
    int _dia;
    int _mes;
};

void Fecha::incrementar_dia(){

    if(_dia == dias_en_mes(_mes)){
      _dia = 1;
      _mes++;
      _mes = _mes % 12;
    }
    else
      _dia++;
}

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
class Horario{
  public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator==(Horario);
    bool operator<(Horario);
  private:
    uint _hora;
    uint _min;

};

bool Horario::operator<(Horario h){

    if(this->hora() < h.hora())
      return true;

    if(this->hora() == h.hora())
      if(this->min() < h.min())
        return true;
      else
        return false;

  return false;
}

ostream& operator<<(ostream& os, Horario r) {

    os << r.hora() << ":" << r.min();
    return os;
}

bool Horario::operator==(Horario o) {
    
    return this->hora() == o.hora() and  this->min() == o.min();
}

Horario::Horario(uint hora, uint min):_hora(hora),_min(min){}

uint Horario::hora(){
  return _hora;
}

uint Horario::min(){
  return _min;
}

// Ejercicio 13

// Clase Recordatorio
class Recordatorio{
  public:
    Recordatorio(Fecha,Horario,string);
    string mensaje();
    Fecha fecha();
    Horario horario();
  private:
    string _mensaje;
    Fecha _fecha;
    Horario _horario;
};



ostream& operator<<(ostream& os, Recordatorio r) {

    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario();
    return os;
}

Recordatorio::Recordatorio(Fecha f,Horario h,string m):_mensaje(m),_fecha(f),_horario(h){}


string Recordatorio::mensaje(){
  return _mensaje;
}

Fecha Recordatorio::fecha(){
  return _fecha;
}

Horario Recordatorio::horario(){
  return _horario;
}

// Ejercicio 14

// Clase Agenda
class Agenda {
  public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();
  private:
    list<Recordatorio> _recordatorios;
    Fecha _actual;
};

bool compare(Recordatorio a, Recordatorio b){

  return a.horario() < b.horario();

}

ostream& operator<<(ostream& os, Agenda r) {

    os << r.hoy() << std::endl << "=====" << std::endl;
    
    list<Recordatorio> res = r.recordatorios_de_hoy();
    res.sort(compare);

    for(Recordatorio r : res){
      os << r << std::endl;
    }
    return os;
}

Agenda::Agenda(Fecha fecha_inicial):_actual(fecha_inicial){}

void Agenda::agregar_recordatorio(Recordatorio rec){
  _recordatorios.push_back(rec);
}

void Agenda::incrementar_dia(){
  _actual.incrementar_dia();
}

list<Recordatorio> Agenda::recordatorios_de_hoy(){
  
  list<Recordatorio> res;

  for(Recordatorio r:_recordatorios)
      if(r.fecha() == hoy())
        res.push_back(r);

  return res;
  
}

Fecha Agenda::hoy(){
  return _actual;
}
