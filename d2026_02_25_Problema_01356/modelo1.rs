impl Solution {
    pub fn sort_by_bits(arr: Vec<i32>) -> Vec<i32> {
        let num_bits = | mut n: i32 | {
            let mut cont = 0;
            while n > 0 {
                cont += n & 1;
                n >>= 1;
            }
            cont
        };
        let ordem = | a, b | {
            let b_a = num_bits (a);
            let b_b = num_bits (b);
            if b_a == b_b {
                return a.cmp (&b);
            }
            b_a.cmp (&b_b)
        };
        let mut arr = arr; // Torna mutável
        arr.sort_by (| &a, &b | ordem (a, b));
        arr
    }
}
