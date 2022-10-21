func containsNearbyDuplicate(nums []int, k int) bool {
    mapaValores := make (map [int] int)
    for i := 0; i < len (nums); i++ {
        if j, existe := mapaValores [nums [i]]; existe && i - j <= k { // i sempre será maior;
            return true
        }
        mapaValores [nums [i]] = i
    }
    return false // Por omissão; se chegou até aqui, não encontrou
}

