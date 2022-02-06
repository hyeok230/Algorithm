T = int(input())
answer = 0
def is_hansoo(n):
    length = len(str(n))
    if length > 1:
        sub = int(str(n)[0]) - int(str(n)[1])
        for i in range(1, length - 1):
            if (int(str(n)[i]) - int(str(n)[i + 1]) != sub):
                return False
    return True

for i in range(1, T + 1):
    if is_hansoo(i):
        answer += 1
print(answer)