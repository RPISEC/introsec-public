from flask import Flask, render_template, make_response

#Create Flask app instance
app = Flask(__name__)

#Configure server name for url_for to work in templates
app.config['SERVER_NAME'] = '127.0.0.1:5200'

#Home route
@app.route("/")
def home():
    return render_template("index.html")

#Cat listings page
@app.route("/listing")
def listing():
    return render_template("listing.html")

#About us page
@app.route("/about")
def about():
    return render_template("about.html")

#About us page
@app.route("/robots.txt")
def robots():
    response = make_response(render_template("robots.txt"))
    response.headers['content-type'] = 'text/plain'
    return response

#Cat listings page
@app.route("/login")
def login():
    return render_template("login.html")

#Super duper secret flag
@app.route("/evil_backend_page_for_the_hackers_where_we_store_our_data")
def flag():
    return "RPISEC{local_robots}"

#Error handling example
@app.errorhandler(404)
def page_not_found(e):
    return "<h1>404 - Page Not Found</h1>", 404

#Run the app
if __name__ == "__main__":
    #debug=True enables auto-reload on code changes
    #app.run(debug=True)
    app.run(host='127.0.0.1', port=5200, debug=False, use_reloader=False) #For Jupiter
