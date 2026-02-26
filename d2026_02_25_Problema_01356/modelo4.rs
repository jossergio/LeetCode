use std::collections::HashMap;
impl Solution {
    pub fn sort_by_bits(arr: Vec<i32>) -> Vec<i32> {
        let mut mapa: HashMap<u32, Vec<i32>> = HashMap::new (); // count_ones é u32
        for v in arr {
            let tmp = v.count_ones ();
            mapa.entry (tmp).and_modify (| lista | lista.push (v)).or_insert (vec![v]);
        }
        let mut resposta: Vec<i32> = Vec::new ();
        for i in 0..32 {
            match mapa.get_mut (&i) {
                None => (),
                Some (lista) => {
                    lista.sort ();
                    resposta.extend (lista.clone ());
                }
            }
        }
        resposta
    }
}
