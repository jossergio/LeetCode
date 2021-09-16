func testeTipo (valor *int, tmp *int) {
	if *tmp > *valor {
		*valor = *tmp
	}
	*tmp = 1
} // testeTipo

func maxTurbulenceSize(arr []int) int {
	if len (arr) < 2 {
		return 1
	} // if len (arr) < 3
	var tipo1 int = 1
	var tipo2 int = 1
	var tmpTipo1 int = 1
	var tmpTipo2 int = 1
	for k := 0; k < len (arr) -1; k++ {
		if (k % 2) == 1 {
			if arr [k] > arr [k + 1] {
				tmpTipo1++
				testeTipo (&tipo2, &tmpTipo2)
			} else { // if arr [k] > arr [k + 1]
				if arr [k] < arr [k + 1] {
					tmpTipo2++
					testeTipo (&tipo1, &tmpTipo1)
				} else { // if arr [k] < arr [k + 1]
					// Podem ser iguais
					testeTipo (&tipo1, &tmpTipo1)
					testeTipo (&tipo2, &tmpTipo2)
				} // else if arr [k] < arr [k + 1]
			} // else if arr [k] > arr [k + 1]
		} else { // if (k % 2) == 1
			if arr [k] < arr [k + 1] {
				tmpTipo1++
				testeTipo (&tipo2, &tmpTipo2)
			} else { // if arr [k] > arr [k + 1]
				if arr [k] > arr [k + 1] {
					tmpTipo2++
					testeTipo (&tipo1, &tmpTipo1)
				} else { // if arr [k] < arr [k + 1]
					// Podem ser iguais
					testeTipo (&tipo1, &tmpTipo1)
					testeTipo (&tipo2, &tmpTipo2)
				} // else if arr [k] < arr [k + 1]
			} // else if arr [k] > arr [k + 1]
		} // else if (k % 2) == 1
	} // for a
	testeTipo (&tipo1, &tmpTipo1)
	testeTipo (&tipo2, &tmpTipo2)
	if tipo1 < tipo2 { // Sacou?
		tipo1 = tipo2
	} // if tipo1 < tipo2
	return tipo1
}

