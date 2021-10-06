package main

import (
	"fmt"
)

func findDuplicates(nums []int) []int {
	var retorno [] int
	tmp := make (map [int] bool)
	for _, valor := range (nums) {
		_, existe := tmp [valor]
		if existe {
			retorno = append (retorno, valor)
		} else { // if existe
			tmp [valor] = true // Cria
		} // else if existe
	} // for n, v...
	return retorno
}

func mostrar (nums [] int) {
	fmt.Print (nums)
	fmt.Print (" | ")
	fmt.Print (findDuplicates (nums))
} // mostrar

func main() {
	var exemplo [] int
	exemplo = [] int {4,3,2,7,8,2,3,1}
	mostrar (exemplo)
}

