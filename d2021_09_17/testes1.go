package main

import (
	"fmt"
)

func encontrarPrimeiro (ns [] int, valor int) int {
	for i, v := range (ns) {
		if v == valor {
			return i
		} // if v == valor
	} // for i, v
	return -1
} // encontrarPrimeiro

func intersectEfetivo (nums1 [] int, nums2 [] int) [] int {
	var tmp [] int = make ([] int, len (nums2))
	copy (tmp, nums2)
	var retorno [] int
	var indice int
	for a := 0; a < len (nums1); a++ {
		indice = encontrarPrimeiro (tmp, nums1 [a])
		if indice != -1 {
			retorno = append (retorno, nums1 [a])
			tmp = append (tmp [:indice], tmp [indice + 1:]...)
		} // if indice != -1
	} // for a
	return retorno
} // intersectEfetivo

func intersect(nums1 []int, nums2 []int) []int {
	if len (nums1) < len (nums2) {
		return intersectEfetivo (nums1, nums2)
	}
	return intersectEfetivo (nums2, nums1)
}

func mostrar (nums1 [] int, nums2 [] int) {
	fmt.Println ("====")
	fmt.Println (nums1)
	fmt.Println (nums2, " S")
	fmt.Println (intersect (nums1, nums2))
} // mostrar

func main() {
	var ns1 = [] int {1, 2, 2, 1}
	var ns2 = [] int {2, 2}
	mostrar (ns1, ns2)
	ns1 = [] int {4,9,5}
	ns2 = [] int {9,4,9,8,4}
	mostrar (ns1, ns2)
}

