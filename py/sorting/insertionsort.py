from sorter import Sorter

import time

'''
Time Complexity:    O(n^2)   
Space Complexity:   O(1)

Divide into sorted and unsorted parts
Iterate over unsorted segment, insert the element viewed into correct position of sorted list
Comparing unsorted to sorted elem 'x'. Move unsorted elem to correct position then first elem last
'''
class InsertionSort(Sorter):
    def __init__(self, input: list):
        super().__init__(input)
        self.name = 'InsertionSort'

    def sort(self):
        # Start with second elem
        for idx in range(1, len(self.numbers)):
            num_to_insert = self.numbers[idx]  
            idx2 = idx - 1
            # Move larger elem later in list if larger than item to insert
            while idx2 >= 0 and self.numbers[idx2] > num_to_insert:
                # Move 
                self.numbers[idx2 + 1] = self.numbers[idx2]
                idx2 -= 1

            # Insert item in correct place
            self.numbers[idx2 + 1] = num_to_insert

sorter = InsertionSort([6,7,8,3,1,4,2,4,5])
begin_time = time.time()
sorter.sort()
elapsed = (time.time() - begin_time) * 1e3
sorter.print_results(sorter.name)
print("\tDuration = {} ms".format(elapsed))