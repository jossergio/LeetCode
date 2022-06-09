func twoSum(numbers []int, target int) []int {
    
    var i, j int = 0, len (numbers) - 1
    
    for i < j {
        if (numbers [i] + numbers [j]) == target {
            return [] int {i + 1, j + 1}
            // O problema é i-begin (indexed)
        }
        // else
        if (numbers [i] + numbers [j]) > target {
            j--
        } else {
            i++
        }
    }
    
    return [] int {} // Só para ter retorno no final
}

