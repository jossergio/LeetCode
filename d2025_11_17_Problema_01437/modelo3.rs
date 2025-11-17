impl Solution {
    pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool {
        let uns = nums
        .into_iter ()
        .enumerate ()
        .filter_map (| v | if v.1 == 1 { Some (v.0) } else { None }
        ).collect::<Vec<_>> ();
        uns.len () == 1 ||
            (1..uns.len ())
            .into_iter ()
            .all (| i | uns [i] - uns [i - 1] - 1 >= k as usize) // Tem que contar somente os espaços
    }
}
