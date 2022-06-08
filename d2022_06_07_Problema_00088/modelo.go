func merge(nums1 []int, m int, nums2 []int, n int)  {
    m-- // m - 1 é o último elemento
    n--
    for m >= 0 {
        if n >= 0 {
            if nums2 [n] > nums1 [m] {
                nums1 [m + n + 1] = nums2 [n]
                n--
            } else {
                nums1 [m + n + 1] = nums1 [m]
                m--
            }
        } else {
                break // Não precisa mais mexer em nums1
        }
    }
    
    for n >= 0 { // Observar que vai descarregar nums2 em nums1
        nums1 [n] = nums2 [n] // mesmo índice, listas diferentes
        n--
    }
}

