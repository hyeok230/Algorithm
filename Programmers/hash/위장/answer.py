def solution(clothes):
    dictionary = {}
    answer = 1
    # 옷 종류에 따라 각각의 list 생성
    for c1, c2 in clothes:
        if c2 in dictionary.keys():
            dictionary[c2].append(c1)
        else:
            dictionary[c2] = [c1]
    # 각 리스트의 개수에 +1를(안 입었을 때) 해주고 모두 곱하면 모든 경우에 수가 나온다
    for i in dictionary.values():
        answer *= (len(i) + 1)
    # 모두 안 입었을 경우만 빼줌
    return (answer - 1)