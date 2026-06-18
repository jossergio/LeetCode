impl Solution {
    pub fn angle_clock(hour: i32, minutes: i32) -> f64 {
        let minutos = (minutes as f64 /60f64) * 360f64;
        let mut horas = (hour * 30) as f64 + minutos / 12f64;
        // 12h é 0h
        if horas >= 360f64 { horas -= 360f64 }
        f64::abs (horas - minutos)
            .min (360f64 - f64::abs (minutos - horas))
    }
}
