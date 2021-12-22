#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();
        //ostream& operator<<(ostream& os, Rectangulo r);

    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho): alto_(alto),
                                               ancho_(ancho) {};

uint Rectangulo::alto() {
    return alto_;
}

// Completar definición: ancho
uint Rectangulo::ancho(){
    return ancho_;
}
// Completar definición: area
float Rectangulo::area(){
    return ancho() * alto();
}
// Ejercicio 2

// Clase Elipse
class Elipse{
    public:
        Elipse(uint, uint);
        uint r_a();
        uint r_b();
        float area();
    private:
        uint a;
        uint b;
        float pi;
};

Elipse::Elipse(uint ra, uint rb):a(ra),b(rb){
    pi = 3.14;
}

uint Elipse::r_a(){
    return a;    
}

uint Elipse::r_b(){
    return b;
}

float Elipse::area(){
    return a * b * pi;
}
// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
    return r_.alto();
}

float Cuadrado::area() {
    r_.area();
}

// Ejercicio 4

// Clase Circulo
class Circulo{
    public:
        Circulo(uint radio);
        uint radio();
        float area();
    private:
        Elipse e;

};

Circulo::Circulo(uint radio):e(radio,radio){}

uint Circulo::radio(){
    return e.r_a();
}

float Circulo::area(){
    return e.area();
}

// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

// ostream Elipse
ostream& operator<<(ostream& os, Elipse r) {
    os << "Elipse(" << r.r_a() << ", " << r.r_b() << ")";
    return os;
}
// Ejercicio 6

