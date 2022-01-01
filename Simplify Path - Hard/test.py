def simplifyPath(path: str) -> str:
    changed_path = []
    splitted = path.split('/')
    for s in splitted:
        if s == '' or s == '.':
            continue
        else:
            if s == '..' and len(changed_path) != 0:
                del changed_path[len(changed_path) - 1]
            elif s == '..' and len(changed_path) == 0:
                continue
            else:
                changed_path.append(s)
    
    print(changed_path)
    current = '/'
    for i, c in enumerate(changed_path):
        current += c
        if i != len(changed_path) - 1:
            current += '/'
    return current
        

print(simplifyPath("/home/"))
print(simplifyPath("/../"))
print(simplifyPath("/home//foo/"))
print(simplifyPath("/a/./b/../../c/"))
