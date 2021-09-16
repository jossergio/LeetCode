package main

import (
	"fmt"
)

func testeTipo (valor *int, tmp *int) {
	if *tmp > *valor {
		*valor = *tmp
	}
	*tmp = 1
} // testeTipo

func maxTurbulenceSize(arr []int) int {
	if len (arr) < 2 {
		return 1
	} // if len (arr) < 3
	var tipo1 int = 1
	var tipo2 int = 1
	var tmpTipo1 int = 1
	var tmpTipo2 int = 1
	for k := 0; k < len (arr) -1; k++ {
		if (k % 2) == 1 {
			if arr [k] > arr [k + 1] {
				tmpTipo1++
				testeTipo (&tipo2, &tmpTipo2)
			} else { // if arr [k] > arr [k + 1]
				if arr [k] < arr [k + 1] {
					tmpTipo2++
					testeTipo (&tipo1, &tmpTipo1)
				} else { // if arr [k] < arr [k + 1]
					// Podem ser iguais
					testeTipo (&tipo1, &tmpTipo1)
					testeTipo (&tipo2, &tmpTipo2)
				} // else if arr [k] < arr [k + 1]
			} // else if arr [k] > arr [k + 1]
		} else { // if (k % 2) == 1
			if arr [k] < arr [k + 1] {
				tmpTipo1++
				testeTipo (&tipo2, &tmpTipo2)
			} else { // if arr [k] > arr [k + 1]
				if arr [k] > arr [k + 1] {
					tmpTipo2++
					testeTipo (&tipo1, &tmpTipo1)
				} else { // if arr [k] < arr [k + 1]
					// Podem ser iguais
					testeTipo (&tipo1, &tmpTipo1)
					testeTipo (&tipo2, &tmpTipo2)
				} // else if arr [k] < arr [k + 1]
			} // else if arr [k] > arr [k + 1]
		} // else if (k % 2) == 1
	} // for a
	testeTipo (&tipo1, &tmpTipo1)
	testeTipo (&tipo2, &tmpTipo2)
	if tipo1 < tipo2 { // Sacou?
		tipo1 = tipo2
	} // if tipo1 < tipo2
	return tipo1
}

func mostrar (arr [] int) {
	fmt.Println (maxTurbulenceSize (arr), " ==> ", arr)
} // mostrar

func main() {
	var arr = [] int {9,4,2,10,7,8,8,1,9}
	mostrar (arr)
	arr = [] int {4,8,12,16}
	mostrar (arr)
	arr = [] int {8,8,9,10,6,8,2,4,2,2,10,6,6,10,10,2,3,5,1,2,10,4,2,0,9,4,9,3,0,6,3,2,3,10,10,6,
	4,6,4,4,2,5,1,4,1,1,9,8,9,5,3,5,5,4,5,5,6,5,3,
	3,7,2,0,10,9,7,7,3,5,1,0,9,6,3,1,3,4,4,3,6,3,2,1,4,10,2,3,4,4,3,6,7,6,2,1,7,0,6,8,10}
	mostrar (arr)
	arr = [] int {4,8}
	mostrar (arr)
}

