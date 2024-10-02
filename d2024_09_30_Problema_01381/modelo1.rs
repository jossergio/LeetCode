struct CustomStack {
    t: usize,
    pilha: Vec<i32>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl CustomStack {

    fn new(maxSize: i32) -> Self {
        Self {
            t: maxSize as usize,
            pilha: Vec::with_capacity (maxSize as usize),
        }
    }
    
    fn push(&mut self, x: i32) {
        if self.pilha.len () < self.t {
            self.pilha.push (x);
        }
    }
    
    fn pop(&mut self) -> i32 {
        if self.pilha.len () > 0 {
            return {
                let tmp = self.pilha.pop ();
                match tmp {
                    Some (v) => v,
                    None => -1,
                }
            }
        }
        -1 // Valor constante
    }
    
    fn increment(&mut self, k: i32, val: i32) {
        let mut k = k as usize; // Sombreiace muda o tipo
        k = if k < self.pilha.len () { k } else { self.pilha.len () }; // Define o máximo
        for v in &mut self.pilha [0..k] {
            *v += val;
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * let obj = CustomStack::new(maxSize);
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * obj.increment(k, val);
 */
 
