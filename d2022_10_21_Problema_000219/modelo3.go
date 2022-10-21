func containsNearbyDuplicate(nums []int, k int) bool {
    for i, num1 := range nums {
        for j := i + 1; j - i <= k && j < len (nums); j++ {
            if num1 == nums [j] {
                return true
            }
        }
    }
    return false // Por omissão; se chegou aqui, não encontrou
}

