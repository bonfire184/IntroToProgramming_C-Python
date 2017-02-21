def CheckSafeLead(pointsAhead, possesion, remainingTime):
	pointsAhead -= 3
	if (possesion):
		pointsAhead += .5
		
	else:
		pointsAhead -= .5
		if pointsAhead < 0:
			pointsAhead = 0
			
	squared = pointsAhead*pointsAhead
	
	if squared > remainingTime:
		print ("Team has a safe lead.")
		return True
		
	else:
		print ("Team does not have a safe lead.")
		return False
		
CheckSafeLead(4, True, 45)
CheckSafeLead(5, False, 6)
CheckSafeLead(-1, True, 15)
