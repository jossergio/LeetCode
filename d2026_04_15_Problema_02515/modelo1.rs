impl Solution {
    pub fn closest_target(words: Vec<String>, target: String, start_index: i32) -> i32 {
        let inicio = start_index as usize;
        if words [start_index as usize] == target {
            return 0; // Sumariamente
        }
        let t = words.len ();
        let adic = | a | (a + 1) % t;
        let subt = | a | (a - 1 + t) % t; 
        let mut atual_dir = adic (inicio);
        let mut atual_esq = subt (inicio);
        let mut cont: i32 = 1;
        while atual_dir != inicio
        && words [atual_dir] != target
        && words [atual_esq] != target {
            atual_dir = adic (atual_dir);
            atual_esq = subt (atual_esq);
            cont += 1;
        }
        if atual_dir == inicio { -1 } else { cont }
    }
}
