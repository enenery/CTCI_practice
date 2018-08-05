from operator import itemgetter, attrgetter

class Person:
	def __init__(self, name, id, location):
		self.name = name
		self.id = id
		self.location = location

#given a list of first names and location, return a list of first names who live in the location
#the output list should be in descending order by the count and ascending order by first name
def get_people_by_location(people, location):
	found = {}
	seen = {}
	for person in people:
		if seen.get(person.id, 0) == 0 and person.location == location:
			seen[person.id] = 1
			found[person.name] = found.get(person.name, 0) + 1

	print(found)
	sorted_people = sorted(found.items(), key=itemgetter(0))
	sorted_people = sorted(sorted_people, key=itemgetter(1), reverse=True)
	print(sorted_people)

def sort_list_ascending(names):
	sorted_names = sorted(names)
	print(sorted_names)

def sort_list_descending(names):
	sorted_names = sorted(names, reverse=True)
	print(sorted_names)


people = [Person("Sarah", 103, "Hawaii"), Person("Leo", 104, "Texas"),
		Person("Sarah", 130, "Hawaii"), Person("Leo", 101, "Texas"), 
		Person("Sarah", 104, "Hawaii"), Person("Leo", 106, "Hawaii"), 
		Person("Katie", 113, "Hawaii"), Person("Leo", 133, "Texas"),
		Person("Katie", 112, "Hawaii"), Person("Ingrid", 188, "Texas"), 
		Person("Samantha", 204, "Hawaii"), Person("Charlot", 136, "Hawaii"),  ]
location = "Hawaii"
get_people_by_location(people, location)

names = ["Lisa", "Kate", "Amy", "Hannah", "Stephanie", "Susanna", "Lauren", "Kelly"]
#sort_list_ascending(names)
#sort_list_descending(names)