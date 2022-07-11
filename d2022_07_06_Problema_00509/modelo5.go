var fibs [31] int // Incluirá o zero até 30; O problema cita esses limites
var criados bool // = false

func fib(n int) int {
    
    if !criados {
        
        fibs [0] = 0
        fibs [1] = 1
        
        for k := 2; k <= 30; k++ {
            fibs [k] = fibs [k - 1] + fibs [k - 2]
        }
        
        criados = true
    }
    
    return fibs [n]
}

