result = ""
def rec(a, ai, b, bi, ex):
    global result
    temp_a = "0"
    temp_b = "0"
    if ai < 0 and bi < 0:
        if ex:
            result = "1" + result
        return
    if ai >= 0:
        temp_a = a[ai]
    if bi >= 0:
        temp_b = b[bi]
    if temp_a == temp_b and temp_a == "1":
        result = ("1" if ex else "0") + result
        ex = True
    elif temp_a == temp_b and temp_a == "0":
        result = ("1" if ex else "0") + result
        ex = False
    else:
        if ex:
            result = "0" + result
            ex = True
        else:
            result = "1" + result
            ex = False
    rec(a, ai - 1, b, bi - 1, ex)


def addBinary(a: str, b: str) -> str:
    global result
    result = ""
    rec(a, len(a) - 1, b, len(b) - 1, False)
    return result

# print(addBinary("11", "1"))
# print(addBinary("1010", "1011"))
print(addBinary("1111", "1111"))
