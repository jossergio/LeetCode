package main

import (
	"fmt"
)

func rangeBitwiseAnd(left int, right int) int {
	acumulador := left & right
	for a := left; a <= right; a++ {
        	acumulador &= a
		if acumulador == 0 {
			return 0
		}
	} // for a
	return acumulador
}

func mostrar (i int, f int) {
	fmt.Println ("Bitwise and entre ", i, " e ", f, ": ", rangeBitwiseAnd (i, f))
} // mostrar

func main() {
	mostrar (1, ((1 << 31) - 1))
	mostrar (4, 7)
}

