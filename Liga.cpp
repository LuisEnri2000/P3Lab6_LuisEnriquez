
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include "Equipo.cpp"

using namespace std;

#ifndef LIGA_CPP
#define LIGA_CPP

class Liga {
	private:
		string nombre;
		string pais;
		vector<Equipo*> equipos;
		
	public:
		
		Liga(string n, string p){
			nombre = n;
			pais = p;
		}
		
		vector<Equipo*> getEquipos() {
			return equipos;
		}
		
		string getNombre() {
			return nombre;
		}
		
		void addEquipo(Equipo *e) {
        	equipos.push_back(e);
		}
		
		string guardar() {
			string total = "";
			total += "$" + nombre + ":" + pais;
			return total;
		}
		
		//funciomes virtuales puras:
		//virtual int prod() = 0;
		//virtual void print() = 0;
		
		
		~Liga(){}
};
#endif
