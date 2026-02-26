
use std::cmp::Ordering;
impl Solution {
    fn num_bits (mut n: i32) -> i32 {
        let mut cont = 0;
        while n > 0 {
            cont += n & 1;
            n >>= 1;
        }
        cont
    }
    fn ordem (a: i32, b: i32) -> Ordering {
        let b_a = Self::num_bits (a);
        let b_b = Self::num_bits (b);
        if b_a == b_b {
            return a.cmp (&b);
        }
        // else
        b_a.cmp (&b_b)
    }
    pub fn sort_by_bits(arr: Vec<i32>) -> Vec<i32> {
        let mut arr = arr; // Torna mutável
        arr.sort_by (| &a, &b | Self::ordem (a, b));
        arr
    }
}
