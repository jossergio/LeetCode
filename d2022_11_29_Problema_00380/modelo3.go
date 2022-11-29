type RandomizedSet struct {
    Conjunto map [int] bool
}


func Constructor() RandomizedSet {
    var tmp RandomizedSet
    tmp.Conjunto = make (map [int] bool)
    return tmp
}


func (this *RandomizedSet) Insert(val int) bool {
    if v, existe := this.Conjunto [val]; existe && v {
        return false
    }
    // else
    this.Conjunto [val] = true;
    return true
}


func (this *RandomizedSet) Remove(val int) bool {
    if v, existe := this.Conjunto [val]; existe && v {
        this.Conjunto [val] = false
        return true
    }
    // else
    return false
}


func (this *RandomizedSet) GetRandom() int {
    var tmp [] int
    for i, v := range this.Conjunto {
        if v {
            tmp = append (tmp, i)
        }
    }
    return tmp [rand.Intn (len (tmp))]
}


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */

