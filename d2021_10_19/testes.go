package main

import (
	"fmt"
)

func nextGreaterElement(nums1 []int, nums2 []int) []int {
	var retorno [] int
	for a := 0; a < len (nums1); a++ {
		encontrou := false
		for b := 0; b < len (nums2); b++ {
			if encontrou {
				if nums2 [b] > nums1 [a] {
					retorno = append (retorno, nums2 [b])
					break
				}
			} else { // if encontrou
				encontrou = nums1 [a] == nums2 [b]
			} // else if encontrou
		} // for b
		if !encontrou || (len (retorno) - 1) < a {
			retorno = append (retorno, -1)
		} // if !encontrou
	} // for a
	return retorno
}

func mostrar (nums1 [] int, nums2 [] int) {
	fmt.Println (nums1, " ==> ", nums2, " | ", nextGreaterElement (nums1, nums2))
} // mostrar

func main() {
	var nums1 = [] int {4, 1, 2}
	var nums2 = [] int {1, 3, 4, 2}
	mostrar (nums1, nums2)
	nums1 = [] int {2, 4}
	nums2 = [] int {1, 2, 3, 4}
	mostrar (nums1, nums2)
}

