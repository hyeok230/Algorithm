def solution(priorities, location):
    array1 = [i for i in range(len(priorities))]
    array2 = priorities.copy()
    
    i = 0
    while True:
        if array2[i] < max(array2[i+1:]):
            array2.append(array2.pop(i))
            array1.append(array1.pop(i))
        else:
            i += 1
        if array2 == sorted(array2, reverse=True):
            break
    return array1.index(location) + 1

# deque를 사용하면 약 절반 정도 빠르다
def solution(priorities, location):
    answer = 0 
    from collections import deque
    d = deque([(v, i) for i, v in enumerate(priorities)])
    
    while len(d) > 0:
        item = d.popleft()
        if d and item[0] < max(d)[0]:
            d.append(item)
        else:
            answer += 1
            if item[1] == location:
                break
    return answer