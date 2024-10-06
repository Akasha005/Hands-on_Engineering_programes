# Question: Execute Aggregation operations ($avg, $min, $max, $sum, $push, $addToSet)
# File: employee_data.json

db.collection.aggregate([
    {
        $group: {
            _id: "$status",
            avgAge: { $avg: "$age" },
            minAge: { $min: "$age" },
            maxAge: { $max: "$age" },
            totalSalary: { $sum: "$salary" },
            allNames: { $push: "$name" },
            uniqueNames: { $addToSet: "$name" }
        }
    }
])
