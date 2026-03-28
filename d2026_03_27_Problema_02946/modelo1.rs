impl Solution {
    pub fn are_similar(mat: Vec<Vec<i32>>, k: i32) -> bool {
        let mut k = k as usize; // Muda o tipo
        let t = mat [0].len (); // Largura
        let mut nova_mat: Vec<Vec<i32>> = Vec::new ();
        for (i, m) in mat.iter ().enumerate () {
            let mut tmp = vec![0; t];
            for j in 0..t {
                if i % 2 == 0 {
                    tmp [j] = m [(j + k) % t];
                } else {
                    tmp [(j + k) % t] = m [j];
                }
            }
            nova_mat.push (tmp);
        }
        println! ("{nova_mat:?}");
        nova_mat == mat
    }
}
