import os
import json
import csv


def process_folders():
    with open('response.csv', 'w', newline='') as csvfile:
        fieldnames = ['folderName', 'request content', 'response content']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()

        for folder_name in range(1, 213):
            folder_path = str(folder_name)
            if os.path.exists(folder_path) and os.path.isdir(folder_path):
                request_path = os.path.join(folder_path, 'request.json')
                response_path = os.path.join(folder_path, 'response.json')

                if os.path.exists(request_path) and os.path.exists(response_path):
                    request_content = read_json_file(request_path)
                    response_content = read_json_file(response_path)

                    writer.writerow({
                        'request content': json.dumps(request_content),
                        'response content': json.dumps(response_content)
                    })


def read_json_file(file_path):
    with open(file_path, 'r') as file:
        return json.load(file)


if __name__ == "__main__":
    process_folders()
