import os
import datetime

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

@app.route("/", methods=["GET","POST"])
def index(error_status=0):
    if request.method == "POST":
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")
        error = 1

        # User validation, has to give input for all three
        if name and validate_birthday(month,day):
            db.execute("INSERT INTO birthdays(name,month,day) VALUES (?,?,?)", name, month, day)
            error = 0

        return redirect(url_for("/", error_status = error))

    else:
        birthday_list = db.execute("SELECT * FROM birthdays")

        return render_template("index.html", birthdays=birthday_list, err = error_status)


@app.route("/delete", methods=["POST"])
def delete():
    id = request.form.get("id")
    db.execute("DELETE FROM birthdays WHERE id=?",id)
    return redirect("/")


# Validates birthday
def validate_birthday(month, day):
    try:
        date = datetime.datetime(2024,int(month),int(day))
    except:
        return False
    return True
