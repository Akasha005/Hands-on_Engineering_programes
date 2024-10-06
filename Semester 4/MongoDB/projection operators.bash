# Question: Demonstrate projection operators ($, $elemMatch, $slice)
# File: employee_data.json

# $elemMatch to project the first matching sub-document
db.collection.find({ "grades": { $elemMatch: { score: { $gt: 90 } } } })

# $slice to limit the number of array elements returned
db.collection.find({}, { grades: { $slice: 2 } })
