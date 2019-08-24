
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <typeinfo>

using namespace std;

#ifndef JUGADOR_CPP
#define JUGADOR_CPP

class Jugador {
	private:
		string nombre;
		string dorsal;
		string pais;
		
	public:
		
		Jugador(string n, string d, string p){
			nombre = n;
			dorsal = d;
			pais = p;
		}
		
		string guardar() {
			string total = "";
			total += nombre + "|" + dorsal + "|" + pais;
			return total;
		}
		
		string getNombre() {
			return nombre;
		}
		
		//funciomes virtuales puras:
		//virtual int prod() = 0;
		//virtual void print() = 0;
		
		~Jugador(){}
};
#endif
