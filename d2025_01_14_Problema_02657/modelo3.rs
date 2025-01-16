impl Solution {
    pub fn find_the_prefix_common_array(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
        let mut c1 = std::collections::HashMap::new ();
        let mut c2 = std::collections::HashMap::new ();
        let mut contar: i32 = 0;
        let mut resposta = vec![0i32; a.len ()]; // Os tamanhos são iguais
        for (i, z) in std::iter::zip (a.into_iter (), b.into_iter ()).enumerate () {
            let (a, b) = z;
            let mut av = c1.entry (a).or_insert (0);
            *av += 1;
            let mut bv = c2.entry (b).or_insert (0);
            *bv += 1;
            if a == b {
                contar += 1;
            } else {
                if c1.get (&a) == c2.get (&a) {
                    contar += 1;
                }
                if c1.get (&b) == c2.get (&b) {
                    contar += 1;
                }
            }
            resposta [i] = contar;
        }
        resposta
    }
}
