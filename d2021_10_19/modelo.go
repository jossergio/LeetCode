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

