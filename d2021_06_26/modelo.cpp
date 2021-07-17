#include <iostream> // std
#include <vector>

using namespace std;

vector<int> contarMenor (vector<int>& nums) {
  vector<int> retorno;
  int a, b, t = nums.size ();

  for (a = 0; a < t; a++) {
    retorno.push_back (0);
    for (b = (a + a); b < t; b++)
      retorno [a] += (nums [b] < nums [a])? 1: 0;
  } // for a
  return (retorno);
} // contarMenor

int main (int argc, char * args []) {

  vector<int> lista = { 10, 9, 11, 30, 5, 4, 3, 2, 1 };

  vector<int> resultado = contarMenor (lista);
  for (int a = 0; a < resultado.size (); a++)
    printf ("Lista [%d]: %d\n", a, resultado [a]);

} // main

