from sorter import Sorter

import time

'''
Time Complexity:    O(n^2)   
Space Complexity:   O(1)

Compares elements in pairs, swapping them until larger elems "bubble up" to end of list
End gets sorted first
'''
class BubbleSort(Sorter):
    def __init__(self, input: list):
        super().__init__(input)
        self.name = 'BubbleSort'

    def sort(self):
        swapped = True
        while swapped:
            swapped = False
            for idx in range(len(self.numbers) - 1):
                # Compare elem and next elem and swap if need to move to end of list (greater)
                if self.numbers[idx] > self.numbers[idx + 1]:
                    self.numbers[idx], self.numbers[idx + 1] = self.numbers[idx + 1], self.numbers[idx]
                    # If swapped, loop again
                    swapped = True  

sorter = BubbleSort([6,7,8,3,1,4,2,4,5])
begin_time = time.time()
sorter.sort()
elapsed = (time.time() - begin_time) * 1e3
sorter.print_results(sorter.name)
print("\tDuration = {} ms".format(elapsed))