impl Solution {
    pub fn first_complete_index(arr: Vec<i32>, mat: Vec<Vec<i32>>) -> i32 {
        let mut pos = std::collections::HashMap::new ();
        for m in 0..mat.len () {
            for n in 0..mat [0].len () {
                pos.insert (mat [m][n] as usize, (m, n));
            }
        }
        let (tm, tn) = (mat.len (), mat [0].len ());
        let mut linhas = vec![mat [0].len () as i32; mat.len ()];
        let mut cols = vec![mat.len () as i32; mat [0].len ()];
        for (i, a) in arr.into_iter ().enumerate () {
            let (m, n) = pos [&(a as usize)];
            linhas [m] -=1;
            cols [n] -= 1;
            if linhas [m] == 0 || cols [n] == 0 {
                return i as i32;
            }
        }
        return 0; // Não chega aqui
    }
}
