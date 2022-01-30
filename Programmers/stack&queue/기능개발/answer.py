def solution(progresses, speeds):
    answer = []
    length = len(progresses)
    while length > 0:
        progresses = [x + y for x, y in zip(progresses, speeds)]
        cnt = 0
        for i in progresses:
            if (i >= 100):
                cnt += 1
            else:
                break
        if cnt > 0:
            del progresses[0:cnt]
            del speeds[0:cnt]
            answer.append(cnt)
        length = len(progresses)
        
    return answer

def solution(progresses, speeds):
    answer = []
    time = 0
    count = 0
    while len(progresses)> 0:
        if (progresses[0] + time*speeds[0]) >= 100:
            progresses.pop(0)
            speeds.pop(0)
            count += 1
        else:
            if count > 0:
                answer.append(count)
                count = 0
            time += 1
    answer.append(count)
    return answer