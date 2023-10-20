


int maxElement(int n, int maxSum, int k) {
    
    // If there is one element, return the maxSum
    if (n == 1) {
        return maxSum;
    }

    int right = k;  // The current index on the right side
    int left = k;   // The current index on the left side
    int count = 1;  // The count of elements considered so far
    int limitRight = n - 1;  // The maximum index on the right side

    while (n <= maxSum && (left > 0 || right < limitRight)) {

        // Add the number of elements in the current range to the total sum
        n += right - left + 1;
        
        if (left > 0) {
            // Move the left index to the left if it's greater than 0
            left--;
        }
        if (right < limitRight) {
            // Move the right index to the right if it's less than the max index
            right++;
        }
        // Increment the count of considered elements
        count++;
    }

    if (n < maxSum) {
        // Add additional elements to reach the maximum sum
        count += (maxSum - n) / (right - left + 1) + 1;
    }

    return count - 1;

}