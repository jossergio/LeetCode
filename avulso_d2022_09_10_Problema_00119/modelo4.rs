impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        
        if row_index < 1 {
            return vec![1]
        }
        
        let mut linha: Vec<i32> = Vec::with_capacity ((row_index + 1) as usize);
        
        linha.push (1);
        linha.push (1);
        
        for i in 2..=row_index as usize {
            
            let mut anterior = linha [0];
            
            for j in 1..i {
                let tmp = linha [j];
                linha [j] = anterior + linha [j];
                anterior = tmp
            }
            
            linha.push (1);
        }
        
        return linha
    }
}

