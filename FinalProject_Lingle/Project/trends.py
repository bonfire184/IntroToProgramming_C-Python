import sys
import json
from tweet import Tweet
from state import load_states
from country import Country
from parse import load_sentiments
from colors import get_sentiment_color
from geo import GeoPosition

class SentimentAnalysis:
    def __init__(self):
        self.sentiments = load_sentiments()
        self.states = load_states()
    def showCountry(self):
        self.usa = Country(self.states, 1200)


if __name__ == "__main__":
    if len(sys.argv) > 1:
        query = sys.argv[1:] #This will take as many querys as the user enters
        print query
    else:
        print "error"
        
    sa = SentimentAnalysis()    

    TweetList = []
    query = ['Hayden']
    
    listOfFiles = ['./tweets_with_time.json', './tweets_with_time_2.json', './tweets_with_time_3.json', './tweets_with_time_4.json'] #The Program will open these files
    
    combinedTwitterFiles = " "
	
    for TweetFile in listOfFiles:
		combinedTwitterFiles += open(TweetFile, 'r').read() + '\n'
		
    print "Combining To New Json..."
    NewFile = open('./NewCombinedTweetData.json', 'w')#Opens Json file and writes the new combined files to the Json file for re-opening below (line 43)
    NewFile.write(combinedTwitterFiles)
    NewFile.close()
    print "Finished Combining."	
	
    tweets = open('./NewCombinedTweetData.json', 'r')#Opens new Json File that is a combination of the 4 with time stamps
    
    for line in tweets:		
		try:
			tweetData = json.loads(line)
		except ValueError:
			pass
		for element in query:#if there is no error in reading the line, it goes through each part of the query and checks if that element is in the tweet, if it is, a list of Tweet data gets appended with a new Tweet object that includes text, a null timestamp, and a geolocation
			if (element in tweetData['text']):
				TweetList.append(Tweet(tweetData['text'], "null", GeoPosition(tweetData['coordinates'][1], tweetData['coordinates'][0])))
				#TweetList is as list of Tweet objects, ^^above code appends a new object as long as the query elements are in the tweet text
	
    for x in TweetList:
		
		#(DEBUGGING)print "******* NEW TWEET ********"
		
		smallestDistance = 100000
		smallestDistanceState = " "
				
		for state in sa.states:
			
			distanceToState = x.position().distance(state.centroid())
					
			if distanceToState < smallestDistance:
				smallestDistance = distanceToState
				#(DEBUGGING)print "New Shortest Distance: ",
				#(DEBUGGING)print smallestDistance
				smallestDistanceState = state.abbrev()
				#(DEBUGGING)print "New Closest State: ",
				#(DEBUGGING)print smallestDistanceState		
		
		#(DEBUGGING)print "Closest State to tweet: ",
		#(DEBUGGING)print smallestDistanceState		
						
		splitMessage = x.message().split()
		
		for word in splitMessage:
			if word in sa.sentiments:
				sentimentScore = sa.sentiments[word]
				#(DEBUGGING)print "Sentiment Score: ",
				#(DEBUGGING)print sentimentScore
				
				#use previously found closest state abbrev and cross check against state list then append sentimentScore to the list of sentiments for that state
				for state in sa.states:
					if state.abbrev() == smallestDistanceState:
						state.addToListOfSentiments(sentimentScore)					
    sa.showCountry()
    
    print "----States With Sentiments About Your Query----"
    for state in sa.states:
		sentiment = state.calculateAverageSentiment()		
		if (state.findLengthSentiments() > 1):#makes sure that there were any tweets with sentiments about the query terms
			print "State: ",
			print state.abbrev(), #Prints state abbreviation code. eg. "CO"
			print ", Average: ",
			print sentiment, #calls the function inside of the state.py file that calculates the average sentiment for current state."
			print ", Color: ",
			print get_sentiment_color(sentiment)
			sa.usa.setFillColor(state.abbrev(), get_sentiment_color(state.calculateAverageSentiment()))#sends the state and the color to the setFillColor function to update the color for that state
