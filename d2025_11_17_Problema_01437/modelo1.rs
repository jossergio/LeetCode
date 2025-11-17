impl Solution {
    pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool {
        let k = k as usize;
        let mut ant: Option<usize> = None;
        for i in 0..nums.len () {
            if nums [i] == 1 {
                if let Some (j) = ant {
                    if i - j < k {
                        return false;
                    }
                }
                ant = Some (i + 1); // Já calcula; considera que o próximo é zero
            }
        }
        true
    }
}
