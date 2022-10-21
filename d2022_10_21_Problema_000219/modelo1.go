func containsNearbyDuplicate(nums []int, k int) bool {
    for i := 0; i < len (nums); i++ {
        for j := i + 1; j < len (nums); j++ {
            if j - i <= k {
                if nums [i] == nums [j] {
                    return true
                }
            } else { // if j - i <= k
                break // Sai de imediato
            }
        }
    }
    return false // Por omissão; se chegou até aqui é por que não encontrou
}

