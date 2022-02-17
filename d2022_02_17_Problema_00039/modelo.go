var candidatos [] int
var respostas [][] int
var acumulado int // Para evitar somar a cada iteração
var objetivo int // Só para não ficar na recursitidade

func responder (valores [] int, atual int) {

	for i := atual; i < len(valores); i++ {
		if (acumulado + valores[i]) < objetivo {
			candidatos = append(candidatos, valores[i])
			acumulado += valores[i]
			responder(valores, i)
			acumulado -= valores[i]
			candidatos = candidatos[0 : len(candidatos)-1]
		} else {
			if (acumulado + valores[i]) == objetivo {
				candidatos = append(candidatos, valores[i])
				adicionar := make([]int, len(candidatos))
				copy(adicionar, candidatos)
				respostas = append(respostas, adicionar)
				candidatos = candidatos[0 : len(candidatos)-1]
			}
		}
	} // for
        
}

func combinationSum(candidates []int, target int) [][]int {
    objetivo = target
    respostas = make ([][]int, 0)
    candidatos = make ([]int, 0)
    acumulado = 0
    responder (candidates, 0)
    return respostas
}

