from sorter import Sorter

import math
import time

'''
Time Complexity:    O(nlog(n))   
Space Complexity:   O(n)    --> more space

Divide and conquer algorithm
Sort list into pairs, and sort those pairs
Sorted pairs merged and sorted with other pairs until list fully sorted
'''
class MergeSort(Sorter):
    def __init__(self, input: list):
        super().__init__(input)
        self.name = 'MergeSort'

    @staticmethod
    def _merge_sort(nums: list) -> list:
        if len(nums) <= 1: 
            return nums

        mid_idx = math.floor(len(nums) / 2)

        left_list = MergeSort._merge_sort(nums[:mid_idx])
        right_list = MergeSort._merge_sort(nums[mid_idx:])

        return MergeSort._merge(left_list, right_list) 

    @staticmethod
    def _merge(left_list: list, right_list: list) -> list:
        sorted_list = []
        left_idx = 0
        right_idx = 0
        left_len = len(left_list)
        right_len = len(right_list)

        for _ in range(left_len + right_len):
            if left_idx < left_len and right_idx < right_len:
                # Check beginning value from each list
                # Add smaller elem to sorted_list
                if left_list[left_idx] <= right_list[right_idx]:
                    sorted_list.append(left_list[left_idx])
                    left_idx += 1 
                else:
                    sorted_list.append(right_list[right_idx])
                    right_idx += 1                     

            # Else, may have reached end of left list, add right list elems
            elif left_idx == left_len:
                sorted_list.append(right_list[right_idx])
                right_idx += 1

            # Else, may have reached end of right list, add left list elems
            elif right_idx == right_len:
                sorted_list.append(left_list[left_idx])
                left_idx += 1

        return sorted_list

    def sort(self):
        self.numbers = MergeSort._merge_sort(self.numbers)

sorter = MergeSort([6,7,8,3,1,4,2,4,5])
begin_time = time.time()
sorter.sort()
elapsed = (time.time() - begin_time) * 1e3
sorter.print_results(sorter.name)
print("\tDuration = {} ms".format(elapsed))