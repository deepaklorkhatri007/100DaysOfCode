try:
    with open('file.txt') as myFile:
        file_data = myFile.read()
    print(file_data)

except FileNotFoundError:
    print ('The file you are looking for is not found!')
except PermissionError:
    print ('This is not allowed.')
except Exception as err:
    print('Some other error occured : ', str(err))