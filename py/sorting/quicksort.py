from sorter import Sorter

import math
import time

'''
Time Complexity:    O(nlog(n))   (generally, WC is O(n^2) if initial pivot is smallest or largest elem)
Space Complexity:   O(1)

Divide and conquer alg
Most often used
Efficient and no extra space if done correctly
Partition list around pivot elem, sort elems recursively around pivot
'''
class QuickSort(Sorter):
    def __init__(self, input: list):
        super().__init__(input)
        self.name = 'QuickSort'

    @staticmethod
    def _partition(nums: list, low: int, high: int) -> int:
        pivot_val = nums[math.floor((low + high) / 2)]
        left_idx = low - 1
        right_idx = high + 1

        while True:
            left_idx += 1
            while nums[left_idx] < pivot_val:
                left_idx += 1

            right_idx -= 1
            while nums[right_idx] > pivot_val:
                right_idx -= 1

            if left_idx >= right_idx:
                return right_idx

            # If elem left of pivot (at index i) is alrger than element to right of pivot (at index j), swap
            nums[right_idx], nums[left_idx] = nums[left_idx], nums[right_idx]
    
    @staticmethod
    def _quick_sort(nums: list, low_idx: int, high_idx: int):
        if low_idx < high_idx:
            split_idx = QuickSort._partition(nums, low_idx, high_idx)
            QuickSort._quick_sort(nums, low_idx, split_idx)
            QuickSort._quick_sort(nums, split_idx + 1, high_idx)

    def sort(self):
        QuickSort._quick_sort(self.numbers, 0, len(self.numbers) - 1)

sorter = QuickSort([6,7,8,3,1,4,2,4,5])
begin_time = time.time()
sorter.sort()
elapsed = (time.time() - begin_time) * 1e3
sorter.print_results(sorter.name)
print("\tDuration = {} ms".format(elapsed))