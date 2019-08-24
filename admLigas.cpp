
// Administrador de ligas
#include<iostream> 
#include<string> 
#include <fstream>
#include <stdlib.h>
#include "Liga.cpp"
#include "Equipo.cpp"
#include<string.h>
#include <vector>
#include <bits/stdc++.h>


#ifndef ADMLIGAS_CPP
#define ADMLIGAS_CPP

using namespace std;
class admLigas{
      private:
              string ruta;
              vector<Liga*> ligas;                           
      public:
             
            admLigas(string ruta) {
               	this->ruta=ruta;
			}
			
            string getRuta() {
            	return ruta;
			} 
            
            void addLiga(Liga *l){
                ligas.push_back(l);
		    }
            
            vector<Liga*> getLigas(){
                return this->ligas;
            } 

			void remLiga(int p){
                ligas.erase(ligas.begin()+p);
             }
			 
			 int getN(){
               	ligas.size();
			}             
            
            ~admLigas(){}
            
            string token(string cadena, string divisor, 
                                    int pos){
               if(cadena.size()>0){
                 char oracion[cadena.size()]; 
                 for (int i=0;i<=cadena.size();i++)
                 {oracion[i]=cadena[i];}                    
                 char *ptrtoken; 
                 int num=1;
                 const char* d=divisor.c_str();
                 ptrtoken = strtok(oracion , d);             
                 while(ptrtoken){
                     if(num==pos){ 
                        return ptrtoken;}                 
                     ptrtoken = strtok(NULL, d);
                     num++;}
                 return "";
               }else{return "";}
            }
            
        void escribir(){
          	ofstream Escribir;
          	Escribir.open(ruta.c_str());  
          	for(int i=0; i < ligas.size();i++) {
          		
                Escribir<<ligas.at(i)->guardar()<<endl;
                
                for (int j = 0; j < ligas.at(i)->getEquipos().size(); j++) {
                	Escribir << ligas.at(i)->getEquipos().at(j)->guardar() << endl;
				}
				
			}             
          Escribir.close(); 
        }
           
		  
        void leer(){
                fstream Leer;
                string linea;
                ligas.clear();                 
                Leer.open(ruta.c_str()); 
                if (Leer.is_open()){                 
                    while(! Leer.eof()){
                            getline(Leer,linea);
							//cout << "Linea: " << linea << endl;
							 
                            if(linea.size()>0){
                            	
                            	cout << "Linea: " << linea << endl;
                            	
							 	if (linea[0] == '$') {
							 		
							 		linea = linea.substr(1,linea.size());
							 		
							 		cout << linea << endl;
							 		
							 		cout << "Es la liga " << token(linea,":" ,1) << endl;
											
									addLiga(new Liga(token(linea,":", 1), token(linea,":", 2)));  
									
								}else{
									int lim = 1;
									
									for (int i = 0; i < linea.size(); i++) {
										if (linea[i] == '{') 
											lim = i;
											
										
									} 
									
									//cout << "El limite es: " << lim;
									
									if (lim != 1) {
										
										
										string sub1, sub2;
										sub1 = linea.substr(0, lim);
										sub2 = linea.substr(lim + 1, linea.size() - 1);
										sub2 = sub2.substr(0, sub2.size() - 1);
										
										cout << "Sub1: " << sub1 << endl;
										cout << "Sub2: " << sub2 << endl;
										
										// agregar equipo a liga actual
										ligas.at(ligas.size() - 1)->addEquipo(new Equipo(token(sub1, ":", 1), token(sub1,":",2)));
										
										// agregar jugadores
										int tok = 1;
										while (true) {
											if (token(sub2,";",tok) == "") {
												break;
											}
											
											string jug = token(sub2, ";", tok);
											string n, d, p;
											
											n = token(jug, "|", 1);
											d = token(jug, "|", 2);
											p = token(jug, "|", 3);
											
											ligas.at(ligas.size() - 1)->getEquipos().at(ligas.at(ligas.size() - 1)->getEquipos().size() - 1)->addJugador(new Jugador(n,d,p));
											
											tok ++;
										}
									}
								}
                                                    
                            }else{
                            	cout << "0 tamano" << endl;
							}
                    }
                } 
				   
                Leer.close();
            }
            
			/*             
             void print(){
                  cout<<"Personas:"<<endl;
                
                for(int i=0; i<personas.size();i++){
				        cout<<"\t"<<"-";				    	
						personas.at(i)->print();				    
				  }
            } 
            */
			            
};
#endif
