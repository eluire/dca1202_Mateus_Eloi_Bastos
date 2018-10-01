#ifndef POLIGONO_H
#define POLIGONO_H
#define NMAX 100
#include "point_class.cpp"
#include <iostream>

class Poligono{

private:

	Point arr[NMAX];
	unsigned  N;
	void copiar(Poligono Pol);
	void limpar();

public:
 	// contrutores inline
	inline Poligono():N(0){limpar();}
	inline Poligono(const Poligono &Pol){copiar(Pol);}
	inline ~Poligono(){limpar();}
	//metodos
	void setV(float x,float y);
	inline unsigned getN(){return N;}
	void translada(float a, float b);
	unsigned Area();
	void printpol();
	void rotation(Poligono Pol,float ang);
};



#endif