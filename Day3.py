def findDuplicate(arr: list[int]) -> int:
    slow, fast = 0, 0
    while True:
        slow = arr[slow]
        fast = arr[arr[fast]]
        if slow == fast:
            break
    finder = 0
    while finder != slow:
        finder = arr[finder]
        slow = arr[slow]
    return finder

if __name__ == "__main__":
    n = 99999
    large_array = list(range(1, n + 1))
    large_array.append(50000) # Add the duplicate
    test_cases = [{"id": 1, "input": [1, 3, 4, 2, 2], "expected": 2},
        {"id": 2, "input": [3, 1, 3, 4, 2], "expected": 3},
        {"id": 3, "input": [1, 1], "expected": 1},
        {"id": 4, "input": [1, 4, 4, 2, 3], "expected": 4},
        {"id": 5, "input": large_array, "expected": 50000},]

    print("Running Test Cases for findDuplicate :-")
    for case in test_cases:
        input_arr = case["input"]
        expected = case["expected"]   
        input_str = str(input_arr)
        if len(input_str) > 50:
            input_str = f"[1, 2, ..., {n}, 50000] (size: {len(input_arr)})"
        actual = findDuplicate(input_arr)       
        print(f"\n# Test Case {case['id']}:")
        print(f"   Input:    {input_str}")
        print(f"   Expected: {expected}")
        print(f"   Actual:   {actual}")   
        if actual == expected:
            print("   Result:   PAssed")
        else:
            print(f"  Result:  FAiled")
