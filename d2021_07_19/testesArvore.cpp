/*
  Faz testes com árvore binária ordenada
*/

#include <iostream> // std::cout
#include "arvore.h"
#include "arvoreTeste1.h" // Define uma array para transformar em árvore binária

using namespace std;

int main (int argn, char *args []) {
  TreeNode *arvore = NULL;
  for (int a = 0; a < tamanhoValores; a++)
    incluir (&arvore, valores [a]);
  if (arvore == NULL)
    std::cout << "A árvore restou nula!" << std::endl;
  else
    ler (arvore);
} // main

