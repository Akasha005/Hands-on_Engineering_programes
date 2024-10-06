# Question: Select certain fields and ignore others
# File: employee_data.json
db.collection.find({}, { name: 1, age: 1, _id: 0 })
# Question: Display the first 5 documents
# File: employee_data.json
db.collection.find().limit(5)
