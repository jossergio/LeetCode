func searchRange(nums []int, target int) []int {
    var i, j int = 0, len (nums) - 1
    for i <= j {
        meio := (i + j) / 2
        if nums [meio] == target {
            i = meio
            j = meio
            for i >= 0 && nums [i] == target {
                i -= 1
            }
            for j < len (nums) && nums [j] == target {
                j += 1
            }
            return [] int {i + 1, j - 1}
        }
        // else
        if nums [meio] < target {
            i = meio + 1
        } else { // Só pode ser maior
            j = meio - 1
        }
    }
    return [] int {-1, -1} // Por omissão
}

