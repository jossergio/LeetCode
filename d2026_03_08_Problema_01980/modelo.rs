use std::collections::HashSet;
impl Solution {
    pub fn find_different_binary_string(nums: Vec<String>) -> String {
        let t = nums.len ();
        let conjunto: HashSet<String> = HashSet::from_iter (nums.into_iter ());
        for i in 0..2i32.pow (t as u32) { // Todas as possibilidades dentro da faixa
            let tmp = format! ("{:b}", i);
            let tmp = "0".repeat (t - tmp.len ()) + &tmp;
            if !conjunto.contains (&tmp) {
                return tmp;
            }
        }
        "".to_string () // Não chega aqui
    }
}
