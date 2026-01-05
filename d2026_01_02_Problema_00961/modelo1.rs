use std::collections::HashMap;
impl Solution {
    pub fn repeated_n_times(nums: Vec<i32>) -> i32 {
        let n = nums.len () / 2;
        let mut tabela: HashMap<i32, usize> = HashMap::new ();
        for v in nums {
            if *tabela
            .entry (v)
            .and_modify (| c | *c += 1)
            .or_insert (1) == n {
                return v;
            }
        }
        0 // Não chega aqui
    }
}
