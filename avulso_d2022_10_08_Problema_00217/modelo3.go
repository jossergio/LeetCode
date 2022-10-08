func containsDuplicate(nums []int) bool {
    mapa := make (map [int] int)
    for _, v := range (nums) {
        if _, existe := mapa [v]; existe {
            return true
        }
        // else
        mapa [v] = 1
    }
    return false // Por omissão
}

