func removeElement(nums []int, val int) int {
    
    var k int = len (nums) - 1 // Índice do último
    var i int = 0
    
    for i <= k {
        if nums [i] == val {
            nums [i] = nums [k] // Mesmo para i == k
            k--
        } else {
            i++
        }
    }
    
    return k + 1 // Reajusta, para refletir tamanho e não o índice do ultimo
    // k Pode terminar negativo, também
}

