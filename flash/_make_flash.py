# файл _list.txt содержит имя файла и название через пробел
# имя файла не должно содержать пробелы
# название может содержать пробелы
# каждая строка должна заканчиваться ENTER
import os.path
import codecs

lines = sum(1 for line in open('_list.txt'))-1
print(lines)

temp_file = open('_list.txt', 'r', errors="ignore")
n_line = sum(1 for line in temp_file)
temp_file.close()

list_file = open("_list.txt", "r", errors="ignore")
flash_file = open('_flash.bin', 'wb')
game_len=0
fat=bytearray(10020)
offset_file = 0

for z in range(n_line):
    print('file number:',z)
    s = list_file.readline()                # читаем строку из файла
#    print(s)
    if s != '':                             # если строка пустая то пропускаем
        x1 = s.find("\n")                   # ищем позицию конца строки (enter)
        data = s[:x1]                       # отрезаем enter от строки
        x2 = s.find(" ")                    # ищем позицию пробела между именем файла и названием
        if x2 < 1:                          # пробел не найден значит нет названия игры
            file_name = data
            print(file_name)                # название будет такое же как имя файла
            game_name = file_name.ljust(15) # дополняем пробелами название игры до 15 символов
#            print(game_name)                # название будет такое же как имя файла
        else:                               # название есть
            file_name = data[: x2]          # выделяем имя файла
            print(file_name)
            game_name = data[x2+1:]         # выделяем название игры
            game_name = game_name.ljust(15) # дополняем название пробелами до 15
#	    print(game_name)
        s=''
        filesize = os.path.getsize(file_name)

        g = game_name.encode('cp866')
#        print(g)
        for i in range(15):                 # преобразуем каждый символ в шестандцетеричный код
            b=g[i: i+1]
#            print(b)
            if   b==b'\x80': b=0x80 # А
            elif b==b'\x81': b=0x81 # Б
            elif b==b'\x82': b=0x82 # В
            elif b==b'\x83': b=0x83 # Г
            elif b==b'\x84': b=0x84 # Д
            elif b==b'\x85': b=0x85 # Е
            elif b==b'\xf0': b=0xf0 # Ё
            elif b==b'\x86': b=0x86 # Ж
            elif b==b'\x87': b=0x87 # З
            elif b==b'\x88': b=0x88 # И
            elif b==b'\x89': b=0x89 # Й
            elif b==b'\x8a': b=0x8a # К
            elif b==b'\x8b': b=0x8b # Л
            elif b==b'\x8c': b=0x8c # М
            elif b==b'\x8d': b=0x8d # Н
            elif b==b'\x8e': b=0x8e # О
            elif b==b'\x8f': b=0x8f # П
            elif b==b'\x90': b=0x90 # Р
            elif b==b'\x91': b=0x91 # С
            elif b==b'\x92': b=0x92 # Т
            elif b==b'\x93': b=0x93 # У
            elif b==b'\x94': b=0x94 # Ф
            elif b==b'\x95': b=0x95 # Х
            elif b==b'\x96': b=0x96 # Ц
            elif b==b'\x97': b=0x97 # Ч
            elif b==b'\x98': b=0x98 # Ш
            elif b==b'\x99': b=0x99 # Щ
            elif b==b'\x9a': b=0x9a # Ъ
            elif b==b'\x9b': b=0x9b # Ы
            elif b==b'\x9c': b=0x9c # Ь
            elif b==b'\x9d': b=0x9d # Э
            elif b==b'\x9e': b=0x9e # Ю
            elif b==b'\x9f': b=0x9f # Я
            elif b==b'\xa0': b=0xa0 # а
            elif b==b'\xa1': b=0xa1 # б
            elif b==b'\xa2': b=0xa2 # в
            elif b==b'\xa3': b=0xa3 # г
            elif b==b'\xa4': b=0xa4 # д
            elif b==b'\xa5': b=0xa5 # е
            elif b==b'\xf1': b=0xf1 # ё
            elif b==b'\xa6': b=0xa6 #  ж
            elif b==b'\xa7': b=0xa7 # з
            elif b==b'\xa8': b=0xa8 # и
            elif b==b'\xa9': b=0xa9 # й
            elif b==b'\xaa': b=0xaa # к
            elif b==b'\xab': b=0xab # л
            elif b==b'\xac': b=0xac # м
            elif b==b'\xad': b=0xad # н
            elif b==b'\xae': b=0xae # о
            elif b==b'\xaf': b=0xaf # п
            elif b==b'\xe0': b=0xe0 # р
            elif b==b'\xe1': b=0xe1 # с
            elif b==b'\xe2': b=0xe2 # т
            elif b==b'\xe3': b=0xe3 # у
            elif b==b'\xe4': b=0xe4 # ф
            elif b==b'\xe5': b=0xe5 # х
            elif b==b'\xe6': b=0xe6 # ц
            elif b==b'\xe7': b=0xe7 # ч
            elif b==b'\xe8': b=0xe8 # ш
            elif b==b'\xe9': b=0xe9 # щ
            elif b==b'\xea': b=0xea # ъ
            elif b==b'\xeb': b=0xeb # ы
            elif b==b'\xec': b=0xec # ь
            elif b==b'\xed': b=0xed # э
            elif b==b'\xee': b=0xee # ю
            elif b==b'\xef': b=0xef # я
            elif b==b'\xfc': b=0xfc # №
            else : b=ord(game_name[i: i+1])
            fat[z*20+i] = b

        print('offset in file:',hex(offset_file))
        offset_a = offset_file//0x2000
        print('offset/0x2000:', offset_a)
        offset_h = offset_a//0x100
        print('offset_h:', offset_h)
        offset_l = offset_a - offset_h * 0x100
        print('offset_l:', offset_l)
        fat[z*20+15] = 0x00
        fat[z*20+16] = offset_h
        fat[z*20+17] = offset_l
        if filesize > 0x9fff:
            game_len=0x06
        elif filesize > 0x7fff:
            game_len=0x05
        elif filesize > 0x5fff:
            game_len=0x04
        elif filesize > 0x3fff:
            game_len=0x03
        elif filesize > 0x1fff:
            game_len=0x02
        elif filesize > 0x0000:
            game_len=0x01
        fat[z*20+18] = game_len
        print('game len in 0x2000:',game_len,'\n')
        ftype = file_name.split('.')
# копирование файла игры в флэш файл
        game_file = open(file_name, 'rb')
        d = game_file.read()
        if ftype[1].lower() == 'r0m':
            flash_file.seek(offset_file+0x000, 0)
        else:
            flash_file.seek(offset_file+0x100, 0)

        flash_file.write(bytearray(d))
        game_file.close()
    else:
        for k in range(20):
            fat[z*20+k] = 0x20

    offset_file = offset_file + game_len * 0x2000

# запись файловой базы в флэш файл
flash_file.seek(0x1300)
flash_file.write(fat)
flash_file.close()  
# запись файловой базы в файл 000_loader3.rom
flash_file = open('_game500.rom', 'rb+')
flash_file.seek(0x1200)
flash_file.write(fat)
flash_file.close()

list_file.close()
print("\n")
print("_flash.bin creation complied")





