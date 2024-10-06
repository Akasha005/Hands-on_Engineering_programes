# Question: Insert, Query, Update, Delete, Projection commands
# File: employee_data.json

# Insert command
db.collection.insertOne({
    name: "John",
    age: 30,
    status: "active"
})

# Query command
db.collection.find({ name: "John" })

# Update command
db.collection.updateOne({ name: "John" }, { $set: { age: 35 } })

# Delete command
db.collection.deleteOne({ name: "John" })

# Projection command
db.collection.find({}, { name: 1, age: 1, _id: 0 })
