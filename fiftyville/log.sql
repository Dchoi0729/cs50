-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Mystery occured on July 28, 2021 on Humphrey Street.

-- First examine crime scene reports for July 28, 2021 on Humphrey Street
SELECT description
  FROM crime_scene_reports
 WHERE year = 2021 AND month = 7 AND day = 28
   AND street = "Humphrey Street";

-- Theft detail: 10:15am at the Humphrey Street bakery. Examine interviews looking out for that time
SELECT name, transcript
  FROM interviews
 WHERE year = 2021 AND month = 7 AND day = 28;

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