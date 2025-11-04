impl Solution {
    pub fn find_x_sum(nums: Vec<i32>, k: i32, x: i32) -> Vec<i32> {
        let t = nums.len ();
        let k = k as usize; // Muda o tipo
        let x = x as usize; // Idem
        let mut resposta = vec![0; t - k + 1];
        let mut contagens = std::collections::HashMap::<i32, i32>::new ();
        for i in 0..=(t - k) {
            for j in i..(i + k) {
                contagens.entry (nums [j]).and_modify (| v | *v += 1).or_insert (1);
            }
            let mut tmp: Vec<(i32, i32)> = Vec::new ();
            for (v, q) in contagens.iter () {
                tmp.push ((*q, *v));
            }
            tmp.sort_by (| a, b | if b.0 == a.0 { b.1.cmp (&a.1)} else { b.0.cmp (&a.0) });
            for n in 0..x.min (tmp.len ()) {
                resposta [i] += tmp [n].0 * tmp [n].1;
            }
            contagens.clear ();
        }
        resposta
    }
}
