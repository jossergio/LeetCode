impl Solution {
    pub fn sort_matrix(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut grid = grid; // Para tornar mutável
        let t = grid.len (); // Dimensões iguais
        for i in 0..t {
            let mut tmp: Vec<i32> = Vec::new ();
            let mut k = i;
            for j in 0..t {
                tmp.push (grid [k][j]);
                k += 1;
                if k == t { break; }
            }
            tmp.sort_by (|a, b| { a.cmp (b) });
            k = i; // Recomeça, para montar
            for j in 0..t {
                grid [k][j] = tmp.pop ().unwrap ();
                k += 1;
                if k == t { break; }
            }
        }
        for j in 1..t {
            let mut tmp: Vec<i32> = Vec::new ();
            let mut k = j;
            for i in 0..t {
                tmp.push (grid [i][k]);
                k += 1;
                if k == t { break; }
            }
            tmp.sort_by (|a, b| b.cmp (a));
            k = j;
            for i in 0..t {
                grid [i][k] = tmp.pop ().unwrap ();
                k += 1;
                if k == t { break; }
            }
        }
        grid
    }
}
