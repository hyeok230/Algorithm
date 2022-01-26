# sorting을 사용한 solution
# 시간복잡도 : log(n)
def solution(participant, completion):
    answer = ''
    participant.sort()
    completion.sort()
    
    for i in range(len(completion)):
        if (participant[i] != completion[i]):
            return participant[i]
    
    return participant[len(participant) - 1]

# Hash를 사용한 solution
# 시간복잡도 : log(n)
def solution(participant, completion):
    dictionary = {}
    sumHash = 0
    
    for i in participant:
        dictionary[hash(i)] = i
        sumHash += hash(i)
    for i in completion:
        sumHash -= hash(i)
        
    return dictionary[sumHash]

# Counter를 사용한 solution
import collections
def solution(participant, completion):
    answer = collections.Counter(participant) - collections.Counter(completion)    
    
    return list(answer.keys())[0]