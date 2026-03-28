impl Solution {
    pub fn are_similar(mat: Vec<Vec<i32>>, k: i32) -> bool {
        let k = (k as usize) % mat [0].len (); // Muda o tipo; ajusta o tamanho
        for (i, m) in mat.iter ().enumerate () {
            let mut tmp = m.clone ();
            if i % 2 == 0 {
                tmp.rotate_left (k);
            } else {
                tmp.rotate_right (k);
            }
            if *m != tmp {
                return false;
            }
        }
        true // Passou
    }
}
