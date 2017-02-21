def CreateDictionary(filename):
	translation = {} #create a dictionary called translation
	
	File = open(filename, 'r') #opening a file to read it
	
	info = File.readlines()
	
	for line in info:
		line = line.strip()# goes line by line and removes extra spaces
		info = line.split(",")# splits the data into lines based on each comma the code comes by
		
		translation[info[0]] = info[1].strip()#creates structure of dictionary
	File.close()
	
	return translation
	
	
def main():
	
	############### Converted the CSV file to a .txt and then ran the command "perl -pi -e 's/\r/\n/g' textToEnglish.txt"###################
	
	translation = CreateDictionary("textToEnglish.txt")#new variable equal to function Create Dictionary sent the text file
	Input1 = "y"
	while Input1 != "quit":
	
		Input1 = raw_input("Keep searching for abbrevitations? y/quit: ")#prompts the user to see if they'd like to keep searching
		
		if Input1 == "y":
			
			
			input = raw_input("Type an abbreviation: ")
			
			#input.search(" ")
			t = input.split(" ")#splits the line into each section seperated by spaces
			
			
			for x in t: #iterates through the list t and checks to see if each word is in the dictionary
				if x in translation:
					print translation[x], #if it is in the dictionary, it prints translation
				else:
					print "NF",
			print ""
	
	
	

if __name__ == "__main__":
	main()
