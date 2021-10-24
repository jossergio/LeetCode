func findMin(nums []int) int {
	for i := 1; i < len (nums); i++ { // O primeiro a ser chegado é o segundo
		if nums [i] < nums [0] { // Quando encontrar um menor que o 1o elemento, é esse
			return nums [i] // É esse
		} // if nums [i] < menor
	} // for i < tamanho
	return nums [0] // Por definição, sempre haverá, pelo menos, um
}

