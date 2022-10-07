type MyCalendarThree struct {
    eventos map [int] int
}


func Constructor() MyCalendarThree {
    return MyCalendarThree {eventos: make (map [int] int)}
}


func (this *MyCalendarThree) Book(start int, end int) int {

    maior := func (a int, b int) int {
        if a > b {
            return a
        }
        // else
        return b
    }

    if _, existe := this.eventos [start]; existe {
        this.eventos [start] += 1
    } else {
        this.eventos [start] = 1;
    }
    if _, existe := this.eventos [end]; existe {
        this.eventos [end] -= 1
    } else {
        this.eventos [end] = -1; // Por padrão, fica negativo
    }

    // map, em GoLang, não é ordenado. Tem que ver uma forma de ordenar
    var chaves [] int
    for i := range this.eventos {
        chaves = append (chaves, i)
    }
    sort.Ints (chaves)

    var acumulado int = 0
    var resposta int = 0
    for _, i := range chaves {
        acumulado += this.eventos [i]
        resposta = maior (resposta, acumulado)
    }

    return resposta
}


/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(start,end);
 */

