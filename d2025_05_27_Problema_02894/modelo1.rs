impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        let mut r: i32 = 0; // Será a resposta
        for i in 1..=n {
            r += if i % m == 0 { -i } else { i };
        }
        r
    }
}
