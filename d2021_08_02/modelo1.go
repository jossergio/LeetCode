unc twoSum(nums []int, target int) []int {
    var a, b int
    tamanho := len (nums)
    encontrado := false
    retorno := [] int {0, 0}
    for a = 0; a < tamanho && !encontrado; a++ {
        for b = a + 1; b < tamanho && !encontrado; b++ {
            encontrado = (nums [a] + nums [b]) == target
        } // for b
    } // for a
    retorno [0], retorno [1] = a - 1, b - 1
    return retorno
}

