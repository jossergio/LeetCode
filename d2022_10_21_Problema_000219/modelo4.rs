use std::collections::HashMap;
impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let mut visto: HashMap<i32, usize> = HashMap::new ();
        let k = k as usize; // Sombreia e altera o tipo
        for (i, v) in nums.into_iter ().enumerate () {
            match visto.get (&v) {
                Some (a) => if i - a <= k { return true },
                None => ()
            }
            visto.insert (v, i); // Se existir, atualiza
        }
        false // Não achou
    }
}
