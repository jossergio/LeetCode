use std::collections::HashMap;
impl Solution {
    pub fn max_difference(s: String) -> i32 {
        let mut cont: HashMap<char, i32> = HashMap::new ();
        for c in s.chars () {
            cont.entry (c).and_modify (|v| *v += 1).or_insert (1);
        }
        let max_imp = *cont.values ().filter (|v| *v % 2 == 1).max ().unwrap_or (&0);
        cont.values ().filter (|v| *v % 2 == 0).map (|a| max_imp - *a).max ().unwrap_or (0)
    }
}
