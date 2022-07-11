var fibs map [int] int = make (map [int] int)

func fib(n int) int {
    
    if _, existe := fibs [n]; !existe {
        if n <= 1 {
            fibs [n] = n
        } else {
            fibs [n] = fib (n - 1) + fib (n - 2)
        }
    }
    
    return fibs [n]
}

