use std::collections::HashSet;
impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut mapa: HashSet<i32> = HashSet::new ();
        for n in nums {
            if mapa.contains (&n) {
                return true;
            }
            // else
            mapa.insert (n); // Basta ter a entrada
        }
        false
    }
}
