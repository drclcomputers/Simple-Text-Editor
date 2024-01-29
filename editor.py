from os import name, system

action=''

while(action!='e'):
    data=[]
    text=''
    print("Simple Text Editor")

    action=input('Write (w), Open (o), Exit (e): ')

    if(action=='w'):
        while(text!="exit"):
            text=input()
            if text!='exit':
                data.append(text)
        filename=input("Input filename: ")
        if(filename!=""):
            with open(filename, 'w') as f:
                for i in range(len(data)):
                    f.write(data[i]+"\n")

    if(action=='o'):
        filename=input("Input filename: ")
        try:
            line=''
            while(line!='e'):
                with open(filename, 'r') as f:
                    data=f.readlines()
                    for i in range(1, len(data)+1):
                        if i==len(data):
                            print(i, str(data[i-1]))
                        else:
                            print(i, str(data[i-1])[:-1])
                    line=input("What line to edit (e - exit): ")
                    if line=='e':
                        pass
                    else:
                        line=int(line)-1
                        if line+1>len(data):
                            x=len(data)
                            for i in range(line+1-x):
                                data.append("\n")
                        text=input("Rewrite (skip - doesn't edit the line): ")
                        if(text!='skip'):
                            data[line]=text+'\n'
                            with open(filename, 'w') as a:  
                                for i in range(len(data)):
                                    a.write(data[i])
                                a.close()
                    if name=='nt':
                        system("cls")
                    else:
                        system("clear")
        except:
            print("File appears to not exist.")
            a=input("Try again (a) or exit (e): ")
            if(a=='a'):
                pass
            else:
                action='e'

    if name=='nt':
        system("cls")
    else:
        system("clear")
        
        