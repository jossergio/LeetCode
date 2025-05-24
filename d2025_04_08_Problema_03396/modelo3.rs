use std::collections::HashSet;
impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        let mut vistos: HashSet<i32> = HashSet::new ();
        let mut nums = nums; // Só para tornar mutável
        nums.reverse (); // preciso nessa ordem
        for (i, v) in nums.iter ().enumerate () {
            if vistos.contains (v) {
                return (nums.len () as i32 - i as i32 + 2) / 3; // +2 = um por 0-begin e outro pois é a partir do próximo
            }
            // else
            vistos.insert (*v);
        }
        0 // Não há
    }
}
