package main

import (
	"fmt"
)

func sortArrayByParityII(nums []int) []int {
	var tamanho int = len (nums)
	for i := 0; i < (tamanho - 1); i++ {
		if (nums [i] % 2) != (i % 2) {
			for j := i + 1; j < tamanho; j++ {
				if (nums [j] % 2) == (i % 2) {
					nums [i], nums [j] = nums [j], nums [i]
					break
				} // if nums [j] % 2...
			} // for j
		} // if nums [i] % 2...
	} // for a
	return nums
}

func mostrar (nums [] int) {
	fmt.Println (nums)
	fmt.Println (sortArrayByParityII (nums))
	fmt.Println (" = = =")
} // mostrar

func main() {
	var nums = [] int {4,2,5,7}
	mostrar (nums)
	nums = [] int {2, 3}
	mostrar (nums)
	nums = [] int {3, 2}
	mostrar (nums)
}

