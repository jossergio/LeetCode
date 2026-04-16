use std::collections::HashMap;
impl Solution {
    fn buscar (indices: &Vec<usize>, indice: usize, t: usize) -> i32 {
        match indices.binary_search (&indice) {
            Ok (k) => {
                let mut resposta = usize::MAX;
                let indice1 = if k == 0 { indices.len () - 1 } else { k - 1 };
                let indice2 = if k == indices.len () - 1 { 0 } else { k + 1};
                let tmp = indice.abs_diff (indices [indice1]);
                resposta = resposta.min (tmp);
                resposta = resposta.min (t - tmp); // t - tmp:  o que sobra para a distância circular
                let tmp = indice.abs_diff (indices [indice2]);
                resposta = resposta.min (tmp);
                resposta = resposta.min (t - tmp); // Idem
                resposta as i32
            },
            Err (k) => 0 // Só para ter
        }
    }
    pub fn solve_queries(nums: Vec<i32>, queries: Vec<i32>) -> Vec<i32> {
        let mut mapa: HashMap<i32, Vec<usize>> = HashMap::new ();
        let t = nums.len ();
        for (i, &v) in nums.iter ().enumerate () {
            let tmp = mapa.entry (v).or_insert (Vec::new ());
            tmp.push (i);
        }
        for k in mapa.values_mut () {
            k.sort ();
        }
        let mut resposta = vec![0; queries.len ()];
        for (i, &q) in queries.iter ().enumerate () {
            let tmp = nums [q as usize];
            resposta [i] = match mapa.get (&tmp) {
                Some (v) => if v.len () == 1 { -1 } else { Self::buscar (&v, q as usize, t) },
                None => -1
            };
        }
        resposta
    }
}
