use std::collections::HashMap;
impl Solution {
    fn buscar (nums: &Vec<i32>, i: usize, t: &mut HashMap<i32, i32>, acum: i32) {
        if i < nums.len () {
            let tmp = acum | nums [i];
            t.entry (tmp).and_modify (|v| *v += 1).or_insert (1);
            for j in (i + 1)..nums.len () {
                Self::buscar (nums, j, t, tmp);
            }
        }
    }
    pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
        let mut tabela: HashMap<i32, i32> = HashMap::new ();
        for i in 0..nums.len () {
            Self::buscar (&nums, i, &mut tabela, 0); // 0 é o elemento neutro
        }
        let mut resposta = 0; // i32
        let mut ver = 0; // Com,parativo inicial; elemento neutro
        for (v, c) in tabela {
            if v > ver {
                resposta = c;
                ver = v;
            }
        }
        resposta
    }
}
