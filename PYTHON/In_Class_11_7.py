#strings
#lists
#for loops
#conditionals
#functions

#FUNCTIONS
#write a functions that prints a string
def myFunction(myStr): #defining function w/myStr as argument
	print myStr
	print type(myStr)
 
 
#strings
myStr = "Four score and seven years ago"
print myStr

f = myStr.find("seven") #index of seven
print f

c = myStr.count("s") #number of instances of the letter s
print c

myStr = myStr.replace("seven", "many")#replace seven with many
print myStr

#lists
listInt = [100, 98, 80, 70]
listStr = ["programming", "chemistry", "math"]
listMixed = ["programming", "chemistry", 1, 2, 3]#strings and integers
#lists can be all different types unlike c++ array

listLists = [listInt, listStr, listMixed]
#list of a fuckkinnn listttt 
print listLists

print listLists [0][0]

#for loops
#for <item> in <collection>
print "\nFor Loop Printing From listInt"
for item in listInt:
	print item
	
for y in listLists:
	print y

numbers = range(1, 6)
print numbers
for x in range(len(listInt)-1, -1, -1):#creates variable x, iterates it beginning at 0 until the length of listInt array, prints value at index x from array
	print listInt[x]
	
for x in reversed(range(0, len(listInt))):#ANOTHA way to do it
	print listInt[x]


s = "string"
y = 5
print s + "test" + str(y)

for letter in myStr:#loops through index and posts letter at index
	print letter
	
for letter in range(0, len(myStr)): #DOES THE SAME THING
	print myStr[letter]

#CONDITIONALS
if y<5:
	print "y<5"
else:
	print "y not < 5"

y+=1
print y

#Calling string
myFunction("hello")

def findItem(listToSearch, valueToSearchFor):
	#loop through list
	for x in range(0, len(listToSearch)):
		if listToSearch[x] == valueToSearchFor:
			index = x
	return x
	
index = findItem(listStr, "chemistry")
print index


	
