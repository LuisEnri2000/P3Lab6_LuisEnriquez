
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include "Jugador.cpp"

using namespace std;

#ifndef EQUIPO_CPP
#define EQUIPO_CPP

class Equipo {
	private:
		string nombre;
		string ano;
		vector<Jugador*> jugadores;
		
		int pj;
		int pg;
		int pe;
		int pp;
		int gf;
		int gc;
		int dg;
		
		
	public:
		
		Equipo(string n, string a) {
			nombre = n;
			ano = a;
			pj = 0;
			pg = 0;
			pe = 0;
			pp = 0;
			gf = 0;
			gc = 0;
			dg = 0;
		}
		
		void masPp() {
			pp++;
			pj++;
		}
		
		void masPg() {
			pg++;
			pj++;
		}
		
		void masPe() {
			pe++;
			pj++;
		}
		
		void masGf(int x) {
			gf+= x;
		}
		
		void masGc(int x) {
			gc+= x;
		}
		
		int dif() {
			return gf - gc;
		}
		
		int puntos() {
			int punt = 0;
			
			punt += pg * 3;
			punt += pe * 1;
			
			return punt;
		}
		
		void printTabla() {
			int w = 10;
			cout << setw(25) << nombre << setw(w) << pj << setw(w) << pg << setw(w) << pe << setw(w) << pp << setw(w) << gf << setw(w) << gc << setw(w) << dif() << setw(w) << puntos() << endl;
		}
		
		
		vector<Jugador*> getJugadores() {
			return jugadores;
		}
		
		string getNombre() {
			return nombre;
		}
		
		void remJugador(int p){
			
            jugadores.erase(jugadores.begin()+p);
            
        }
		
		string guardar() {
			string total = "";
			total += nombre + ":" + ano + "{";
			
			for (int i = 0; i < jugadores.size(); i++ ) {
				total+= jugadores.at(i)->guardar();
				if (i != jugadores.size()-1) {
					total+=";";	
				}				
			}
			
			total += "}";
			
			return total;	
		}
		
		void addJugador(Jugador *j) {
        	jugadores.push_back(j);
		}
		
		//funciomes virtuales puras:
		//virtual int prod() = 0;
		//virtual void print() = 0;
		
		
		~Equipo(){}
};
#endif
