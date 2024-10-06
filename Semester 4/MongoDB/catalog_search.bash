# Question: Aggregation pipeline to illustrate text search on catalog data
# File: catalog_data.json

db.catalog.aggregate([
    { $match: { $text: { $search: "electronics" } } },
    { $project: { name: 1, description: 1, _id: 0 } },
    { $limit: 5 }
])
