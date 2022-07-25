func searchRange(nums []int, target int) []int {
    
    var i, j int = 0, len (nums) - 1
    resposta := [] int {-1, -1}
    
    for i <= j && (resposta [0] == -1 || resposta [1] == -1) {
        
        if resposta [0] == -1  {
            if nums [i] == target { // Desmembrar da condição anterior, por conta do incremento
                resposta [0] = i
            } else {
                i++
            }
        }
        
        if resposta [1] == -1 {
            if nums [j] == target {
                resposta [1] = j
            } else {
                j--
            }
        }
    }
    
    return resposta
}

