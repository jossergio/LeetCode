func search(nums []int, target int) int {
    var i, j int = 0, len (nums) - 1
    for i <= j {
        
        m := (i + j) / 2
        
        if nums [m] == target {
            return m
        }
        
        if target > nums [m] {
            i = m + 1
        } else {
            j = m - 1
        }
    }
    
    return -1 // Não encontrou
}

