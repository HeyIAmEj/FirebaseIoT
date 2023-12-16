import os
import json


def getDataToJson():
    final_data = {}

    for folder_name in range(1, 213):
        folder_path = str(folder_name)
        if os.path.isdir(folder_path):
            request_path = os.path.join(folder_path, 'request.json')
            response_path = os.path.join(folder_path, 'response.json')

            if os.path.exists(request_path) and os.path.exists(response_path):
                with open(request_path, 'r') as request_file, open(response_path, 'r') as response_file:
                    request_data = json.load(request_file)
                    response_data = json.load(response_file)

                final_data[str(folder_name)] = {
                    'request': request_data,
                    'response': response_data
                }

    # Save the final_data to response.json
    with open('response.json', 'w') as final_file:
        json.dump(final_data, final_file, indent=2)


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


def get_data(start_key, end_key=None):
    with open('response.json', 'r') as response_file:
        data = json.load(response_file)

    if end_key is None:
        # Return data for a specific key
        return json.dumps(data.get(str(start_key), None)).replace("'", '"')
    else:
        # Return data for a range of keys
        result = {}
        for key in range(start_key, end_key + 1):
            key_str = str(key)
            if key_str in data:
                result[key_str] = data[key_str]
        return json.dumps(result).replace("'", '"')


def main():
    while True:
        print("Menu:")
        print("1 - Criar Json")
        print("2 - Criar Csv")
        print("3 - Ver X Json")
        print("4 - Ver X - Y Json")
        print("0 - Sair")

        choice = input("Escolha uma opção: ")

        if choice == '1':
            getDataToJson()
        elif choice == '2':
            process_folders()
        elif choice == '3':
            id = input("Escolha um id: ")
            result = get_data(id)
            print(result)
        elif choice == '4':
            id1 = int(input("Escolha o primeiro intervalo: "))
            id2 = int(input("Escolha o segundo intervalo: "))
            result = get_data(id1, id2)
            print(result)
        elif choice == '0':
            print("Saindo do programa. Até mais!")
            break
        else:
            print("Opção inválida. Tente novamente.")


if __name__ == "__main__":
    main()
