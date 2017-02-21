from googleplaces import GooglePlaces, types, lang
from PIL import Image
import cStringIO as StringIO

KEY = 'AIzaSyCvsG3KllUIgy198K5evyB90ITHeKITM-8'

google_places = GooglePlaces(KEY)

query_result = google_places.nearby_search(
	location='Boulder, Colorado', keyword='University',
	radius=20000, types=[types.TYPE_UNIVERSITY])
	
for place in query_result.places:
	print "\n\n"
	print place.name
	print place.geo_location
	print place.place_id
	
	for photo in place.photos:
		photo.get(maxheight=500, maxwidth = 500)
		
		photo.mimetype
		photo.url
		photo.filename
		photo.data
		
		stream=StringIO.StringIO(photo.data)
		img = Image.open(stream)
		img.show()


