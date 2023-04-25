class SmallestInfiniteSet:

    def __init__(self):
        self.heap = []
        self.proximo = 0

    def popSmallest(self) -> int:
        if len (self.heap) == 0:
            self.proximo += 1
            return self.proximo
        # else
        return heappop (self.heap)

    def addBack(self, num: int) -> None:
        if num <= self.proximo and (not num in self.heap):
                heappush (self.heap, num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)

