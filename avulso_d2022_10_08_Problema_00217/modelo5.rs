use std::collections::HashMap;
impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut mapa: HashMap<i32, u32> = HashMap::new ();
        for n in nums {
            if mapa.contains_key (&n) {
                return true;
            }
            // else
            mapa.insert (n, 1); // Basta ter a entrada
        }
        false
    }
}
