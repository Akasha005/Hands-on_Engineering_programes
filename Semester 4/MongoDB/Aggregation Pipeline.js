// Question: Execute Aggregation Pipeline using $match, $group, $sort, $project, $skip
// File: employee_data.json

db.collection.aggregate([
    { $match: { status: "active" } },   // Match active status
    { $group: { _id: "$department", totalSalary: { $sum: "$salary" } } },  // Group by department
    { $sort: { totalSalary: -1 } },  // Sort by total salary in descending order
    { $project: { department: 1, totalSalary: 1, _id: 0 } },  // Project fields
    { $skip: 1 }  // Skip the first result
])
