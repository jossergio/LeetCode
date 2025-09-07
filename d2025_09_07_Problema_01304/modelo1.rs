impl Solution {
    pub fn sum_zero(n: i32) -> Vec<i32> {
        let m = n / 2;
        let impar = (n % 2) == 1;
        ((m * (-1))..=m).filter_map (
            | v | if v != 0 || impar { Some (v)}
            else { None }
        ).collect::<Vec<i32>> ()
    }
}
