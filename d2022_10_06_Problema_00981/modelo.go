type TimeMap struct {
    mapa map [string] map [int] string
}


func Constructor() TimeMap {
    var timeMap TimeMap
    timeMap.mapa = make (map [string] map [int] string)
    return timeMap
}


func (this *TimeMap) Set(key string, value string, timestamp int)  {
    if _, existe := this.mapa [key]; !existe {
        this.mapa [key] = make (map [int] string)
    }
    this.mapa [key][timestamp] = value // Indiferente se o timestape existe
}


func (this *TimeMap) Get(key string, timestamp int) string {
    if chaves, existe := this.mapa [key]; existe {
        var valor string
        for timestamp >= 0 {
            if valor, existe = chaves [timestamp]; existe {
                return valor
            }
            timestamp -= 1
        }
    }
    return ""
}


/**
 * Your TimeMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Set(key,value,timestamp);
 * param_2 := obj.Get(key,timestamp);
 */

