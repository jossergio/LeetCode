func findMin(nums []int) int {
    esq := 0
    dir := len (nums) - 1
    for esq < dir {
        meio := (esq + dir) / 2
        if nums [esq] == nums [dir] {
            dir -= 1
        } else if nums [dir] >= nums [meio] {
            dir = meio
        } else {
            esq = meio + 1
        }
    }
    return nums [esq]
}
