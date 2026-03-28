// Copyright 2021 NNTU-CS

#include <cstdint>
#include "alg.h"

int countPairs1(int *arr, int len, int value) {
  int per1 = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        per1++;
      }
    }
  }
  return per1;
}

int countPairs2(int *arr, int len, int value) {
  int per2 = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int x = right - left + 1;
        per2 += x * (x - 1) / 2;
        break;
      }
      int leftPerem = 1;
      int rightPerem = 1;
      while (left + leftPerem < right && arr[left] == arr[left + leftCount])
        leftPerem++;
      while (right - rightPerem > left && arr[right] == arr[right - rightCount])
        rightPerem++;
          per2 += leftPerem * rightPerem;
      left += leftPerem;
      right -= rightPerem;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return per2;
}

int countPairs3(int *arr, int len, int value) {
  int per3 = 0;
  for (int i = 0; i < len; i++) {
    if (i > 0 && arr[i] == arr[i - 1])
      continue;
    int tar = value - arr[i];
    if (tar < arr[i])
      break;
    int lows = -1;
    int highs = -1;
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == tar) {
        lows = mid;
        right = mid - 1;
      } else if (arr[mid] < tar) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (lows == -1)
      continue;
    left = lows;
    right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == tar) {
        hig = mid;
        left = mid + 1;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (arr[i] == tar) {
        int n = hi - i + 1;
      per3 += n * (n - 1) / 2;
      break;
      }
    int leftPerem = 1;
    while (i + leftPerem < len && arr[i + leftPerem] == arr[i])
      leftPerem++;
    per3 += leftPerem * (hi - lo + 1);
  }
  return per3;
}
