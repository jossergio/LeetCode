impl Solution {
    pub fn largest_perimeter(nums: Vec<i32>) -> i32 {
        let eh_triangulo = | a, b, c | b + c > a;
        let mut nums = nums; // Torna mutável
        let t = nums.len ();
        nums.sort_by (| a, b | b.cmp (a));
        for i in 0..t {
            for j in (i + 1)..t {
                for k in (j + 1)..t {
                    if eh_triangulo (nums [i], nums [j], nums [k]) {
                        return nums [i] + nums [j] + nums [k]; // Encontrou
                    } else {
                        break; // Não é com os menires que irá formar
                    }
                }
            }
        }
        0 // Caso não exista
    }
}
