#ifndef ZYLINDERMANTEL_HH
#define ZYLINDERMANTEL_HH

#include "Koerper.hh"
#include "Vektor.hh"

class Zylindermantel : public Koerper {
public:
  Zylindermantel(double nr, double nl, double nm);

  Vektor punkt();
  double mass() {return m_;}
  std::string name() {return "Zylindermantel";}
private:
  double r_, l_, m_;
};

#endif
