func find132pattern(nums []int) bool {
    
    m := nums [0] // Sempre haverá
    
    for j := 1; j < len (nums) - 1; j++ {
        if m < nums [j] {
            for k := j + 1; k < len (nums); k++ {
                if m < nums [k] && nums [k] < nums [j] {
                    return true
                }
            }
        } else {
            m = nums [j]
        }
    }
    
    return false
}

