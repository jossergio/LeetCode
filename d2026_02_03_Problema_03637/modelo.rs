impl Solution {
    pub fn is_trionic(nums: Vec<i32>) -> bool {
        let mut i: usize = 1; // Começa do segundo
        let t = nums.len ();
        while i < t && nums [i - 1] < nums [i] {
            i += 1;
        }
        // i == 1 nem andou
        if i == 1 || i == t { return false; }
        let mut j = i;
        while i < t && nums [i - 1] > nums [i] {
            i += 1;
        }
        // i == j nem andou
        if i == j || i == t { return false; }
        j = i;
        while i < t && nums [i - 1] < nums [i] {
            i += 1;
        }
        i != j && i == t // Chegou ao final sem problemas
    }
}
