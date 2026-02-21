impl Solution {
    pub fn count_prime_set_bits(left: i32, right: i32) -> i32 {
        let mut primos = vec![true; 33]; // 0..=32
        primos [0] = false;
        primos [1] = false;
        for i in 2..=32 {
            for j in ((2 * i)..=32).step_by (i) {
                primos [j] = false; // Erastóstenes
            }
        }
        let mut cont = 0;
        for i in left..=right {
            if primos [i.count_ones () as usize] {
                cont += 1;
            }
        }
        cont
    }
}
