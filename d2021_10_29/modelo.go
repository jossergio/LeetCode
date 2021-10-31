func testePodre (grade [][] int, i int, j int) bool {
	if (i >= 0) && (i < len (grade)) && (j >= 0) && (j < len (grade [i])) {
		if grade [i][j] == 2 {
			return true
		} // if grade [i][j] == 2
	} // if i >0 ...
	return false
} // testePodre

func verificarPodre (grade [][] int, i int, j int) bool {
	return testePodre (grade, i - 1, j) ||
		testePodre (grade, i + 1, j) ||
		testePodre (grade, i, j - 1) ||
		testePodre (grade, i, j + 1)
} // verificarPodre

func orangesRotting(grid [][]int) int {
	var sair bool = false
	var retorno = 0
	for !sair {
		var mudou [] int
		for i := 0; i < len (grid); i++ {
			for j := 0; j < len (grid [i]); j++ {
				if grid [i][j] == 1 { // É fresca
					if verificarPodre (grid, i, j) {
						mudou = append (mudou, i, j) // Irá resgatar pela orgem, também
					} // if verificarPodre
				}
			} // for j
		} // for i
		if len (mudou) > 0 {
			retorno += 1
			for len (mudou) > 0 {
				i := mudou [0]
				j := mudou [1] // Lembra da ordem?
				grid [i][j] = 2
				mudou = mudou [2:]
			} // for len mudou > 0
		} else { // if len mudou > 0
			sair = true
		} // else if len mudou > 0
	} // for !sair
	for i := 0; i < len (grid); i++ { // Irá fazer o teste se sobrou alguma fresca
		for j := 0; j < len (grid [i]); j++ {
			if grid [i][j] == 1 {
				return -1
			} // if grid i j == 1
		} // for j
	} // for i
	return retorno
}

