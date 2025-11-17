impl Solution {
    pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool {
        let k = k as usize;
        nums
            .into_iter ()
            .enumerate ()
            .filter_map (| (i, v) | if v == 1 { Some (i) } else { None })
            .fold ((Option::<usize>::None, true), | (ant, passo), atual |
                (Some (atual), match ant {
                    Some (i) => passo && (atual - i - 1) >= k,
                    None => true
                })
            ).1
    }
}
