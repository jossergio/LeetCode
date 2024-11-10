impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let mut p = (m + n - 1) as usize;
        let mut m = m - 1; // Sombrear para tornar mutável; 0-begin
        let mut n = n - 1; // Idem
        while m >= 0 || n >= 0 { // Poderia ser p >= 0, mas ele é usize e não fica -1
            if m >= 0 && n >= 0 {
                if nums1 [m as usize] > nums2 [n as usize] {
                    nums1 [p] = nums1 [m as usize];
                    m -= 1;
                } else {
                    nums1 [p] = nums2 [n as usize];
                    n -= 1;
                }
            } else {
                if n < 0 {
                    break; // O que sobrou é de nums1 e não precisamos mexer
                } else {
                    nums1 [p] = nums2 [n as usize];
                    n -= 1;
                }
            }
            p -= 1;
        }
        // A resposta é no próprio nums1
    }
}

