class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap (stones.begin (), stones.end ());
        while (heap.size () > 1) {
            int tmp = heap.top ();
            heap.pop ();
            tmp -= heap.top ();
            heap.pop ();
            if (tmp > 0)
                heap.push (tmp);
        }
        return (heap.size () > 0 ? heap.top () : 0);
    }
};

