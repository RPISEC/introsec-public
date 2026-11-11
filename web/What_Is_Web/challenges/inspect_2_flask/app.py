from flask import Flask, render_template

#Create Flask app instance
app = Flask(__name__)

#Configure server name for url_for to work in templates
app.config['SERVER_NAME'] = '127.0.0.1:5100'

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

#Login page
@app.route("/login")
def login():
    return render_template("login.html")

#Super duper secret flag
@app.route("/super_secret_flag.txt")
def flag():
    return "RPISEC{local_flag_inspect2}"

#Error handling example
@app.errorhandler(404)
def page_not_found(e):
    return "<h1>404 - Page Not Found</h1>", 404

#Run the app
if __name__ == "__main__":
    #debug=True enables auto-reload on code changes
    #app.run(debug=True)
    app.run(host='127.0.0.1', port=5100, debug=False, use_reloader=False) #For Jupiter
