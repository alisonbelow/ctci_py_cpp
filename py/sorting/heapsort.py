from sorter import Sorter

import time

'''
Time Complexity:    O(nlog(n))   
Space Complexity:   O(1)

Transform list into a MaxHeap (Binary Tree) where biggest elem is root node
    - Place that item to end of list
    - Rebuild max heap with one less value, repeat
'''
class HeapSort(Sorter):
    def __init__(self, input: list):
        super().__init__(input)
        self.name = 'HeapSort'

    def _create_heap(self, heap_size: int, root_idx: int):
        largest = root_idx
        left_child = (2 * root_idx) + 1     # Indexing BT, left child position
        right_child = (2 * root_idx) + 2    # Indexing BT, right child position
        
        # If left child of root is a valid index, and elem is greater than curr largest elem, update largest elem
        if left_child < heap_size and self.numbers[left_child] > self.numbers[largest]:
            largest = left_child

        # If right child of root is a valid index, and elem is greater than curr largest elem, update largest elem
        if right_child < heap_size and self.numbers[right_child] > self.numbers[largest]:
            largest = right_child

        # If largest elem not root, swap
        if largest != root_idx:
            self.numbers[root_idx], self.numbers[largest] = self.numbers[largest], self.numbers[root_idx]

    def sort(self):
        N = len(self.numbers)
        
        # Range from size to -1 by -1 each time
        # Create max heap recursively
        for root_idx in range(N, -1, -1):
            self._create_heap(N, root_idx)

        # Swap max elem (root at index 0) with last element in original heap
        # Reduce size of heap (first arg of _create_heap)
        # Heapify root of tree
        for i in range(N - 1, 0, -1):
            # Swap/move elem
            self.numbers[i], self.numbers[0] = self.numbers[0], self.numbers[i]
            # Create heap do not include last element(s) swapped at end of heap
            self._create_heap(i, 0)

sorter = HeapSort([6,7,8,3,1,4,2,4,5])
begin_time = time.time()
sorter.sort()
elapsed = (time.time() - begin_time) * 1e3
sorter.print_results(sorter.name)
print("\tDuration = {} ms".format(elapsed))