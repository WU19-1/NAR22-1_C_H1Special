data = open("1_in.txt", "r").readlines()
for i in range(len(data)):
    file = open("%d.in"%(i + 1), "w")
    file.write(data[i])
    file.close()
    
