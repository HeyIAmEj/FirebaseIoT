import csv
import json


def csv_to_json(csv_file):
    result = []

    with open(csv_file, 'r') as file:
        reader = csv.reader(file, delimiter='\t')

        for row in reader:
            request_data = json.loads(row[1])
            response_data = json.loads(row[2])

            entry = {
                "request": request_data,
                "response": response_data
            }

            result.append(entry)

    return result


# Replace 'your_input_file.csv' with the actual path to your CSV file
csv_file_path = 'response.csv'

# Replace 'output.json' with the desired output file name
json_output_path = 'output.json'

json_result = csv_to_json(csv_file_path)

with open(json_output_path, 'w') as json_file:
    json.dump(json_result, json_file, indent=2)

print(f"Conversion successful. JSON output saved to '{json_output_path}'")
