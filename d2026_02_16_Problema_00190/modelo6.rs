impl Solution {
    pub fn reverse_bits(n: i32) -> i32 {
        (0..32)
            .fold (0, | mut acum, atual | {
                acum <<= 1;
                acum += (n >> atual) & 1;
                acum
    })
    }
}
