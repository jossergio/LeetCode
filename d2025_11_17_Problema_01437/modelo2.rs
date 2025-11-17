impl Solution {
    pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool {
        nums
            .into_iter ()
            .enumerate ()
            .filter_map (| v | if v.1 == 1 { Some (v.0) } else { None })
            .fold ((Option::<usize>::None, true), | (ant, passo), atual | {
                if let Some (i) = ant {
                    (Some (atual), passo && (atual - i - 1) >= k as usize)
                } else {
                    (Some (atual), true)
                }
            } ).1
    }
}
