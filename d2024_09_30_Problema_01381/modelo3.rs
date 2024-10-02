use std::cmp::min;

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
            pilha: Vec::with_capacity (maxSize as usize), // Já sei o maximo de espaço que será usado
        }
    }
    
    fn push(&mut self, x: i32) {
        if self.pilha.len () < self.t {
            self.pilha.push (x);
        }
    }
    
    fn pop(&mut self) -> i32 {
        match self.pilha.pop () {
            Some (v) => v,
            None => -1
        }
    }
    
    fn increment(&mut self, k: i32, val: i32) {
        let k = min (self.pilha.len (), k as usize); // Sombreia para mudar o tipo; define o limite
        for v in self.pilha [..k].iter_mut () {
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
 
