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

