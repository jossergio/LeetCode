package main

import (
	"fmt"
)

func romanToInt(s string) int {
	valores := make (map [byte] int)
	valores ['I'] = 1
	valores ['V'] = 5
	valores ['X'] = 10
	valores ['L'] = 50
	valores ['C'] = 100
	valores ['D'] = 500
	valores ['M'] = 1000
	tmp := valores [s [0]]
	acumulado := 0
	for a := 1; a < len (s); a++ {
		if tmp < valores [s [a]] {
			if tmp == 0 {
				tmp = valores [s [a]]
			} else { // if tmp == 0
				acumulado += valores [s [a]] - tmp
				tmp = 0
			} // else if tmp == 0
		} else { // if tmp < valores
			acumulado += tmp
			tmp = valores [s [a]]
		} // else if tmp < valores
	} // for a
	acumulado += tmp
	return acumulado
}

func mostrar (romano string) {
	fmt.Println (romano, " ==> ", romanToInt (romano))
} // mostrar

func main() {
	mostrar ("MMMCM")
	mostrar ("MIX")
	mostrar ("IX")
	mostrar ("XL")
	mostrar ("XCIX")
	mostrar ("XC")
	mostrar ("CMXCIX")
	mostrar ("MMMCMXCIX")
	mostrar ("CIX")
	mostrar ("XXXIII")
	mostrar ("XXX")
	mostrar ("III")
}

