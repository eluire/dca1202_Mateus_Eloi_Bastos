#include <iostream>
#include "retangulo_class.h"

using namespace	std;

int main()
{

	Retangulo ret(0,0,3,4);
	ret.printpol();
	cout<<"Área do retangulo 1:"<<ret.Area()<<endl;
	ret.translada(-3,4);
	ret.printpol();
	cout<<endl<<"Área do retangulo 2:"<<ret.Area()<<endl;
	Point Pj(-1,5.5);
	ret.rotation(Pj,30);
	cout<<endl<<"Área do retangulo 3:"<<ret.Area()<<endl;
	ret.printpol();




	return 0;
}
