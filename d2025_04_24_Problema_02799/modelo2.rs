use std::collections::HashSet;
impl Solution {
    pub fn count_complete_subarrays(nums: Vec<i32>) -> i32 {
        let distintos = HashSet::<i32>::from_iter (nums.clone ().into_iter ()).len ();
        let t = nums.len ();
        let mut resposta = 0; // i32
        for i in 0..t {
            let mut tmp: HashSet<i32> = HashSet:: new ();
            for j in i..t {
                tmp.insert (nums [j]);
                if tmp.len () == distintos { resposta += 1; }
            }
        }
        resposta
    }
}
