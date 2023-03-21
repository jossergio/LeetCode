func pode (i int, f [] int) bool {
	if f [i] == 1 {
		return false // Nem tenta
	}

	var contagem int = 1 // Pressupõe o próprio ser zero (0)
	if i == 0 {
		contagem++
	} else {
		if f [i-1] == 0 {
			contagem++
		}
	}

	if i == (len (f) - 1) {
		contagem++
	} else {
		if f [i+1] == 0 {
			contagem++
		}
	}

	return contagem == 3 // O anterior, o atual e o posterior são zero (0)
} // pode

func canPlaceFlowers(flowerbed []int, n int) bool {
	for i := 0; i < len (flowerbed); i++ {
		if pode (i, flowerbed) {
			flowerbed [i] = 1
			n--
		}
	}
	return n <= 0
}

