from flask import Flask, redirect, render_template, request, url_for, make_response

#Create Flask app instance
app = Flask(__name__)

#Configure server name for url_for to work in templates
app.config['SERVER_NAME'] = '127.0.0.1:5300'

#Fake user database
USERS = {
    "cookie_monster": "yum_yum_yum",
}

def renderWithCookies(template_rendered: str):
    resp = make_response(template_rendered)
    print(request.cookies.get("isAdmin"))
    if request.cookies.get("isAdmin") == None:
        resp.set_cookie("isAdmin", "0")
    return resp

#Home route
@app.route("/")
def home():
    return renderWithCookies(render_template("index.html"))

#Cat listings page
@app.route("/listing")
def listing():
    return renderWithCookies(render_template("listing.html"))

#About us page
@app.route("/about")
def about():
    return renderWithCookies(render_template("about.html"))


#Login page
@app.route("/login", methods=["GET", "POST"])
def login():
    error = ""
    if request.method == "GET":
        return renderWithCookies(render_template("login.html", error=error))
    #Otherwise POST Request
    username = request.form.get("user")
    password = request.form.get("pass")

    if username in USERS and USERS[username] == password and request.cookies.get("isAdmin") == "1":
        return redirect(url_for("flag"))
    else:
        if request.cookies.get("isAdmin") != "1":
            error = "You're not an admin!!!! Silly goose only admins can schudule at THIS cat cafe"
        else:
            error = "There was an error logging in. Please try again. (You aren't cookie monster)"
        return renderWithCookies(render_template("login.html", error=error))

#Super duper secret flag
@app.route("/super_secret_flag.txt")
def flag():
    return "RPISEC{local_cookies}"

#Error handling example
@app.errorhandler(404)
def page_not_found(e):
    return "<h1>404 - Page Not Found</h1>", 404

#Run the app
if __name__ == "__main__":
    #debug=True enables auto-reload on code changes
    #app.run(debug=True)
    app.run(host='127.0.0.1', port=5300, debug=False, use_reloader=False) #For Jupiter
