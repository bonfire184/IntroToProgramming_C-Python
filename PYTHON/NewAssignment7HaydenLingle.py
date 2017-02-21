list1 = "Be kind to your <noun1>-footed <plural noun1>, or a duck maybe somebody's <noun2>."
list2 = "It was the <adjective1> of <noun1>, it was the <adjective2> of <noun2>."
list3 = "<plural noun1>? I don't have to show you any <adjective1> <plural noun2>!"
list4 = "My <relative1> always said <noun1> was like a box of <noun2>. You never know what you're gonna get."
list5 = "One <time of day1>, I <verb1> a <noun1> in my pajamas. How he got in my pajamas, I don't know."
listTemplates = [list1, list2, list3, list4, list5]

'''for number in listTemplates:
	print number
'''	

choice = 'y'
#print choice
while (choice != 'n'):
	print "Do you want to play a game? (y) or (n)"
	choice = raw_input('')
	if (choice == 'y'):
		import random
		randnum = random.randrange(0,5)
		if(randnum == 0):
			#1
			userinput = raw_input('Enter a noun: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<noun1>", userinput)
			#2
			userinput = raw_input('Enter a plural noun: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<plural noun1>", userinput)
			#3
			userinput = raw_input('Enter another noun: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<noun2>", userinput)
			#4
			print listTemplates[randnum]
			
		elif(randnum == 1):
			#1
			userinput = raw_input('Enter an adjective: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<adjective1>", userinput)
			#2
			userinput = raw_input('Enter a noun: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<noun1>", userinput)
			#3
			userinput = raw_input('Enter another adjective: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<adjective2>", userinput)
			#4
			userinput = raw_input('Enter another noun: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<noun2>", userinput)
			
			print listTemplates[randnum]
		elif(randnum == 2):
			#1
			userinput = raw_input('Enter a plural noun: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<plural noun1>", userinput)
			#2
			userinput = raw_input('Enter an adjective: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<adjective1>", userinput)
			#3
			userinput = raw_input('Enter another plural noun: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<plural noun2>", userinput)
			#4		
			print listTemplates[randnum]
		elif(randnum == 3):
			#1
			userinput = raw_input('Enter a relative: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<relative1>", userinput)
			#2
			userinput = raw_input('Enter a noun: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<noun1>", userinput)
			#3
			userinput = raw_input('Enter another noun: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<noun2>", userinput)
			#4		
			print listTemplates[randnum]
		elif(randnum == 4):
			#1
			userinput = raw_input('Enter a time of day: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<time of day1>", userinput)
			#2
			userinput = raw_input('Enter a verb: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<verb1>", userinput)
			#3
			userinput = raw_input('Enter a noun: ')
			listTemplates[randnum] = listTemplates[randnum].replace("<noun1>", userinput)
			#4
			print listTemplates[randnum]
		
print "good bye"


