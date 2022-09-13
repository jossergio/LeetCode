impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        
        let mut triangulo: Vec<Vec<i32>> = Vec::new ();
        
        triangulo.push (vec![1]);
        triangulo.push (vec![1, 1]);
        
        for i in 2..=row_index {
            
            let linhaAnterior = (i - 1) as usize; // Só para evitar ficar recalculando
            let mut tmp = vec![1; (i + 1) as usize]; // O 1o e o último estão aqui
            
            for j in 1..triangulo [linhaAnterior].len () {
                tmp [j] = triangulo [linhaAnterior][j - 1] + triangulo [linhaAnterior][j];
            }
            
            triangulo.push (tmp);
        }
        
        return triangulo [row_index as usize].to_vec ()
    }
}

