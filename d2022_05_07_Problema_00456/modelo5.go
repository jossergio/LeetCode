func find132pattern(nums []int) bool {
    
    min := nums [0] // Sempre haverá
    
    for j := 1; j < len (nums) - 1; j++ {
        if min < nums [j] {
            max := nums [j]
            for k := j + 1; k < len (nums); k++ {
                if nums [k] < max {
                    if nums [k] > min {
                        return true
                    }
                } else {
                    max = nums [k]
                }
            }
        } else {
            min = nums [j]
        }
    }
    
    return false
}

