# Question: Develop a query to demonstrate text search using catalog data
# File: catalog_data.json

# Create a text index on the description field
db.catalog.createIndex({ description: "text" })

# Perform text search for a specific word
db.catalog.find({ $text: { $search: "electronics" } })
# Question: Exclude documents with certain words
# File: catalog_data.json

# Exclude documents containing certain words (e.g., 'discount')
db.catalog.find({
    $text: { $search: "electronics -discount" }
})
