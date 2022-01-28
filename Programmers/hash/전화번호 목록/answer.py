def solution(phone_book):
    phone_book.sort()
    for i in range(len(phone_book) - 1):
        if phone_book[i + 1].startswith(phone_book[i]):
            return False
    return True

def solution(phone_book):
    phone_book.sort()
    for p1, p2 in list(zip(phone_book, phone_book[1:])):
        if p2.startswith(p1):
            return False
    return True