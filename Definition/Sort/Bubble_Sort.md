Bubble Sort
===
### Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

Example
===
![](Bubble_sort.gif)


Complexity
===

  * Time Complexity

    * Worst complexity: O(n^2)
    * Average complexity: O(n^2)
    * Best complexity: O(n)
    
  * Space Complexity

    * O(2)
    

CODE
===

#### C++
``` c++
void bubbleSort(int array[], int size) {
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}
```

#### Python
``` python
def bubbleSort(array):
    for i in range(len(array)):
        for j in range(0, len(array) - i - 1):
            if array[j] > array[j + 1]:
                (array[j], array[j + 1]) = (array[j + 1], array[j])
```
