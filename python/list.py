import os

def Test1(rootDir): 
    list_dirs = os.walk(rootDir) 
    for root, dirs, files in list_dirs: 
        #for d in dirs: 
        #    print os.path.join(root, d)      
        for f in files: 
            print os.path.join(root, f) 
#Test1( os.path.join( os.getenv("AppData"), "chrust", "svd", "test") )

#list=os.walk(os.path.join( os.getenv("AppData"), "chrust", "svd", "test"))
#for r, d, files in list:
#    for f in files:
#        print f
token = 4567
path = os.path.join( os.getenv("AppData"), "chrust", "svd", "test")
for lists in os.listdir(path): 
        path_file = os.path.join(path, lists) 
        print path_file
        f = open(path_file)
        line = f.readline()
        f.close()
        strlist = line.split(',')
        print strlist[0]
        #print line
        token_to_str = "%d" % token
        if (cmp(strlist[0],token_to_str) == 0):
            os.remove(path_file)
            #pass
