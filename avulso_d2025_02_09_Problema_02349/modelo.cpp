class NumberContainers {
    private:
        map<int, set<int>> valores;
        map<int, int> indices;
    public:
        NumberContainers() {
            // Não precisa inicializar
        }
        
        void change(int index, int number) {
            if (indices.count (index) != 0) {
                valores [indices [index]].erase (index);
            }
            valores [number].insert (index);
            indices [index] = number;
        }
        
        int find(int number) {
            return valores [number].empty () ? -1 : *valores [number].begin ();
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */
    