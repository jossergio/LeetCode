func passar (ant *int, atual *int, valor int, proximo *int) {
    *ant = *atual
    *atual = valor
    *proximo += 1
}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    i1, i2 := 0, 0
    limite := (len (nums1) + len (nums2)) / 2
    var ant, atual int = 0, 0 // Só para constar
    var i int = 0
    for i <= limite { // 0-based; o último tem que entrar
        if i1 < len (nums1) && i2 < len (nums2) {
            if nums1 [i1] <= nums2 [i2] {
                passar (&ant, &atual, nums1 [i1], &i1)
            } else {
                passar (&ant, &atual, nums2 [i2], &i2)
            }
        } else {
            fmt.Println (i1, i2)
            if i1 < len (nums1) {
                passar (&ant, &atual, nums1 [i1], &i1)
            } else {
                passar (&ant, &atual, nums2 [i2], &i2)
            }
        }
        i += 1
    }
    if (len (nums1) + len (nums2)) % 2 == 0 {
        return float64 (ant + atual) / 2
    }
    // else
    return float64 (atual)
}

