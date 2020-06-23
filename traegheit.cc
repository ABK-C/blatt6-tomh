#include "Vektor.hh"
#include "Koerper.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>
#include <cmath>
#include <vector>

double traegheit(Koerper* k, Vektor a, Vektor u) {
  std::cout << "Berechne fuer " << k->name() << "\n";

  int N = 10000;
  double J = 0;
  double m = k->mass()/N;

  for (int i = 0; i < N; ++i) {
    Vektor x = k->punkt();
   
    double r = 0; 
    r = ((x-a).kreuz(u)).betrag() / u.betrag();

    J += m * r * r;
  }
  return J;
}

std::unique_ptr<Koerper> Koerperrechner(double ZM_R, double ZM_L, double ZM_M, int i){
  if(i==0){std::unique_ptr<Koerper> k(new Zylindermantel(ZM_R, ZM_L, ZM_M)); return k;}
  if(i==1){std::unique_ptr<Koerper> k(new Vollzylinder(ZM_R, ZM_L, ZM_M)); return k;}
}

//double Ausgabe(int i){
//  std::unique_ptr<Koerper> k(Koerperrechner(1,1,1,i));
//  double t = traegheit(k.get(), Vektor(0, 0, 0) , Vektor(0, 0, 1));
//  return t;
//}

void Ausgabe(std::unique_ptr<Koerper> k, Vektor a, Vektor u){
  std::cout << traegheit(k.get(),a,u) << std::endl;
}

int main(){

for(int i = 0; i<2; i++){
  Ausgabe( Koerperrechner(1, 1, 1, i), Vektor(0,0,0), Vektor(0,0,1));
  Ausgabe( Koerperrechner(1, 1, 2, i), Vektor(0,0,0), Vektor(0,0,1));
  Ausgabe( Koerperrechner(2, 1, 1, i), Vektor(0,0,0), Vektor(0,0,1));
  Ausgabe( Koerperrechner(1, 1, 1, i), Vektor(0,1,0), Vektor(0,0,1));
  Ausgabe( Koerperrechner(1, 1, 2, i), Vektor(0,1,0), Vektor(0,0,1));
  Ausgabe( Koerperrechner(2, 1, 1, i), Vektor(0,2,0), Vektor(0,0,1));
}

}
