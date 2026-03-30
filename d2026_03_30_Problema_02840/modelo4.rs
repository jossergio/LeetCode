impl Solution {
    pub fn check_strings(s1: String, s2: String) -> bool {
        s1
            .bytes ()
            .zip (s2.bytes ())
            .enumerate ()
            .fold (vec! [vec! [0; 26]; 2],
                | mut acum, (i, (a, b)) | {
                    acum [i % 2][(a - b'a') as usize] += 1;
                    acum [i % 2][(b - b'a') as usize] -= 1;
                    acum
                }
            )
            .iter ()
            .flatten ()
            .all (| &a | a == 0)
    }
}
