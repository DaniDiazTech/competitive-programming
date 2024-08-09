n = int(input())
s = input()
ev = ""
for i in range(0, len(s) -1 ):
    ev += s[i]
    if (s[i] == '('):
        if (s[i + 1] == ')'):
            ev += '1'
    else:
        if (s[i + 1] == ')'):
            ev += "+1"
        else:
            ev += '*'
ev += s[len(s) - 1]

print(eval(ev))