func canCompleteCircuit(gas []int, cost []int) int {

	var tamanho int = len (gas) // Poderia ser cost
	var acumulos [] int = make ([] int, tamanho)

	posicionar := func (p int) int {
		if p < tamanho {
			return p
		}

		return p - tamanho
	} // Posicionar (closure)

	for i, v := range acumulos {
		if v >= 0 {
			for ponteiro := 0; ponteiro < tamanho; ponteiro++ {
				p := posicionar (i + ponteiro)
				if (gas [p] - cost [p]) != 0 {
					acumulos [i] += gas [p] - cost [p]
					if acumulos [i] < 0 {
						break
					}
				}
			} // for ponteiro
		} // if v >= 0
	} // range

	for i := 0; i < tamanho; i++ {
		if acumulos [i] >= 0 {
			return i
		}
	}

	return -1
}

