impl Solution {
    pub fn minimum_length(s: String) -> i32 {
        let mut contador = std::collections::HashMap::new ();
        for c in s.as_bytes () {
            let q = contador.entry (c).or_insert (0 as i32);
            *q += 1;
        }
        contador.values ().map (|&q| if q %2 == 0 { 2 } else { 1 }).sum ()
    }
}
