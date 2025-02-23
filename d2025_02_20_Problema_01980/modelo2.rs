use std::collections::HashSet;
impl Solution {
    pub fn find_different_binary_string(nums: Vec<String>) -> String {
        let t = nums.len (); // O tamanho de cada string é o mesmo do próprio vetor
        let mut tmp: HashSet<String> = HashSet::new ();
        fn gerar (t: usize, n: usize, tmp: &mut HashSet<String>, acum: String) {
            if n < t {
                gerar (t, n + 1, tmp, acum.clone () + "0");
                gerar (t, n + 1, tmp, acum.clone () + "1");
            } else {
                tmp.insert (acum);
            }
        }
        gerar (t, 0, &mut tmp, String::new ());
        tmp.difference (&HashSet::from_iter (nums.into_iter ())).into_iter ().collect::<Vec<&String>> () [0].to_string () // Retorna o primeiro
    }
}
