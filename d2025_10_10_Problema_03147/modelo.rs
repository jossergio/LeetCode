impl Solution {
    fn buscar (nivel: usize, e: &Vec<i32>, f: &mut Vec<bool>, v: &mut Vec<i64>, k: usize) -> i64 {
        if nivel >= v.len () {
            return 0; // Padrão
        }
        if !f [nivel] {
            f [nivel] = true;
            v [nivel] = (e [nivel] as i64) + Self::buscar (nivel + k, e, f, v, k);
        }
        v [nivel]
    }

    pub fn maximum_energy(energy: Vec<i32>, k: i32) -> i32 {
        let t = energy.len ();
        let mut valores = vec![0 as i64; t];
        let mut feitos = vec![false; t];
        let mut maximo = i64::MIN;
        for i in 0..t {
            maximo = maximo.max (Self::buscar (i, &energy, &mut feitos, &mut valores, k as usize));
        }
        maximo as i32
    }
}
