# Question: Find all listings with listing_url, name, address, host_picture_url that have a host with a picture
# File: listings_reviews.json

db.listingsAndReviews.find({
    host_picture_url: { $exists: true, $ne: null }
}, { listing_url: 1, name: 1, address: 1, host_picture_url: 1, _id: 0 })
# Question: Query to display review summaries from the E-commerce collection
# File: ecommerce_data.json

db.ecommerce.find({}, { review_summary: 1, _id: 0 })
