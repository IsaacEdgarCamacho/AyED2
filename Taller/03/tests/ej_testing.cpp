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

// Ejercicios 6..9
