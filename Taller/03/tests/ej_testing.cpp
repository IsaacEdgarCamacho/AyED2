#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
	int esperado = 17 + 5;
	int calculado = 22;
	EXPECT_EQ(calculado, esperado);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
	float calculado = 100;
	float esperado = pow(10, 2);
	EXPECT_EQ(calculado, esperado);
}

// Ejercicios 6.
TEST(Aritmetica, potenci_general){

	for (int i = -5; i < 6; ++i){
		
		float calculado = i * i;
		float esperado = pow(i, 2);
		EXPECT_EQ(calculado, esperado);
	}
}

TEST(Diccionario, obtener){
	map<int , int> m;
	m[4] = 8;

	int esperado = 8;
	int calculado = m[4];

	EXPECT_EQ(calculado, esperado);
}

TEST(Diccionario, definir){

	map<int,int> m;

	EXPECT_EQ(m.count(5), 0);

	m[5] = 10;

	EXPECT_EQ(m.count(5), 1);

	EXPECT_EQ(m.count(6), 0);
	m.insert(make_pair(6,12));
	EXPECT_EQ(m.count(6),1);
}


TEST(Truco, inicio){

	Truco t;

	EXPECT_EQ( t.puntaje_j1(), 0);
	EXPECT_EQ(t.puntaje_j2(), 0);
}



TEST(Truco, buenas){

	Truco t;

	EXPECT_FALSE (t.buenas(1));
	for (int i = 0; i < 15; ++i)
		t.sumar_punto(1);
	
	EXPECT_FALSE(t.buenas(1));

	t.sumar_punto(1);

	EXPECT_TRUE(t.buenas(1));

	t.sumar_punto(1);
	t.sumar_punto(1);
	EXPECT_TRUE(t.buenas(1));	
}