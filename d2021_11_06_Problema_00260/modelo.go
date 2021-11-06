func singleNumber(nums []int) []int {
    valores := make (map [int] int)
    for _, valor := range (nums) {
        _, ok := valores [valor]
        if ok {
            delete (valores, valor) // Só há, no máximo, dois. Então, retira o que já tinha para diminuir
        } else { // if ok
            valores [valor] = 1
        } // else if ok
    } // for range nums
    var retorno [] int
    for indice, _ := range (valores) { // Só haverá dois
        retorno = append (retorno, indice)
    } // for indice = range valores
    return retorno
}

