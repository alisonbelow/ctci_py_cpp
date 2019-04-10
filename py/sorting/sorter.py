from abc import ABCMeta, abstractmethod
import copy
import six

@six.add_metaclass(ABCMeta)
class Sorter:
    def __init__(self, input: list):
        self.initial_input = copy.deepcopy(input)
        self.numbers = input
        self.output = []

    @abstractmethod
    def sort(self):
        pass

    def check_accurate(self) -> bool:
        return all(self.numbers[i-1] <= self.numbers[i] for i in range(1, len(self.numbers)))

    def print_results(self, sort_type = ""):
        print('{}\n\tBefore: {}\n\tAfter: {}'.format(sort_type, self.initial_input, self.numbers))