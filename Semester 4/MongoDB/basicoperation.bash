# Question: Illustration of Where Clause, AND, OR operations
# File: employee_data.json
db.collection.find({
    $or: [
        { age: { $gt: 25 } },   # age greater than 25
        { status: "active" }    # or status is 'active'
    ]
})
