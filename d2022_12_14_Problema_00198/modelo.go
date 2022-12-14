func max (a int, b int) int {
    if a > b {
        return a
    }
    // else
    return b
}
func auxiliar (nums [] int, acumulado int, i int, memo [] int) int {
    if i >= len (nums) {
        return acumulado
    }
    // else
    if memo [i] == -1 {
        memo [i] = max (auxiliar (nums, nums [i], i + 2, memo), auxiliar (nums, nums [i], i + 3, memo))
    }
    return acumulado + memo [i]
}
func rob(nums []int) int {
    memo := make ([] int, len (nums))
    for i := 0; i < len (nums); i +=1 {
        memo [i] = -1 // nums sempre é positivo; valor para indicar que ainda não possui resposta
    }
    return max (auxiliar (nums, 0, 0, memo), auxiliar (nums, 0, 1, memo))
}

