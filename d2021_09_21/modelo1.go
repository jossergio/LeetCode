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
	nums = nums [i:]
	for len (nums) > 0 {
		contadorInterno := 0
		for len (nums) > 0 {
			if nums [0] == 1 {
				contadorInterno++
				nums = nums [1:]
			} else { // if nums [i] == 1
				break
			} // else if nums [i] == 1
		} // for len (nums) > 0 (interno 1)
		if contadorInterno > contador {
			contador = contadorInterno
		} // if contadorInterno > contador
		contadorInterno = 0
		for len (nums) > 0 {
			if nums [0] == 0 {
				nums = nums [1:]
			} else { // if nums [i] == 0
				break
			} // else if nums [i] == 0
		} // for len (nums) > 0 (interno 0)
	} // for len (nums) > 0 (externo)
	return contador
}

