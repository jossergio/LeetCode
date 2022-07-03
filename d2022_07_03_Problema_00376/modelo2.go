func maior (a int, b int) int {
    if a > b {
        return a
    }
    // else
    return b
}


func wiggleMaxLength(nums []int) int {
    
    if (len (nums) < 2) {
        return len (nums)
    }
    
    paraCima := make ([] int, len (nums))
    paraBaixo := make ([] int, len (nums))
    
    for i := 1; i < len (nums); i++ {
        for j := 0; j < i; j++ {
            if nums [i] > nums [j] {
                paraCima [i] = maior (paraCima [i], paraBaixo [j] + 1)
            } else {
                if nums [i] < nums [j] {
                    paraBaixo [i] = maior (paraBaixo [i], paraCima [j] + 1)
                }
            }
        }
    }
    
    return 1 + maior (paraBaixo [len (nums) - 1], paraCima [len (nums) - 1])
}

