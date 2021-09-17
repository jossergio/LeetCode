func encontrarPrimeiro (ns [] int, valor int) int {
	for i, v := range (ns) {
		if v == valor {
			return i
		} // if v == valor
	} // for i, v
	return -1
} // encontrarPrimeiro

func intersectEfetivo (nums1 [] int, nums2 [] int) [] int {
	var retorno [] int
	var indice int
	for a := 0; a < len (nums1); a++ {
		indice = encontrarPrimeiro (nums2, nums1 [a])
		if indice != -1 {
			retorno = append (retorno, nums1 [a])
			nums2 = append (nums2 [:indice], nums2 [indice + 1:]...)
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

