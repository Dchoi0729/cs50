import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime

from helpers import apology, login_required, lookup, usd

# export API_KEY=pk_01c5fa2829cb450e91de45efa0669518
# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    cash = db.select("SELECT cash FROM users")

    # "SELECT symbol, SUM(shares) FROM transactions WHERE user_id=? GROUP BY symbol", user_id

    return render_template("index.html", cash=value(cash))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":

        # If user didn't provide a symbol
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("Missing Symbol")

        # If provided symbol is not valid
        data = lookup(symbol)
        if not data:
            return apology("Invalid Symbol")

        # If user didn't provide a share number
        if not request.form.get("shares"):
            return apology("Missing shares")

        # If user inputted a negative amount of shares
        shares = int(request.form.get("shares"))
        if shares < 0:
            return apology("Negative shares")

        # Check if user has enough money
        desired = data["price"] * shares
        balance = db.execute("SELECT cash FROM users WHERE id=?", session["user_id"])[0]["cash"]
        if desired > balance:
            return apology("Not enough money")

        # Get current time
        now = datetime.now()
        date_time = now.strftime("%Y-%m-%d %H:%M:%S")

        # Record purchase to database (transactions table)
        db.execute("INSERT INTO transactions(user_id,symbol,type,shares,total_price,time) Values (?,?,?,?,?)", session["user_id"], symbol, "buy", shares, desired, date_time)

        # Change remaining balance (users table)
        db.execute("UPDATE users SET cash = ? WHERE id = ?", balance - desired, session["user_id"])

        flash('Bought!')
        return redirect("/")

    if request.method == "GET":
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]
        session["username"] = request.form.get("username")

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # User sent a post request with symbol
    if request.method == "POST":
        data = lookup(request.form.get("symbol"))
        return render_template("quoted.html",name=data["name"],symbol=data["symbol"],price=data["price"])

    # User clicked on quote tab on navbar
    if request.method == "GET":
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # If user sent a register post request
    if request.method == "POST":

        # Check to see if username was provided
        user = request.form.get("username")
        if not user:
            flash("Please provide a username")
            return redirect("/register")

        # Check to see if username already exists in database
        db_user = db.execute("SELECT * FROM users WHERE username=?",user)
        if db_user:
            flash("Username already exists")
            return redirect("/register")

        # Check to see if password and confirmation password was provided
        pwd = request.form.get("password")
        pwd_confirm = request.form.get("confirmation")
        if not pwd or not pwd_confirm:
            flash("Please provide a password")
            return redirect("/register")

        # Check to see if password and confirmation password are equal
        if pwd != pwd_confirm:
            flash("Password and confirmation password do not match")
            return redirect("/register")

        # Adds username and password to database
        db.execute("INSERT INTO users(username,hash) VALUES (?,?)", user, generate_password_hash(pwd))

        # Remember which user has logged in
        rows = db.execute("SELECT * FROM users WHERE username = ?", user)
        session["user_id"] = rows[0]["id"]

        flash('Registered!')
        return redirect("/")

    # If user wants to register
    if request.method == "GET":
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
