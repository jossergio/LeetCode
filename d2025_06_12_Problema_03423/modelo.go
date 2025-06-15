func maxAdjacentDistance(nums []int) int {
    abs := func (a int) int {
        if a < 0 {
            return -a
        }
        // else
        return a
    }
    nums = append (nums, nums [0])
    resposta := 0 // int
    for i := 1; i < len (nums); i += 1 {
        resposta = max (resposta, abs (nums [i] - nums [i - 1]))
    }
    return resposta
}
