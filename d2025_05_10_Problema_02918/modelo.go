func minSum(nums1 []int, nums2 []int) int64 {
    var s1 int64 = 0
    var s2 int64 = 0
    var z1 int64 = 0 // Para montar o resultado nesse tipo
    var z2 int64 = 0
    for _, n := range nums1 {
        if n == 0 {
            z1 += 1
        } else {
            s1 += int64 (n)
        }
    }
    for _, n := range nums2 {
        if n == 0 {
            z2 += 1
        } else {
            s2 += int64 (n)
        }
    }
    if (z1 == 0 && z2 + s2 > s1) || (z2 == 0 && z1 + s1 > s2) {
        return -1
    }
    s1 += z1
    s2 += z2
    return max (s1, s2)
}
