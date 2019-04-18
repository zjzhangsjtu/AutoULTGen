import os
import re

class Stack():  
    def __init__(self,size):  
        self.size=size
        self.stack=[] 
        self.top=-1
    def push(self,ele):  #  
        if self.isfull():  
            raise exception("out of range")
        else:  
            self.stack.append(ele) 
            self.top=self.top+1
    def pop(self):             # 
        if self.isempty():  
            raise exception("stack is empty") 
        else:  
            self.top=self.top-1 
            return self.stack.pop()
       
    def isfull(self):  
        return self.top+1==self.size
    def isempty(self):  
        return self.top==-1

def doRegex(i):
    p = r"(class|friend|public) ([A-Z][^;\s]+)([;\s])"
    return re.sub(p, '\g<1> \g<2>Next\g<3>', i)

s = os.sep
root = './' #this is the root dir. Please change it to your dir.
#Only files under os (or subdirs) should be modified; only .h and .c files should be modified.
WFC=[] #Wait For Check

print "ready"
file_number=1

for rt,dirs,files in os.walk(root):
    if "os" in dirs:
        #print rt
        #print dirs

        WFC.append(rt+"/"+"os")
        for file in os.listdir(rt):
            if not os.path.isdir(rt+"/"+file):
                pass 


print WFC

for osdir in WFC:
    for rt,dirs,files in os.walk(osdir):
        #print rt
        for file in os.listdir(rt):
            if rt.find("i915", 0, len(rt))!=-1:
                break
            if not os.path.isdir(rt+"/"+file):
                if file=="media_srcs.cmake":
                    file_data = ""
                    with open(rt+"/"+file, "r") as f:
                        for line in f:
                            temp_line=line.split('/')
                            if temp_line[-1].find("mos_", 0, 5)!=-1:
                                if temp_line[-1].find(".h",-5, len(temp_line[-1]))!=-1:
                                    line=line.replace(".h","_next.h")
                                if temp_line[-1].find(".c",-5, len(temp_line[-1]))!=-1:
                                    line=line.replace(".c","_next.c")
                            file_data += line
                    with open(rt+"/"+file,"w") as f:
                        f.write(file_data)                         
                if file.find("mos_", 0, 5)!=-1:
                    print rt+"/"+file
                    file_data = ""
                    with open(rt+"/"+file, "r") as f:
                        for line in f:
                            if line.split(' ')[0]=="#ifndef" or line.split(' ')[0]=="#define" or line.split(' ')[0]=="#endif":
                                line=line.replace("_H","_NEXT_H")
                                #print line
                            if line.split(' ')[0]=="#include" and line.split(' ')[1].find("\"mos_", 0, 5)!=-1:
                                line=line.replace(".h\"","_next.h\"")
                                #print line

                            line=doRegex(line)

                            if line.find("class")==-1 and line.find("public")==-1 and line.find("friend")==-1:
                                line_split=line
                                findlocall=Stack(50)
                                curloc=0
                                temp_line=line.lower()
                                temp_fname=file.replace("_","").split(".")[0].replace("mos","")
                                while curloc<len(temp_line):
                                    findloc=temp_line.find(temp_fname,curloc,len(temp_line))
                                    if findloc!=-1:
                                        #print line
                                        #print findloc
                                        findlocall.push(findloc)
                                        curloc=findloc+len(temp_fname)
                                    else:
                                        break
                                while not findlocall.isempty():
                                    findloc=findlocall.pop()
                                    line=line[:findloc+len(temp_fname)]+"Next"+line[findloc+len(temp_fname):]
                            file_data += line
                    with open(rt+"/"+file,"w") as f:
                        f.write(file_data)
                    if file.find(".h", -5, len(file))!=-1:
                        #print ".h"
                        os.rename(rt+"/"+file,(rt+"/"+file).replace(".h","_next.h"))
                    if file.find(".c", -5, len(file))!=-1:
                        #print ".c"
                        os.rename(rt+"/"+file,(rt+"/"+file).replace(".c","_next.c"))                
