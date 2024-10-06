// 7.1 Create record in MongoDB
db.Employee.insertOne({
    E_id: 401,
    E_name: "Lucy",
    Age: 32,
    Salary: 65000
});

// 7.2 Read records in MongoDB
db.Employee.find();

// 7.3 Update record in MongoDB
db.Employee.updateOne(
    { E_id: 401 }, 
    { $set: { Salary: 70000 } }
);

// 7.4 Delete record in MongoDB
db.Employee.deleteOne({ E_id: 401 });
