func twoSum(numbers []int, target int) []int {
    
    for i, v1 := range numbers {
        
        for j, v2 := range numbers [i+1:] {
            
            if (v1 + v2) == target {
                return [] int {i + 1, i + j + 2}
                // O vetor é i-begin (indexed)
                // +2 ==> j começa em zero, +1 de i +1 para j
            }
            // else
            if (v1 + v2) > target {
                break // Interno
            }
        }
    }
    
    return [] int {0, 0} // Só para ter essa linha
}

