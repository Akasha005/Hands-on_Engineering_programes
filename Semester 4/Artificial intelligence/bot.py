#Build a bot which provides all the information related to text in search box
# Make sure to install the Wikipedia library with: pip install wikipedia
import wikipedia

# Function to search Wikipedia
def search_wikipedia(query):
    try:
        # Search Wikipedia for the given query
        page = wikipedia.page(query)
        # Extract summary and URL
        summary = page.summary
        url = page.url
        return {"summary": summary, "url": url}
    except wikipedia.exceptions.PageError:
        return {"error": "Page not found."}
    except wikipedia.exceptions.DisambiguationError as e:
        # If there are multiple results, return them as suggestions
        return {"suggestions": e.options}

# Main function for user interaction
def main():
    print("Welcome to the Wikipedia Bot!")
    while True:
        query = input("Enter your search query (or type 'exit' to quit): ")
        if query.lower() == 'exit':
            print("Exiting...")
            break
        # Search Wikipedia for the query
        result = search_wikipedia(query)
        # Print the result
        if "summary" in result:
            print("Summary:", result["summary"])
            print("URL:", result["url"])
        elif "suggestions" in result:
            print("Did you mean:")
            for suggestion in result["suggestions"]:
                print("-", suggestion)
        elif "error" in result:
            print("Error:", result["error"])

# Run the main function
if __name__ == "__main__":
    main()
