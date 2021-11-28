/*
====
Funções auxiliares para o desafio.
====
*/

func acharCaminhos(grafo [][] int, ponto int, acumulado [] int, resposta *[][] int) {
	acumuladoInterno := make ([]int, len (acumulado))
	copy (acumuladoInterno, acumulado)
	for _, proximo := range grafo [ponto] {
		//To-do: adicionar previsão de loop
		acumuladoInterno = append (acumuladoInterno, proximo)
		if proximo == (len (grafo) - 1) {
			acumuladoTmp := make([] int, len (acumuladoInterno))
			copy (acumuladoTmp, acumuladoInterno)
			*resposta = append (*resposta, acumuladoTmp)
		} else { // if a == len (grafo)
			acharCaminhos (grafo, proximo, acumuladoInterno, resposta)
		} // else if a == len grafo
		acumuladoInterno = acumuladoInterno [:len (acumuladoInterno)-1]
	} // for a
} // acharCaminhos

/*
====
Função do desafio
====
*/

func allPathsSourceTarget(graph [][]int) [][]int {
	var resposta [][] int
	var acumulado [] int = [] int{0} // Adiciona o primeiro ponto
	acharCaminhos (graph, 0, acumulado, &resposta) // 0 -> Primeiro ponto.
	return resposta
}

