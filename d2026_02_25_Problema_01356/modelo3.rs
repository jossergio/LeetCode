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
            match mapa.get (&i) {
                None => (),
                Some (lista) => {
                    let mut lista = lista.clone ();;
                    lista.sort ();
                    resposta.extend (lista);
                }
            }
        }
        resposta
    }
}
