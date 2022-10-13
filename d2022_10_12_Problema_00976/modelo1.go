func triangulo (a, b, c int) bool {
    if b + c > a { // Sempre vem ordenado, com a sendo o maior
        return true
    }
    // else
    return false
}
func largestPerimeter(nums []int) int {
    maior := func (a, b int) int {
        if a > b {
            return a
        }
        // else
        return b
    }
    sort.Ints (nums)
    var resposta int // = 0
    for i := 0; i < len (nums) - 2; i++ {
        for j := i + 1; j < len (nums) - 1; j++ {
            for k := j + 1; k < len (nums); k++ {
                if triangulo (nums [k], nums [j], nums [i]) { // k-ésimo é o maior
                    resposta = maior (resposta, nums [k] + nums [j] + nums [i])
                } else {
                    break
                }
            }
            break // Incondicional, pois em k já não forma mais
        }
    }
    return resposta
}

