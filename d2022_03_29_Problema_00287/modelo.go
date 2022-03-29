func findDuplicate(nums []int) int {
    
    indices := make ([] bool, len (nums)) // GoLang inicia false
    
    for _, v := range nums {
        if indices [v] {
            return v
        }
        indices [v] = true
    }
    
    return 0 // Não chega aqui
}

