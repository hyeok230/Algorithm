num = set(range(1, 10001))
not_self = set()
for i in num:
    for j in str(i):
        i += int(j)
    not_self.add(i)

answer = sorted(num - not_self)
for i in answer:
    print(i)