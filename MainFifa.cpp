#include<vector>
#include<string>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "admLigas.cpp"
#include "Liga.cpp"
#include "Equipo.cpp"
#include "Jugador.cpp"

using namespace std;

int main(){
	
	admLigas adm("./Save1.txt");
	srand(time(NULL));

	cout << "....:::: FIFA ::::...." << endl;
	
	int op = 0, sop = 0;
	bool cargo = false;
	
	while (op != 8) {
		cout << "....:::: MENU ::::...." << endl;
		cout << "1. Administrar ligas" << endl;
		cout << "2. Administrar equipos" << endl;
		cout << "3. Administrar jugadores" << endl;
		cout << "4. Jugar partido" << endl;
		cout << "5. Cargar archivo" << endl;
		cout << "6. Guardar archivo" << endl;
		cout << "7. Ver tablas" << endl;
		cout << "8. Salir" << endl;
		cout << "Opcion: ";
		cin >> op;
		
		system("CLS");
		
		if (op == 1 && cargo) {
			cout << "..:: Administrar ligar ::.." << endl;
			cout << "1. Crear liga" << endl;
			cout << "2. Eliminar liga" << endl;
			cout << "3. Listar ligas" << endl;
			cout << "Opcion: ";
			cin >> sop;
			
			system("CLS");
			
			if (sop == 1) {
				string n, p;
				cout << ".: Crear liga :." << endl;
				
				cout << "Ingrese el nombre: ";
				cin >> n;
				cout << "Ingrese el pais: ";
				cin >> p;
				
				adm.addLiga(new Liga(n,p));
				
				
				
				cout << ".: Creada con exito! :." << endl;
				
			}
			
			if (sop == 2) {
				int eli = 0;
				
				cout << ".: Eliminar liga :." << endl;
				for (int i = 0; i < adm.getLigas().size(); i++) {
					cout << i << ". " << adm.getLigas().at(i)->getNombre() << endl;
				}
				
				cout << "Posicion a eliminar: ";
				cin >> eli;
				
				adm.remLiga(eli);
				
				cout << ".: Eliminada con exito :." << endl;
				
			}
			
			if (sop == 3) {
				cout << "..:: LIGAS ::.." << endl;
				for (int i = 0; i < adm.getLigas().size(); i++) {
					cout << i << ". " << adm.getLigas().at(i)->getNombre() << endl;
				}
				cout << "..:::::::::::.." << endl;
			}
			
		}
		
		if (op == 2 && cargo) {
			cout << "..:: Administrar equipos ::.." << endl;
			cout << "1. Crear equipo" << endl;
			cout << "2. Eliminar equipo" << endl;
			cout << "3. Listar equipos" << endl;
			cout << "Opcion: ";
			cin >> sop;
			
			system("CLS");
			
			if (sop == 1) {
				cout << ".: Crear equipo :." << endl;
				
				string n, a;
				
				cout << "Nombre: ";
				cin >> n;
				cout << "Ano: ";
				cin >> a;
				
				
				int pos = 0;
				
				cout << "..:: Elige una liga a agregar ::.." << endl;
				for (int i = 0; i < adm.getLigas().size(); i++) {
					cout << i << ". " << adm.getLigas().at(i)->getNombre() << endl;
				}
				
				cout << "Posicion de liga: ";
				cin >> pos;
				
				adm.getLigas().at(pos)->addEquipo(new Equipo(n,a));
				
				cout << "..:: Equipo agregado con exito ::.." << endl;
				
				
			}
			
			if (sop == 2) {
				
				int pos = 0, pos2 = 0;
				
				cout << "..:: Eliminar equipo ::.." << endl;
				
				cout << "..:: Elige una liga ::.." << endl;
				for (int i = 0; i < adm.getLigas().size(); i++) {
					cout << i << ". " << adm.getLigas().at(i)->getNombre() << endl;
				}
				
				cout << "Posicion de liga: ";
				cin >> pos;
				
				cout << "..:: Elige un equipo ::.." << endl;
				for (int i = 0; i < adm.getLigas().at(pos)->getEquipos().size(); i++) {
					cout << i << ". " << adm.getLigas().at(pos)->getEquipos().at(i)->getNombre() << endl;
				}
				
				cout << "Posicion de equipo: ";
				cin >> pos2;
				
				for (int i = 0; i < adm.getLigas().at(pos)->getEquipos().at(pos2)->getJugadores().size(); i++) {
					cout << i << ". " << adm.getLigas().at(pos)->getEquipos().at(pos2)->getJugadores().at(i)->getNombre();	
				}
				
			}
			
			if (sop == 3) {
				int pos = 0, pos2 = 0;
				
				cout << "..:: Listar equipos ::.." << endl;
				
				cout << "..:: Elige una liga ::.." << endl;
				for (int i = 0; i < adm.getLigas().size(); i++) {
					cout << i << ". " << adm.getLigas().at(i)->getNombre() << endl;
				}
				
				cout << "Posicion de liga: ";
				cin >> pos;
				
				cout << "..:: Equipos ::.." << endl;
				for (int i = 0; i < adm.getLigas().at(pos)->getEquipos().size(); i++) {
					cout << i << ". " << adm.getLigas().at(pos)->getEquipos().at(i)->getNombre() << endl;
				}
				
				cout << ":::::::::::::::::::::::::::::::::::::::::" << endl;
			}
		}
		
		if (op == 3 && cargo) {
			cout << "..:: Administrar jugadores ::.." << endl;
			cout << "1. Crear jugador" << endl;
			cout << "2. Eliminar jugador" << endl;
			cout << "3. Listar jugadores" << endl;
			cout << "Opcion: ";
			cin >> sop;
			
			system("CLS");
			
			if (sop == 1) {
				string n, d, p;
				
				cout << "..:: Crear jugador ::.." << endl;
				cout << "Nombre: ";
				cin >> n;
				cout << "Dorsal: ";
				cin >> d;
				cout << "Pais: ";
				cin >> p;
				
				int pos = 0, pos2 = 0;
				
				cout << "..:: Elige una liga ::.." << endl;
				for (int i = 0; i < adm.getLigas().size(); i++) {
					cout << i << ". " << adm.getLigas().at(i)->getNombre() << endl;
				}
				
				cout << "Posicion de liga: ";
				cin >> pos;
				
				cout << "..:: Elige un equipo ::.." << endl;
				for (int i = 0; i < adm.getLigas().at(pos)->getEquipos().size(); i++) {
					cout << i << ". " << adm.getLigas().at(pos)->getEquipos().at(i)->getNombre() << endl;
				}
				
				cout << "Posicion de equipo: ";
				cin >> pos2;
				
				adm.getLigas().at(pos)->getEquipos().at(pos2)->addJugador(new Jugador(n,d,p));
			}
			
			if (sop == 2) {
				int pos = 0, pos2 = 0, pos3 = 0;
				
				cout << "..:: Elige una liga ::.." << endl;
				for (int i = 0; i < adm.getLigas().size(); i++) {
					cout << i << ". " << adm.getLigas().at(i)->getNombre() << endl;
				}
				
				cout << "Posicion de liga: ";
				cin >> pos;
				
				cout << "..:: Elige un equipo ::.." << endl;
				for (int i = 0; i < adm.getLigas().at(pos)->getEquipos().size(); i++) {
					cout << i << ". " << adm.getLigas().at(pos)->getEquipos().at(i)->getNombre() << endl;
				}
				
				cout << "Posicion de equipo: ";
				cin >> pos2;
				
				for (int i = 0; i < adm.getLigas().at(pos)->getEquipos().at(pos2)->getJugadores().size(); i++) {
					cout << i << ". " << adm.getLigas().at(pos)->getEquipos().at(pos2)->getJugadores().at(i)->getNombre();	
				}
				cout << "Posicion del jugador: ";
				cin >> pos3;
				
				adm.getLigas().at(pos)->getEquipos().at(pos2)->remJugador(pos3);
				
				cout << "Eliminado con exito!" << endl;
			}
			
			if (sop == 3) {
				int pos = 0, pos2 = 0, pos3 = 0;
				
				cout << "..:: Elige una liga ::.." << endl;
				for (int i = 0; i < adm.getLigas().size(); i++) {
					cout << i << ". " << adm.getLigas().at(i)->getNombre() << endl;
				}
				
				cout << "Posicion de liga: ";
				cin >> pos;
				
				cout << "..:: Elige un equipo ::.." << endl;
				for (int i = 0; i < adm.getLigas().at(pos)->getEquipos().size(); i++) {
					cout << i << ". " << adm.getLigas().at(pos)->getEquipos().at(i)->getNombre() << endl;
				}
				
				cout << "Posicion de equipo: ";
				cin >> pos2;
				
				cout << "...::: JUGADORES :::..." << endl;
				
				for (int i = 0; i < adm.getLigas().at(pos)->getEquipos().at(pos2)->getJugadores().size(); i++) {
					cout << i << ". " << adm.getLigas().at(pos)->getEquipos().at(pos2)->getJugadores().at(i)->getNombre() << endl;	
				}
			}
			
		}
		
		if (op == 4 && cargo) {
			// Partidos
			cout << "...::: JUGAR PARTIDO :::..." << endl;
			int pos = 0, pos2 = 0, pos3 = 0;
				
			cout << "..:: Elige una liga ::.." << endl;
			for (int i = 0; i < adm.getLigas().size(); i++) {
				cout << i << ". " << adm.getLigas().at(i)->getNombre() << endl;
			}
				
			cout << "Posicion de liga: ";
			cin >> pos;
				
			cout << "..:: Elige un equipo ::.." << endl;
			for (int i = 0; i < adm.getLigas().at(pos)->getEquipos().size(); i++) {
				cout << i << ". " << adm.getLigas().at(pos)->getEquipos().at(i)->getNombre() << endl;
			}
				
			cout << "Posicion de equipo: ";
			cin >> pos2;
			
			cout << "..:: Elige otro ::.." << endl;
			for (int i = 0; i < adm.getLigas().at(pos)->getEquipos().size(); i++) {
				cout << i << ". " << adm.getLigas().at(pos)->getEquipos().at(i)->getNombre() << endl;
			}
				
			cout << "Posicion de equipo: ";
			cin >> pos3;
			
			int alv = 0, gol1 = 0, gol2 = 0;
			
			if (pos2 != pos3) {
				cout << "..:: Resultado ::.." << endl;
				cout << "1. Random" << endl;
				cout << "2. Por teclado" << endl;
				cout << "Opcion: " << endl;
				cin >> alv;
				
				if (alv == 2) {
					cout << "Goles del 1: ";
					cin >> gol1;
					cout << "Goles del 2: ";
					cin >> gol2;
					
					adm.getLigas().at(pos)->getEquipos().at(pos2)->masGf(gol1);
					adm.getLigas().at(pos)->getEquipos().at(pos2)->masGf(gol2);
					
					adm.getLigas().at(pos)->getEquipos().at(pos3)->masGf(gol2);
					adm.getLigas().at(pos)->getEquipos().at(pos3)->masGf(gol1);
					
				}else{
					gol1 = rand()%6;
					gol2 = rand()%6;
				}
				
				if (gol1 == gol2) {
					adm.getLigas().at(pos)->getEquipos().at(pos2)->masPe();
					adm.getLigas().at(pos)->getEquipos().at(pos3)->masPe();
					
					adm.getLigas().at(pos)->getEquipos().at(pos2)->masGf(gol1);
					adm.getLigas().at(pos)->getEquipos().at(pos2)->masGf(gol2);
					
					adm.getLigas().at(pos)->getEquipos().at(pos3)->masGf(gol2);
					adm.getLigas().at(pos)->getEquipos().at(pos3)->masGf(gol1);
				}
				
				if (gol1 < gol2) {
					adm.getLigas().at(pos)->getEquipos().at(pos2)->masPp();
					adm.getLigas().at(pos)->getEquipos().at(pos3)->masPg();
					
					adm.getLigas().at(pos)->getEquipos().at(pos2)->masGf(gol1);
					adm.getLigas().at(pos)->getEquipos().at(pos2)->masGf(gol2);
					
					adm.getLigas().at(pos)->getEquipos().at(pos3)->masGf(gol2);
					adm.getLigas().at(pos)->getEquipos().at(pos3)->masGf(gol1);
				}
				
				if (gol1 > gol2) {
					adm.getLigas().at(pos)->getEquipos().at(pos2)->masPg();
					adm.getLigas().at(pos)->getEquipos().at(pos3)->masPp();
					
					adm.getLigas().at(pos)->getEquipos().at(pos2)->masGf(gol1);
					adm.getLigas().at(pos)->getEquipos().at(pos2)->masGf(gol2);
					
					adm.getLigas().at(pos)->getEquipos().at(pos3)->masGf(gol2);
					adm.getLigas().at(pos)->getEquipos().at(pos3)->masGf(gol1);
				}
				
			}
		}
		
		if (op == 5) {
			cout << "...::: CARGAR ARCHIVO :::..." << endl;
			cout << "Archivo cargado con exito!" << endl;
			// lit
			cargo = true;
			adm.leer();
			cout << "............................." << endl;
		}
		
		if (op == 6 && cargo) {
			cout << "...::: GUARDAR ARCHIVO :::..." << endl;
			cout << "Guardado con exito! Puede cerrar sin miedo!" << endl;
			adm.escribir();
			cout << "............................." << endl;
		}
		
		if (op == 7 && cargo) {
			// Ver tablas
			int w = 10;
			
			cout << setw(25) <<"Equipo" << setw(w) << "PJ" << setw(w) << "PG" << setw(w) << "PE" << setw(w) << "PP" << setw(w) << "GF" << setw(w) << "GC" << setw(w) << "DF" << setw(w) << "Pts." << endl;
			
			for (int i = 0; i < adm.getLigas().size(); i ++) {
				for (int j = 0; j < adm.getLigas().at(i)->getEquipos().size(); j++) {
					adm.getLigas().at(i)->getEquipos().at(j)->printTabla();
				}
			}
		}
		
		if (!cargo) {
			cout << "Te recomiendo cargar el archivo primero!" << endl;
		}
		
		system("pause");
		system("CLS");
	}

	
}
