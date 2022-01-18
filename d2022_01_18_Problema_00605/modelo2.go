func pode (i int, f [] int) (possivel bool, saltar bool) {
	if f [i] == 1 {
		return false, true // Nem tenta; provoca salto
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
    
	return contagem == 3, contagem == 3 // O anterior, o atual e o posterior são zero (0)
    // Provoca um salto, caso seja possível
} // pode

func canPlaceFlowers(flowerbed []int, n int) bool {

    var i int = 0

    for i < len (flowerbed) {
        
        possivel, salto := pode (i, flowerbed)
		
        if possivel {
			flowerbed [i] = 1
			n--
            if n == 0 {
                return true // Já termina
            }
		}
        
        if salto {
            i += 2
        } else {
            i++
        }
        
	}

    return n <= 0 // Só para garantir, pois, se for possível, sai antes
}

