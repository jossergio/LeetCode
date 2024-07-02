func menor (a int, b int) int {
    if a < b {
        return a
    }
    // else
    return b
}

func intersect(nums1 []int, nums2 []int) []int {
    a1 := make (map[int]int)
    for _, v := range nums1 {
        if _, existe := a1 [v]; existe {
            a1 [v] += 1
        } else {
            a1 [v] = 1
        }
    }
    a2 := make (map[int]int)
    for _, v := range nums2 {
        if _, existe := a2 [v]; existe {
            a2 [v] += 1
        } else {
            a2 [v] = 1
        }
    }
    var resposta []int
    for i, v1 := range a1 {
        if v2, existe := a2 [i]; existe {
            minimo := menor (v1, v2)
            for minimo > 0 {
                minimo -= 1
                resposta = append (resposta, i)
            }
        }
    }
    return resposta
}

