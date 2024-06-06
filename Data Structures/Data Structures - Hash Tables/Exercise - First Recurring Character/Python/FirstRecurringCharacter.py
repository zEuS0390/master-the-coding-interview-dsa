def firstRecurringChar(arr):
    recurring_char_map = {}
    for item in arr:
        recurring_char_map[item] = recurring_char_map.get(item, 0) + 1 
        if recurring_char_map[item] > 1:
            return item
    return None

arr = [2,1,1,2,3,5,1,2,4]
result = firstRecurringChar(arr)
print(result)
