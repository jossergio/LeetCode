var fibs map [int] int = make (map [int] int)
var maior int = -1

func fib(n int) int {
    
    if _, existe := fibs [n]; !existe {
        for k := maior + 1; k <= n; k++ {
            if k <= 1 {
                fibs [k] = k
            } else {
                fibs [k] = fibs [k - 1] + fibs [k - 2] // Com certeza, já existem
            }
        }
    }
    if n > maior {
        maior = n
    }
    return fibs [n]
}

