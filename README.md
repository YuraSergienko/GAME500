# GAME500

<img src="game500.jpg" alt="GAME500">

<b>ROM картридж для компьютера "Вектор-06Ц"</b>

GAME500 - простое устройство для быстрой загрузки любимых программ. Для подключения к "Вектору" использется порт ПУ, а также при необходимости
магнитофонный вход. GAME500 эмулирует ROM картридж поддержка которого есть в большенстве загрузочных ПЗУ. Если же в "Векторе" установлено
заводское загрузочное ПЗУ без поддержки ROM картриджа, на GAME500 есть аудиовыход, который нужно подключить к магнитофонному входу "Вектора".
При нажатии кнопки "PLAY" на GAME500, с него воспроизводится небольшая программа-загрузчик с поддержкой ROM картриджей.

Содержание папок репозитория:<br>
asm - исходные коды для загрузчиков и файловой оболочки.<br>
box - stl модели корпусных деталей картриджа.<br>
doc - документация на изделие.<br>
flash - программа и файлы для подготовки bin файла для записи в микросхему флэш памяти W25Q128.<br>
gerber - GERBER файлы для производства печатной платы.<br>
src - проект в среде MounRiver для микроконтроллера CH32V103C8T6.<br>
src/obj/game500.hex - файл прошивки микроконтроллера CH32V103C8T6.<br>

<b>ROM cartridge for the Vector-06C computer</b>

GAME500 is a simple device for quickly loading your favorite programs. The "ПУ" port is used to connect to the "Vector", and if necessary,
the tape recorder input. GAME500 emulates a ROM cartridge, which is supported by most boot ROMs. If the "Vector" has a factory boot ROM
without support for a ROM cartridge, the GAME500 has an audio output that needs to be connected to the tape recorder input of the "Vector".
When you press the "PLAY" button on the GAME500, a small bootloader program with support for ROM cartridges is played from it.

Contents of repository folders:<br>
asm - source codes for loaders and file manager.<br>
box - stl models of cartridge body parts.<br>
doc - product documentation.<br>
flash - program and files for preparing a bin file for recording in the W25Q128 flash memory chip.<br>
gerber - GERBER files for PCB production.<br>
src - project in the MounRiver IDE for the CH32V103C8T6 microcontroller.<br>
src/obj/game500.hex - firmware file for the CH32V103C8T6 microcontroller.<br>
