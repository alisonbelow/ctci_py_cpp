from sorter import Sorter

import time

'''
Time Complexity:    O(n^2)   
Space Complexity:   O(1)

Divide list into sorted and unsorted
Continously remove smallest elem of unsorted segment of list and append to sorted segment
Treat leftmost as sorted part initially
'''
class SelectionSort(Sorter):
    def __init__(self, input: list):
        super().__init__(input)
        self.name = 'SelectionSort'

    def sort(self):
        # idx = how many elems sorted
        for idx in range(len(self.numbers)):
            lowest_value_idx = idx  # Assume first elem is smallest
            # Iterate through unsorted elems
            for iter_idx in range(idx + 1, len(self.numbers)):
                # Swap if smaller number later in list
                if self.numbers[iter_idx] < self.numbers[lowest_value_idx]:
                    lowest_value_idx = iter_idx

            self.numbers[idx], self.numbers[lowest_value_idx] = self.numbers[lowest_value_idx], self.numbers[idx]

sorter = SelectionSort([6,7,8,3,1,4,2,4,5])
begin_time = time.time()
sorter.sort()
elapsed = (time.time() - begin_time) * 1e3
sorter.print_results(sorter.name)
print("\tDuration = {} ms".format(elapsed))