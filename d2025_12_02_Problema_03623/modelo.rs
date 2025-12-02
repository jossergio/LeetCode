use std::collections::HashMap;
impl Solution {
    pub fn count_trapezoids(points: Vec<Vec<i32>>) -> i32 {
        let modulo = 1_000_000_007; // Módulo padrão
        let mut eixos_x: HashMap<i32, i64> = HashMap::new ();
        for p in points {
            eixos_x.entry (p [1]).and_modify (| a | *a += 1).or_insert (1);
        }
        let linhas: Vec<i64> = eixos_x.into_iter ().filter_map (| (y, cont) | 
            if cont >= 2 { Some ((cont * (cont - 1)) / 2) } else { None }).collect ();
        let mut unicos: HashMap<i64, i64> = HashMap::new ();
        for v in linhas {
            unicos.entry (v).and_modify (| q | *q += 1).or_insert (1);
        }
        let mut linhas2: Vec<(i64, i64)> = unicos.into_iter ().collect ();
        let t = linhas2.len ();
        let mut resposta = 0i64;
        for i in 0..t {
            resposta = (resposta + (linhas2 [i].0 * linhas2 [i].0) * ((linhas2 [i].1 * (linhas2 [i].1 - 1)) / 2)) % modulo;
            for j in (i + 1)..t {
                resposta = (
                    resposta +
                    (linhas2 [i].1 * linhas2 [j].1) * (linhas2 [i].0 * linhas2 [j].0)
                    ) % modulo;
            }
        }
        resposta as i32
    }
}
