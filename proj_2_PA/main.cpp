#include "figura_geometrica.h"
#include "screen.h"
#include "reta.h"
#include "circulo.h"
#include "retangulo.h"
#include "figura_geometrica.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {

  ifstream file;
  Screen tela(0,0);
  vector<Figura_geometrica *> figs;

  file.open("figuras.txt");
  if(!file.is_open()) {
    cout << "Error ao abrir o arquivo de instruções!\n";
    return -1;
  }
  while(file.good()) {
    string instruction,cmd;
    getline(file, instruction);
    instruction += " ";

    if(!file.good()) break;

    stringstream ss(instruction);

    ss >> cmd;

    if(cmd.compare("dim") == 0) {
      int nl ,nc;
      ss >> nl >> nc;

      tela = Screen(nl,nc);
    }

    else if(cmd.compare("line") == 0) {
      int x0, y0, x1, y1;
      char brush;

      ss >> x0 >> y0 >> x1 >> y1 >> brush;

      if(ss.good()){
        figs.push_back(new Reta(x0, y0, x1, y1, brush));
      }
      else {
        figs.push_back(new Reta(x0, y0, x1, y1, ' '));
      }
    }

    else if(cmd.compare("rectangle") == 0) {
      int x0, y0, largura,altura;
      bool fillMode;
      char brush;

      ss >> x0 >> y0 >> largura >> altura >> fillMode >> brush;

      if(ss.good()){
        figs.push_back(new Retangulo(x0, y0, largura, altura, fillMode, brush));
      }else {
        figs.push_back(new Retangulo(x0, y0, largura, altura, fillMode, ' '));
      }

    }else if(cmd.compare("circle") == 0) {
      int xc, yc, raio;
      bool fillMode;
      char brush;

      ss >> xc >> yc >> raio >> fillMode >> brush;

      if(ss.good()){
        figs.push_back(new Circulo(xc, yc, raio, fillMode, brush));

      }else {
        figs.push_back(new Circulo(xc, yc, raio, fillMode,' '));
      }

    }
  }

  file.close();


  for(Figura_geometrica* fig : figs) {
    fig->draw(tela);
  }

  cout << endl << tela << endl;

  ofstream out_file;
  out_file.open("output.txt");

  if(!out_file.is_open()) {
    cout << "Error ao abrir o arquivo de saida!\n";
    return -1;
  }

  out_file << tela;

  out_file.close();

  return 0;
}
