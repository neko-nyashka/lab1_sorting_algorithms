import random
from datetime import datetime, timedelta
import csv

def generate_flight_data(num_flights=10):
    airlines = ["Aeroflot", "S7 Airlines", "Ural Airlines", "Emirates", "Qatar Airways", "Lufthansa", "British Airways"]
    flights = []

    for _ in range(num_flights):
        flight_number = f"FV{random.randint(1000, 9999)}"
        airline = random.choice(airlines)

        today = datetime.today()
        random_days = random.randint(0, 365)  
        arrival_date = today + timedelta(days=random_days)
        arrival_date_str = arrival_date.strftime("%Y-%m-%d")

        random_hour = random.randint(0, 23)
        random_minute = random.randint(0, 59)
        arrival_time = f"{random_hour:02d}:{random_minute:02d}"

        passengers = random.randint(50, 500)

        flights.append([
            flight_number,
            airline,
            arrival_date_str,
            arrival_time,
            passengers
        ])

    return flights

def save_to_csv(data, filename):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerows(data)


big_dataset = generate_flight_data(100000)

sizes = [100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 75000]

for i, size in enumerate(sizes, 1):
    subset = big_dataset[:size]
    save_to_csv(subset, f"{size}.csv")
    print(f"Generated dataset {i} with {size} entries")