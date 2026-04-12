use std::collections::HashMap;
impl Solution {
    pub fn minimum_distance(nums: Vec<i32>) -> i32 {
        let mut tabela: HashMap<i32, Vec<usize>> = HashMap::new ();
        let mut resposta = usize::MAX;;
        for (a, v) in nums.into_iter ().enumerate () {
            let mut tmp = tabela
                .entry (v)
                .or_insert (Vec::new ());
            tmp.push (a);
            let t = tmp.len ();
            if t > 2 {
                resposta = resposta.min (2 * (a - tmp [t - 3])); // Lógica
            }
        }
        resposta as i32
    }
}
