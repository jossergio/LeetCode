impl Solution {
    pub fn largest_perimeter(nums: Vec<i32>) -> i32 {
        let eh_triangulo = | a, b, c | b + c > a;
        let mut nums = nums; // Torna mutável
        let t = nums.len ();
        nums.sort_by (| a, b | b.cmp (a));
        for i in 0..(t - 2) {
            let (a, b, c) = (nums [i], nums [i + 1], nums [i + 2]);
            if eh_triangulo (a, b, c) {
                return a + b + c;
            }
        }
        0 // Caso não exista
    }
}
