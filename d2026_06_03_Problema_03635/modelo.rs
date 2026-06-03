impl Solution {
    fn checar (v1: &Vec<i32>, v2: &Vec<i32>, v3: &Vec<i32>, v4: &Vec<i32>) -> i32 {
        let mut m = i32::MAX;
        for i in 0..v1.len () {
            m = m.min (v1 [i] + v2 [i])
        }
        let mut n = i32::MAX;
        for i in 0..v3.len () {
            n = n.min (m.max (v3 [i]) + v4 [i]);
        }
        n
    }
    pub fn earliest_finish_time(land_start_time: Vec<i32>, land_duration: Vec<i32>, water_start_time: Vec<i32>, water_duration: Vec<i32>) -> i32 {
        Self::checar (&land_start_time, &land_duration, &water_start_time, &water_duration).min (Self::checar (&water_start_time, &water_duration, &land_start_time, &land_duration))
    }
}
