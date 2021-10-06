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

