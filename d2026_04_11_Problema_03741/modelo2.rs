use std::collections::{HashMap, VecDeque};
impl Solution {
    pub fn minimum_distance(nums: Vec<i32>) -> i32 {
        let mut tabela: HashMap<i32, VecDeque<usize>> = HashMap::new ();
        let mut resposta = usize::MAX;;
        for (a, v) in nums.into_iter ().enumerate () {
            let mut tmp = tabela
                .entry (v)
                .or_insert (VecDeque::new ());
            tmp.push_back (a);
            if tmp.len () == 3 {
                let (i, j, k) = (tmp [0], tmp [1], tmp [2]);
                resposta = resposta.min ((j - i) + (k - j) + (k - i)); // Não precisa de abs
                tmp.pop_front ();
            }
        }
        resposta as i32
    }
}
