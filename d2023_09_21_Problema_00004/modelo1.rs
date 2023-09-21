impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let mut i1: usize = 0; // Início de cada valor
        let mut i2: usize = 0; // ^^^^
        let limite: usize = (nums1.len () + nums2.len ()) / 2;
        let mut ant: i32 = 0; // Só para ter algum valor
        let mut atual: i32 = 0; // ^^^^
        let mut i: usize = 0;
        while (i <= limite) { // 0-based permite isso sem adicionar 1
            if i1 < nums1.len () && i2 < nums2.len () {
                if nums1 [i1] <= nums2 [i2] {
                    ant = atual;
                    atual = nums1 [i1];
                    i1 += 1;
                } else {
                    ant = atual;
                    atual = nums2 [i2];
                    i2 += 1;
                }
            } else {
                if i1 < nums1.len () {
                    ant = atual;
                    atual = nums1 [i1];
                    i1 += 1;
                } else {
                    ant = atual;
                    atual = nums2 [i2];
                    i2 += 1;
                }
            }
            i += 1;
        }
        if (nums1.len () + nums2.len ()) % 2 == 0 {
            return (ant as f64 + atual as f64) / 2.0
        }
        // else
        return atual as f64
    }
}

