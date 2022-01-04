import os
import subprocess

folders = list(next(os.walk(".")))
del folders[2]
del folders[0]

folders = folders[0]
del folders[0]

print(len(folders))
for folder in folders:
    input_path = "./%s/input"%(folder)
    output_path = "./%s/output"%(folder)
    exe_path = ""
    for p in os.listdir("./%s/"%(folder)):
        if ".exe" in p:
            exe_path = "./%s/"%(folder) + p
            break
    print(folder)
    # print(input_path)
    # print(output_path)
    # print(exe_path, open("%s/%d.in"%(input_path, 1)))
    for i in range(1, 11):
        print("Test case %d"%(i))
        subprocess.Popen("%s"%(exe_path), stdin=open("%s/%d.in"%(input_path, i)), stdout=open("%s/%d.out"%(output_path, i), "w"), stderr=subprocess.PIPE, shell=True)
        # output_file = open("%s/%d.out"%(output_path, i), "w")
        # o, e = cmd.communicate()
        # if o == b'':
        #     output_file.write(e.decode())
        # else:
        #     output_file.write(o.decode().rstrip() + "\n")
        # output_file.close()