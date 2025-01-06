impl Solution {
    pub fn min_operations(boxes: String) -> Vec<i32> {
        let mut lista = std::collections::HashSet::new ();
        let b = boxes.as_bytes ();
        for (i, c) in b.iter ().enumerate () {
            if *c == b'1' { lista.insert (i as i32); }
        }
        let mut resposta: Vec<i32> = vec![0; boxes.len ()];
        for (i, c) in b.iter ().enumerate () {
            for p in &lista {
                resposta [i] += i32::abs ((i as i32) - p); // Não precisa testar o próprio; é zero esse valor
            }
        }
        resposta
    }
}
