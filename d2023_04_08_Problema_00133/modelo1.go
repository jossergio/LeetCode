/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */

func montar (no *Node, mapa map [int] *Node) *Node {
    if _, existe := mapa [no.Val]; !existe {
        tmp := &Node {no.Val, make ([] *Node, len (no.Neighbors))}
        mapa [no.Val] = tmp
        for i, item := range no.Neighbors {
            tmp.Neighbors [i] = montar (item, mapa)
        }
    }
    return mapa [no.Val]
}

func cloneGraph(node *Node) *Node {
    if node == nil { // Por falta disso, produziu um erro
        return nil
    }
    mapa := make (map [int] *Node)
    return montar (node, mapa)
}

