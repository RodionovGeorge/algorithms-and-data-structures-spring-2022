#include <iostream>

bool check(int const * const points, int n, int k, int length)
{
    int currentK = 0, nextPointIndex = 0, pointValue;
    while (nextPointIndex < n && currentK < k) {
        pointValue = points[nextPointIndex];
        while ((nextPointIndex < n) && ((pointValue + length) >= points[nextPointIndex])) {
            nextPointIndex++;
        }
        currentK++;
    }
    return nextPointIndex >= n;
}

int binarySearch(int const * const array, int N, int K, int minLength, int maxLength)
{
    size_t currentLength = (maxLength + minLength) / 2;
    if (maxLength - minLength <= 1) {
        return maxLength;
    }
    if (check(array, N, K, currentLength)) {
        return binarySearch(array, N, K, minLength, currentLength);
    } else {
        return binarySearch(array, N, K, currentLength, maxLength);
    }
}

int main()
{
    int N, K;
    int *points;
    std::cin >> N >> K;
    points = new int[N];
    for (size_t i = 0; i < N; i++) {
        std::cin >> points[i];
    }
    std::cout << binarySearch(points, N, K, 0, points[N - 1] - points[0]) << std::endl;
    delete[] points;
    return 0;
}
