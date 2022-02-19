#include <iostream>

int binarySearch(int const * const array, int left, int right, int elementForSearching)
{
    size_t currentElementIndex = (left + right) / 2;
    if (array[currentElementIndex] == elementForSearching) {
        return currentElementIndex;
    } else {
        if (left >= right) {
            return -1;
        } else {
            if (elementForSearching > array[currentElementIndex]) {
                return binarySearch(array, currentElementIndex + 1, right, elementForSearching);
            } else {
                return binarySearch(array, left, currentElementIndex - 1, elementForSearching);
            }
        }
    }
}

int main()
{
    int N, K, elementIndex;
    int *array;
    size_t i;
    std::cin >> N;
    array = new int[N];
    for (i = 0; i < N; i++) {
        std::cin >> array[i];
    }
    std::cin >> K;
    for (i = 0; i < K; i++) {
        std::cin >> elementIndex;
        std::cout << binarySearch(array, 0, N - 1, elementIndex) << std::endl;
    }
    delete[] array;
    return 0;
}
