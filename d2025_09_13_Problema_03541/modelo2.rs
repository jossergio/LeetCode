use std::collections::HashMap;
impl Solution {
    pub fn max_freq_sum(s: String) -> i32 {
        let mut cont: HashMap<char, i32> = HashMap::new ();
        for c in s.chars () {
            cont.entry (c).and_modify (| v | *v += 1).or_insert (1);
            // cont.insert (c, cont.get (&c).unwrap_or (&0) + 1);
        }
        let (mut vogal, mut consoante) = (0, 0); // i32
        for (l, q) in cont.into_iter () {
            if "aeiou".find (l) == None { // É consoante
                if q > consoante { consoante = q }
            } else { // É vogal
                if q > vogal { vogal = q }
            }
        }
        vogal + consoante
    }
}
