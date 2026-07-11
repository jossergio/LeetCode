impl Solution {
    pub fn count_complete_components(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let n = n as usize; // Muda o tipo
        let mut grafo = vec![vec![false; n]; n];
        for a in edges {
            let (i, j) = (a [0] as usize, a [1] as usize);
            grafo [i][j] = true;
            grafo [j][i] = true;
        }
        fn buscar (grupos: &mut Vec<i32>, i: usize, grafo: &Vec<Vec<bool>>, grupo: i32) -> (i32, i32) {
            let (mut c, mut q) = (0, 0);
            if grupos [i] == -1 {
                c += 1; // Já conta esse nó
                grupos [i] = grupo; // Já inclui nesse grupo
                for k in 0..grafo.len () {
                    if grafo [i][k] {
                        q += 1; // Há uma aresta aqui
                        let (tmp_c, tmp_q) = buscar (grupos, k, grafo, grupo);
                        c += tmp_c;
                        q += tmp_q;
                    }
                }
            }
            (c, q)
        }
        let mut grupo = 0;
        let mut grupos = vec![-1; n];
        let mut cont = 0;
        for i in 0..n {
            if grupos [i] == -1 {
                let (c, q) = buscar (&mut grupos, i, &grafo, grupo);
                if (q / 2) == (c * (c - 1)) / 2 {// A quantidade de arestas vem em dobro (não direcional)
                    cont += 1;
                }
                grupo += 1;
            }
        }
        cont
    }
}
