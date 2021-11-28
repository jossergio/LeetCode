/*
Encontrar todos os caminhos em um grafo.
Desafio LeetCode 28/11/2021.
Problema 00797.
*/

package main

import "fmt"

/*
====
Funções auxiliares para o desafio.
====
*/

func acharCaminhos(grafo [][]int, ponto int, acumulado []int, resposta *[][]int) {
	acumuladoInterno := make([]int, len(acumulado))
	copy(acumuladoInterno, acumulado)
	for _, proximo := range grafo[ponto] {
		//To-do: adicionar previsão de loop
		acumuladoInterno = append(acumuladoInterno, proximo)
		if proximo == (len(grafo) - 1) {
			acumuladoTmp := make([]int, len(acumuladoInterno))
			copy(acumuladoTmp, acumuladoInterno)
			*resposta = append(*resposta, acumuladoTmp)
		} else { // if a == len (grafo)
			acharCaminhos(grafo, proximo, acumuladoInterno, resposta)
		} // else if a == len grafo
		acumuladoInterno = acumuladoInterno[:len(acumuladoInterno)-1]
	} // for a
} // acharCaminhos

/*
====
Função do desafio
====
*/

func allPathsSourceTarget(graph [][]int) [][]int {
	var resposta [][]int
	var acumulado []int = []int{0}                // Adiciona o primeiro ponto
	acharCaminhos(graph, 0, acumulado, &resposta) // 0 -> Primeiro ponto.
	return resposta
}

/*
====
Funções auxiliares gerais
====
*/

func mostrarGrafo(grafo [][]int) {
	for i := 0; i < len(grafo); i++ {
		fmt.Print(i, ": ")
		for j := 0; j < len(grafo[i]); j++ {
			fmt.Print(grafo[i][j], " ")
		} // for j
		fmt.Println()
	} // for i
} // mostrarGrafo

func main() {
	var grafo [][]int
	grafo = append(grafo, []int{4, 3, 1})
	grafo = append(grafo, []int{3, 2, 4})
	grafo = append(grafo, []int{3})
	grafo = append(grafo, []int{4})
	grafo = append(grafo, []int{})
	mostrarGrafo(grafo)
	fmt.Println(allPathsSourceTarget(grafo))
}

