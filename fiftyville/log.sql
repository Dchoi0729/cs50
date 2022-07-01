-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Mystery occured on July 28, 2021 on Humphrey Street.

.schema

-- First examine crime scene reports for July 28, 2021 on Humphrey Street
SELECT description
  FROM crime_scene_reports
 WHERE year = 2021 AND month = 7 AND day = 28
   AND street = "Humphrey Street";


-- Theft detail: 10:15am at the Humphrey Street bakery. Examine interviews looking out for that time
SELECT name, transcript
  FROM interviews
 WHERE year = 2021 AND month = 7 AND day = 28;


-- Ruth: Criminal left the bakery 10:15 ~ 10:25am in a car
SELECT people.name
  FROM people
       JOIN bakery_security_logs AS bsl
         ON bsl.license_plate = people.license_plate
 WHERE bsl.year = 2021 AND month = 7 AND day = 28 AND hour = 10
   AND NOT(minute < 15) AND NOT (minute > 25)
   AND activity = "exit";
-- Got a list of potential suspects


-- Eugene: Thief withrew money from the atm on Leggett street earlier that day
SELECT DISTINCT(people.name)
  FROM bank_accounts
       JOIN atm_transactions AS atm ON bank_accounts.account_number = atm.account_number
       JOIN people ON bank_accounts.person_id = people.id
 WHERE atm.transaction_type = "withdraw"
   AND atm.year = 2021 AND atm.month = 7 AND atm.day = 28
   AND atm.atm_location = "Leggett Street";
--Got another list of potential suspects


-- Raymond: As thief left bakery, called someone for less than a min.
SELECT people.name
  FROM people
       JOIN phone_calls AS pc ON pc.caller = people.phone_number
 WHERE pc.duration < 60
   AND pc.year = 2021 AND pc.month = 7 AND pc.day = 28;
-- Got another list of potential suspects


-- Raymond: Take earliest flight out of Fiftyville on 7/29
SELECT people.name
  FROM passengers JOIN people ON people.passport_number = passengers.passport_number
 WHERE passengers.flight_id =
       (SELECT flights.id
          FROM airports
             JOIN flights ON airports.id = origin_airport_id
         WHERE airports.city = "Fiftyville"
           AND flights.year = 2021 AND month = 7 AND day = 29
         ORDER BY hour, minute
         LIMIT 1);

/*
             crime scene reports
id | year | month | day | street | description

                 interviews
id | name | year | month | day | transcript

                                atm_transcations
id | account_number | year | month | day | atm_location | transaction_type | amount

              bank accounts
account_number | person_id | creation_year

              airports
id | abbreviation | full_name | city

                                    flights
id | origin_airport_id | destination_airport_id | year | month | day | hour | minute

            passengers
fight_id | passport number | seat

                    phone calls
id | caller | receiver | year | month | day | duration

                        people
id | name | phone_number | pasport_number | license_plate

                       bakery_security_logs
id | year | month | day | hour | minute | activity | license_plate

/*