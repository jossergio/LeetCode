func sortArray(nums []int) []int {
    contagem := make (map [int] int)
    menor := nums [0] // Só para referência
    maior := nums [0] // Idem
    for _, n := range nums {
        if _, existe := contagem [n]; existe {
            contagem [n] += 1
        } else {
            contagem [n] = 1
        }
        if n < menor {
            menor = n
        }
        if n > maior {
            maior = n
        }
    }
    var k int = 0 // Será índice para nums, no laço de atualização
    for n := menor; n <= maior; n += 1 {
        if v, existe := contagem [n]; existe {
            for v > 0 {
                nums [k] = n
                k += 1
                v -= 1
            }
        }
    }
    return nums
}

