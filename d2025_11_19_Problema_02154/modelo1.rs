impl Solution {
    pub fn find_final_value(nums: Vec<i32>, original: i32) -> i32 {
        let mut nums = nums; // Vou ordenar
        let mut original = original; // Torna mutável
        nums.sort ();
        let t = nums.len ();
        let mut i = 0usize;
        while i < t {
            if original == nums [i] {
                original *= 2;
            } else if original < nums [i] {
                break; // Sem chances a partir daqui
            }
            i += 1;
        }
        original
    }
}
