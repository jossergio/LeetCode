package main

import (
	"fmt"
)

func encontrarPrimeiro1 (nums [] int) int {
	for a := 0; a < len (nums); a++ {
		if nums [a] == 1 {
			return a
		} // if nums [a] == 1
	} // for a
	return -1
} // encontrarPrimeiro1

func findMaxConsecutiveOnes(nums []int) int {
	i := encontrarPrimeiro1 (nums)
	if (i == -1) { // Não há 1s
		return 0
	} // if i == 1
	contador := 0
	for i < len (nums) {
		contadorInterno := 0
		for i < len (nums) {
			if nums [i] == 1 {
				contadorInterno++
				i++
			} else { // if nums [i] == 1
				break
			} // else if nums [i] == 1
		} // for i < len (nums) (interno 1)
		if contadorInterno > contador {
			contador = contadorInterno
		} // if contadorInterno > contador
		contadorInterno = 0
		for i < len (nums) {
			if nums [i] == 0 {
				i++
			} else { // if nums [i] == 0
				break
			} // else if nums [i] == 0
		} // for i < len (nums) (interno 0)
	} // for i < len (nums) (externo)
	return contador
}

func mostrar (nums [] int) {
	fmt.Print (nums, " ==> ")
	fmt.Println (findMaxConsecutiveOnes (nums))
} // mostrar

func main() {
	var teste = [] int {1,1,0,1,1,1}
	mostrar (teste)
	teste = [] int {0, 1}
	mostrar (teste)
}

