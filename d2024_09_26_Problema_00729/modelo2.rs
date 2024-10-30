struct MyCalendar {
    lista: Vec<(i32, i32)>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyCalendar {

    fn new() -> Self {
        Self {lista: Vec::new (),}
    }
    
    fn book(&mut self, start_time: i32, end_time: i32) -> bool {
        for p in &self.lista {
            if p.1 > start_time && p.0 < end_time {
                return false;
            }
        }
        self.lista.push ((start_time, end_time));
        true
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * let obj = MyCalendar::new();
 * let ret_1: bool = obj.book(startTime, endTime);
 */
 
