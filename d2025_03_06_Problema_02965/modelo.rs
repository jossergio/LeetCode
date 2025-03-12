use std::collections::HashSet;
impl Solution {
    pub fn find_missing_and_repeated_values(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let n = grid.len () as i32; // Uma das dimensões
        let mut todos: HashSet<i32> = HashSet::from_iter (1..=(n * n));
        let mut vistos: HashSet<i32> = HashSet::new ();
        let mut duplo: i32 = 0; // Só para haver um valor aqui
        for v in grid.into_iter ().flatten () {
            if !vistos.insert (v) { // Insere, mas verifica se não havia
                duplo = v;
            }
            todos.remove (&v);
        }
        let faltante = {
            let mut tmp: i32 = 0; // Só para haver um valor aqui
            for f in todos.into_iter () {
                tmp = f; // Só conterá um
            }
            tmp
        };
        vec![duplo, faltante]
    }
}
