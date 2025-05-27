impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        (1..=n).map (|a| if a % m == 0 { -a } else { a }).sum ()
    }
}
