#include <iostream>

int *countSmaller (int *nums, int numsSize, int *returnSize) {
  returnSize = malloc (sizeof (int) * numsSize);
  int a, b;

  for (a = 0; a < numsSize; a++) {
    returnSize [a] = 0;
    for (b = (a + 1); b < numsSize; b++)
      returnSize [a] += (nums [b] < nums [a])? 1 : 0;
  } // for a

  return (returnSize);
} // countSmaller

int main (int argc, char *args []) {

  int lista [9] = {10, 9, 11, 30, 5, 4, 3, 2, 1};
  int *retorno;

  retorno = countSmaller (lista, 9, retorno);

  int *p = retorno;
  for (int a = 0; a < 9; a++)
    printf ("|- %d - | \n", *(p++));

  free (retorno);
} //main

