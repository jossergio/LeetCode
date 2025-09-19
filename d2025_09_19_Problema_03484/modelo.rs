use std::collections::HashMap;
struct Spreadsheet {
    grade: HashMap<char, Vec<i32>>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Spreadsheet {

    fn pega_celula (&self, c: &str) -> i32 {
        let (coluna, valor) = Self::dec_celula (&c);
        if coluna == ' ' {
            return valor as i32
        }
        // else
        self.grade [&coluna][valor]
    }

    fn pega_valor (c: &str) -> usize {
        c.parse::<usize> ().unwrap ()
    }

    fn dec_celula (c: &str) -> (char, usize) {
        let mut col: char = c.chars ().nth (0).unwrap ();
        let mut idx: usize = 1;
        if col.is_numeric () {
            col = ' ';
            idx = 0;
        }
        (col, Self::pega_valor (&c [idx..]) - idx) // idx tem dupla finalidade
    }

    fn new(rows: i32) -> Self {
        let mut grade: HashMap<char, Vec<i32>> = HashMap::new ();
        for a in 'A'..='Z' {
            grade.insert (a, vec![0; rows as usize]);
        }
        Self { grade }
    }
    
    fn set_cell(&mut self, cell: String, value: i32) {
        let (coluna, linha) = Self::dec_celula (&cell); // Sempre é representação de célula
        let mut tmp = self.grade.get_mut (&coluna).unwrap ();
        tmp [linha] = value;
    }
    
    fn reset_cell(&mut self, cell: String) {
        self.set_cell (cell, 0);
    }
    
    fn get_value(&self, formula: String) -> i32 {
        let pos = formula.find ('+').unwrap (); // Há, sempre um
        let mut v1 = String::from (&formula [1..pos]);
        let mut v2 = String::from (&formula [(pos+1)..]);
        self.pega_celula (&v1) + self.pega_celula (&v2)
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * let obj = Spreadsheet::new(rows);
 * obj.set_cell(cell, value);
 * obj.reset_cell(cell);
 * let ret_3: i32 = obj.get_value(formula);
 */
 