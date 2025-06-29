#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // Left half (max-heap)
    priority_queue<int, vector<int>, greater<int>> minHeap; // Right half (min-heap)

public:
    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Add to maxHeap first
        maxHeap.push(num);

        // Step 2: Move the largest from maxHeap to minHeap to balance order
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: Maintain size property
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            // Even total count
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            // Odd total count
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */