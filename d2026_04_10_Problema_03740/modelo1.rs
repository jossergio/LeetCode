use std::collections::HashSet;
impl Solution {
    pub fn minimum_distance(nums: Vec<i32>) -> i32 {
        let valores: HashSet<i32> = HashSet::from_iter (nums.clone ().into_iter ());
        let mut resposta = -1;
        for k in valores {
            let iguais_idxs: Vec<i32> = nums
                .iter ()
                .enumerate ()
                .filter_map (| (i, &v) |
                    if v == k { Some (i as i32) } else { None }
                )
                .collect ();
            if iguais_idxs.len () >= 3 {
                let tmp = iguais_idxs
                    .windows (3)
                    .map ( | a |
                        (a [1] - a [0]) +
                        (a [2] - a [1]) +
                        (a [2] - a [0]) // Não precisa de abs
                    )
                    .fold (i32::MAX, | acum, atual |
                        acum.min (atual)
                    );
                resposta = if resposta == -1 { tmp } else { resposta.min (tmp)};
            }
        }
        resposta
    }
}
