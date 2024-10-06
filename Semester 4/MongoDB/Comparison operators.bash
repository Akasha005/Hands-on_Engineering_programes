# Question: Execute query selectors (comparison, logical)
# File: employee_data.json

# Comparison selector (e.g., age greater than 30)
db.collection.find({ age: { $gt: 30 } })

# Logical selector (e.g., age > 30 and status is active)
db.collection.find({
    $and: [
        { age: { $gt: 30 } },
        { status: "active" }
    ]
})
# Question: Execute query selectors (geospatial, bitwise)
# File: location_data.json

# Geospatial selector (finding documents near coordinates)
db.collection.find({
    location: {
        $near: {
            $geometry: {
                type: "Point",
                coordinates: [ -73.9667, 40.78 ]  # Example coordinates
            }
        }
    }
})

# Bitwise selector (find documents using bitmask)
db.collection.find({ bitmask: { $bitsAllSet: 7 } })
