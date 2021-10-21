type RandomizedSet struct {
    Conjunto [] int
}

func Constructor() RandomizedSet {
    var obj RandomizedSet
    return obj
}


func (this *RandomizedSet) Insert(val int) bool {
    for i := 0; i < len (this.Conjunto); i++ {
        if this.Conjunto [i] == val {
            return false
        }
    }
    this.Conjunto = append (this.Conjunto, val)
    return true
}


func (this *RandomizedSet) Remove(val int) bool {
    for i := 0; i < len (this.Conjunto); i++ {
        if this.Conjunto [i] == val {
            switch {
                case i == 0: this.Conjunto = this.Conjunto [1:]; return true
                case i == len (this.Conjunto) - 1: this.Conjunto = this.Conjunto [0:i]; return true
                default: 
                tmp := this.Conjunto [i+1:]
                this.Conjunto = this.Conjunto [0:i]
                this.Conjunto = append (this.Conjunto, tmp...)
                return true
            }
        }
    }
    return false
}


func (this *RandomizedSet) GetRandom() int {
    return this.Conjunto [rand.Intn (len (this.Conjunto))]
}


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */

