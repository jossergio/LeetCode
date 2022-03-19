type FreqStack struct {
    acumulador int // = 0
    pilha map [int] [] int
}


func Constructor() FreqStack {
    
    var estrutura FreqStack
    
    estrutura.pilha = make (map [int] [] int)
    
    return estrutura
}


func (this *FreqStack) Push(val int)  {
    this.pilha [val] = append (this.pilha [val], this.acumulador)
    this.acumulador++
}


func (this *FreqStack) Pop() int {
    
    var maiorFreq int // = 0
    var valor int // = 0
    var maisProximo int // = 0
    
    for i, p := range this.pilha {
        if len (p) > maiorFreq {
            valor = i
            maiorFreq = len (p)
            maisProximo = p [len (p) - 1]
        } else {
            if len (p) != 0 && len (p) == maiorFreq {
                if p [len (p) - 1] > maisProximo {
                    valor = i
                    maisProximo = p [len (p) - 1]
                }
            }
        }
    }
    
    this.pilha [valor] = this.pilha [valor][:len (this.pilha [valor]) - 1]
    
    return valor
    
}


/**
 * Your FreqStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * param_2 := obj.Pop();
 */

