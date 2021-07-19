/*
  Testa o modelo1.h
*/

#include <iostream>
#include <string>

#include "modelo1.h"

using namespace std;

int main (int narg, char * args []) {
  string teste = "fksldkfjshaadbkfalsckdbjfl";
  string ordem = "abc";
  Solution solucao;
  cout << solucao.customSortString (ordem, teste) << endl;
return (0);
} // main

