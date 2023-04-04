import json

#to access json file as dictionary
with open('E:\\12.json','r+') as f:
    c=json.load(f)

    #checking if a accountnumber is stored in the json file

    accountnumber=str(38)

    if accountnumber in c:
        print(c[accountnumber]["Name"])

    #check if the accountnumber is not stored in the json file and to add new data
    if accountnumber not in c:
        c[accountnumber]={'Name':'Yashpal','Address':'Garhi','Balance':23}
        f.seek(0)
        json.dump(c,f,indent=4)
    
    #update balance in json file
    if accountnumber in c:
        c[accountnumber]['Balance']+=23
        f.seek(0)
        json.dump(c,f,indent=4)