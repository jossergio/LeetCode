impl Solution {
    pub fn reverse_bits(n: i32) -> i32 {
        (0..32)
            .fold (vec![0; 32], 
                | mut acum, atual | {
                acum [atual] = (n >> atual) & 1;
                acum
            })
            .iter ()
                .fold (0, | mut acum, atual | {
                    acum <<= 1;
                    acum+= atual;
                    acum
                })
    }
}
