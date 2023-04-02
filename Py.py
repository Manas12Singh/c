import random

class Enquire():
    def __init__(self):
        self.sb = 0
        self.cb = 0
        self.universalsavingsaccount=0
        self.universalcurrentaccount= 0
        self.name = ""
        self.address = ""

    def accountopen(self):
        a = input("Which type of account you want to create: (For savings account press: s and for current account press c): ")
        if a == "s":
            self.name = input('Enter your name: ')
            self.address = input('Enter your address: ')
            self.universalsavingsaccount = random.randint(10000000000, 99999999999)
            print('Your account number is:', self.universalsavingsaccount)
            savingfile = open("D:{}.txt".format(self.universalsavingsaccount), "w+")
            savingfile.write("Account Holder Name: {}\nAddress: {}\nAccount Type: Savings\nAccount Number: {}\n".format(self.name, self.address, self.universalsavingsaccount))
            savingfile.close()
        elif a == "c":
            self.name = input('Enter your name: ')
            self.address = input('Enter your address: ')
            self.universalcurrentaccount = random.randint(10000000000, 99999999999)
            print('Your account number is:', self.universalcurrentaccount)
            currentfile = open("D:{}.txt".format(self.universalcurrentaccount), "w+")
            currentfile.write("Account Holder Name: {}\nAddress: {}\nAccount Type: Current\nAccount Number: {}\n".format(self.name, self.address, self.universalcurrentaccount))
            currentfile.close()

    def deposit(self):
        accounttype = input('Enter the type of account you have (Savings or Current): ')
        if accounttype.lower() == "savings":
            tempsavingaccno = int(input('Enter your account number: '))
            if self.universalsavingsaccount == tempsavingaccno:
                a = int(input('Enter the amount you want to deposit: '))
                self.sb += a
                print('Your balance is:', self.sb)
                savingfile = open("D:{}.txt".format(universalsavingsaccount), "a")
                savingfile.write("Deposited: {}\n".format(a))
                savingfile.close()
            else:
                print('Wrong account number')
        elif accounttype.lower() == 'current':
            tempcurrentaccno = int(input('Enter your account number: '))
            if self.universalcurrentaccount == tempcurrentaccno:
                b = int(input('Enter the amount you want to deposit: '))
                self.cb += b
                print('Your balance is', self.cb)
                currentfile = open("D:{}.txt".format(universalcurrentaccount), "a")
                currentfile.write("Deposited: {}\n".format(b))
                currentfile.close()
            else:
                print('Wrong account number')

    def withdrawl(self):
        accounttype = input('Enter the type of account you have (Savings or Current): ')
        if accounttype.lower() == "savings":
            sacno = int(input('Enter the account number: '))
            if sacno == self.universalsavingsaccount:
                a = int(input('Enter the amount you want to withdraw: '))
                if a > self.sb:
                    print('Balance less than the balance left')
                else:
                    self.sb = self.sb - a
                    print('{} ruppees withdrawed'.format(a))
                    print("Your balance left is:", self.sb)
                    savingfile = open("D:{}.txt".format(universalsavingsaccount), "a")
                    savingfile.write('Withdrawed:{}'.format(a))
                    savingfile.close()
        elif accounttype.lower()=='current':
            tempcurrentaccno = int(input('Enter the account number: '))
            if tempcurrentaccno == self.universalcurrentaccount:
                a = int(input('Enter the amount you want to withdraw: '))
                if a > self.sb:
                    print('Balance less than the balance left')
                else:
                    self.sb = self.sb - a
                    print('{} ruppees withdrawed'.format(a))
                    print("Your balance left is:", self.sb)
                    savingfile = open("D:{}.txt".format(universalcurrentaccount), "a")
                    savingfile.write('Withdrawed:{}'.format(a))
                    savingfile.close()
def __init__(self):
        global c
        global b
        a=input('Do you have a account(Yes or No):')
        if a=="Yes":
            print("What services do you want to use(Deposit,Withdrawl,Customer support):")
            b=input('Please type:')
        elif a=="No":
            print("Do you want to open an account?(Yes or No):")
            c=input("Please type(Yes or no):")
            if c=="No":
                print("Never come back again to our bank")
