use std::collections::BinaryHeap;
impl Solution {
    pub fn asteroids_destroyed(mass: i32, asteroids: Vec<i32>) -> bool {
        let mut massa = mass as i64;
        let mut heap: BinaryHeap<i64> = BinaryHeap::new ();
        for v in asteroids.into_iter ().map (| a | a as i64) {
            if v <= massa { // Pode destruir
                massa += v; // Acumula na massa total
                while !heap.is_empty () && massa >= -heap.peek ().unwrap () { // Destroi anteriores ignorados
                    massa += -heap.pop ().unwrap (); // Desinverte
                }
            } else {
                heap.push (-v); // Invertido
            }
        }
        heap.is_empty ()
    }
}
