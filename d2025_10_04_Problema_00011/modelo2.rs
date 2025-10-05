impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut resp = 0; // i32
        let mut esq = 0usize;
        let mut dir = height.len () - 1;
        while esq < dir {
            resp = resp.max (i32::min (height [esq], height [dir]) * (dir as i32 - esq as i32));
            if height [esq] < height [dir] {
                esq += 1;
            } else {
                dir -= 1;
            }
        }
        resp
    }
}
