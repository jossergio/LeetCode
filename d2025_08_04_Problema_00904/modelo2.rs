use std::collections::HashMap;
impl Solution {
    pub fn total_fruit(fruits: Vec<i32>) -> i32 {
        let mut i: usize = 0;
        let t = fruits.len ();
        let mut bases: HashMap<i32, usize> = HashMap::new ();
        let mut pontos: (i32, i32) = (0, 0);
        let mut maximo: i32 = 0;
        pontos.0 = fruits [i];
        bases.insert (pontos.0, i); // De toda forma, é o primeiro
        while i < t && fruits [i] == pontos.0 {
            maximo += 1;
            i += 1;
        }
        if i == t { return maximo; }
        // else
        pontos.1 = fruits [i];
        bases.insert (pontos.1, i); // Desse, també é o primeiro
        let mut resposta: i32 = 0;
        while i < t && fruits [i] == pontos.1 {
            maximo += 1;
            resposta = i32::max (resposta, maximo);
            i += 1;
            if i < t && fruits [i] != pontos.1 {
                if fruits [i] == pontos.0 {
                    bases.insert (pontos.0, i); // Na realidade, atualiza
                } else {
                    maximo = (i - bases [&pontos.1]) as i32;
                    bases.insert (fruits [i], i);
                }
                pontos.0 = pontos.1;
                pontos.1 = fruits [i];
            }
        }
        resposta
    }
}
