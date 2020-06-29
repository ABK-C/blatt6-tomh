#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>
#include <cmath>

int main() {
  const int N = 10000;     // Anzahl Integrationspunkte
  const double M = 1;      // Masse des Zylindermantels
  const double ZM_R = 1.0; // Radius der Zylindermantels
  const double ZM_L = 1.0; // Laenge des Zylindermantels

  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  std::unique_ptr<Zylindermantel> zm(new Zylindermantel(ZM_R, ZM_L));
  std::unique_ptr<Vollzylinder> vz(new Vollzylinder(ZM_R, ZM_L));


  double J = 0;     // Massentraegheitsmoment
  double m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = zm->punkt();
    // Abstand Punkt x und Gerade a + t*u
    
    // Vektor n = ...;//Normalenvektor x-a kreuz u
    double r = 0; //|n|/|u|
    r = ((x-a).kreuz(u)).betrag() / u.betrag();
    // std::cout << x << " :" << r << std::endl;
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    J += m * r * r;
  }

  double I = 0;
  for (int i = 0; i < N; ++i) {
      Vektor x = vz->punkt();
      // Abstand Punkt x und Gerade a + t*u
      
      // Vektor n = ...;//Normalenvektor x-a kreuz u
      double r = 0; //|n|/|u|
      r = ((x-a).kreuz(u)).betrag() / u.betrag();
      // std::cout << x << " :" << r << std::endl;
      // addiere Beitrag des Massenpunktes zum Traegheitsmoment
      I += m * r * r;
    }


  //analytisch
  double Ja = M*pow(ZM_R,2)+M*a.betrag()*a.betrag();
  double Ia = 0.5*M*pow(ZM_R,2)+M*a.betrag()*a.betrag();



  std::cout << "Massentraegheitsmoment fuer einen Zylindermantel"
            << " mit a = " << a << " und u = " << u << ": " << J << std::endl;
  std::cout << "Massentraegheitsmoment fuer einen Vollzylinder"
            << " mit a = " << a << " und u = " << u << ": " << I << std::endl;
  std::cout << "Analytisch:" << " I_m = " << Ja << " I_v = " << Ia << std::endl; 

            
  return 0;
}
