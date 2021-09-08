def greedy_activity_selection(a):
    index = 0
    current_final = a[0][1]
    print('Doing activity 1')
    for i in range(1, len(a)):
        if(a[i][0] >= current_final):
            print('Doing activity', i+1)
            current_final = a[i][1]


s = [[12, 14], [8, 12], [2, 13], [8, 11], [1, 4], [
    3, 5], [0, 6], [5, 7], [3, 8], [5, 9], [6, 10]]
n = len(s)
for i in range(0, n):
    for j in range(i+1, n):
        if(s[i][1] > s[j][1]):
            s[i], s[j] = s[j], s[i]
greedy_activity_selection(s)
