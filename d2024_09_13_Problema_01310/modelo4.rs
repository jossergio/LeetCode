impl Solution {
    pub fn xor_queries(arr: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut resposta: Vec<i32> = Vec::new ();
        let queries = Vec::from_iter (
            queries.iter ().map (
                |q| Vec::from_iter (q.iter ().map (|&v| v as usize)))); // Para sombrear e mudar o tipo
        for q in queries {
            resposta.push (arr [(q [0] + 1)..(q [1] + 1)].iter ().fold (arr [q [0]], |acum, v| acum ^ v));
        }
        resposta
    }
}

