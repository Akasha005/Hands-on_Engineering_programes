# Question: Demonstrate creation of indexes (unique, sparse, compound, multikey)
# File: employee_data.json

# Unique index on name
db.collection.createIndex({ name: 1 }, { unique: true })

# Sparse index on optional field (e.g., phone number)
db.collection.createIndex({ phone: 1 }, { sparse: true })

# Compound index on two fields (age and salary)
db.collection.createIndex({ age: 1, salary: -1 })

# Multikey index (if documents contain arrays)
db.collection.createIndex({ hobbies: 1 })
# Question: Demonstrate optimization of queries using indexes
# File: employee_data.json

db.collection.find({ age: { $gt: 30 } }).explain("executionStats")
