impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let mut nums = nums.clone (); // Torna mutável
        nums.push (nums [0]); // Fecha o ciclo
        let t = nums.len ();
        let mut continuidade: bool = true; // Pressupõe
        for i in 1..t {
            if nums [i] < nums [i - 1] {
                if !continuidade { // Houve uma descontinuidade anterior
                    return false;
                } else {
                    continuidade = false; // Primeira descontinuidade
                }
            }
        }
        true // Passou
    }
}
