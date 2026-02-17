impl Solution {
    pub fn reverse_bits(n: i32) -> i32 {
        (0..32)
            .fold (Vec::<i32>::new (), 
                | mut acum, atual | {
                if n & (1 << atual) != 0 {
                    acum.push (1)
                } else {
                    acum.push (0)
                }
                acum
            })
            .into_iter ()
                .fold (0, | mut acum, atual | {
                    acum <<= 1;
                    acum+= atual;
                    acum
                })
    }
}
