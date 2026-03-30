impl Solution {
    pub fn check_strings(s1: String, s2: String) -> bool {
        s1
            .bytes ()
            .enumerate ()
            .fold (vec! [0; 52],
                | mut acum, (i, c) | {
                    acum [26 * (i % 2) + (c - b'a') as usize] += 1;
                    acum
                }
            )
        == s2
            .bytes ()
            .enumerate ()
            .fold (vec! [0; 52],
                | mut acum, (i, c) | {
                    acum [26 * (i % 2) + (c - b'a') as usize] += 1;
                    acum
                }
            )
    }
}
