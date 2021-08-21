package main

import (
	"fmt"
)

var valores = [] string {"1", "2", "3", "4", "5", "6", "7", "8", "9"}

func podeUsar (q [][] string, a int, b int, i string) bool {
	for zz := 0; zz < 9; zz++ {
		if q [a][zz] == i || q [zz][b] == i {
			return false
		} // if q...
	} // for zz
	for za := 0; za < 3; za++ {
		for zb := 0; zb < 3; zb++ {
			if q [3 * (a / 3) + za][3 * (b / 3) + zb] == i {
				return false
			} // if q...
		} // for zb
	} // for za
	return true
} // podeUsar

func mostrarQuadro (q [][] string) {
	fmt.Println ("= = = = =")
	for a := 0; a < 9; a++ {
		fmt.Print ("[")
		for b := 0; b < 9; b++ {
			fmt.Print (q [a][b])
			if b < 8 {
				fmt.Print (" ")
			} // if b < 8
		} // for b
		fmt.Println ("]")
	} // for a
} // mostrarQuadro

func checar (quadro [][] string) bool {
	temPonto := false
	// mostrarQuadro (quadro)
	for a := 0; a < 9; a++ {
		for b := 0; b < 9; b++ {
			if quadro [a][b] == "." {
				temPonto = true
				for _, item := range valores {
					if podeUsar (quadro, a, b, item) {
						quadro [a][b] = item
						if checar (quadro) {
							return true
						} else { // if checar quadro
							quadro [a][b] = "."
						} // else if checar quadro
					} // if podeUsar ...
				} // for item range valores
				return false
			} // if quadro ... == "."
		} // for b
	} // for a
	return !temPonto
} // checar

func main() {
	var board = [][] string {{"5","3",".",".","7",".",".",".","."},
{"6",".",".","1","9","5",".",".","."},
{".","9","8",".",".",".",".","6","."},
{"8",".",".",".","6",".",".",".","3"},
{"4",".",".","8",".","3",".",".","1"},
{"7",".",".",".","2",".",".",".","6"},
{".","6",".",".",".",".","2","8","."},
{".",".",".","4","1","9",".",".","5"},
{".",".",".",".","8",".",".","7","9"}}
	mostrarQuadro (board)
	if checar (board) {
		fmt.Println ("Há solução!")
		mostrarQuadro (board)
	} else { // if checar board
		fmt.Println ("Não há solução!")
	} // else if checar board
}

