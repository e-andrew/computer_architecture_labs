### Склад програми
Назва виконуваного файлу: сommand.exe<br>
Назва динамічної бібліотеки: сommand.so<br>
### Принцип роботи
Розбір команд командного рядка виконується за 5 етапів:<br>
1. Зчитування командного рядка. Отримання об'єкта сommand(string).<br>
2. Парсинг об'єкта command(string). Отримання дерева розбору(parseTree).<br>
2.1. Поділ об'єкта сommand(string) на список ключів(keys).<br>
2.2. Поділ складних коротких ключів на прості короткі ключі.<br>
3. Перевірка синтаксичної правильності дерева розбору(parseTree).<br>
4. Спрощення дерева розбору(parseTree) за ім'ям ключів.<br>
5. Виклик обробника для кожного ключа.<br>

### Objects View
#### Short Key View
    [KEY_FLAG][SHORT_KEY_NAME][NULL][NULL | PARAMETER | PARAMETERS]
    [KEY_FLAG][SHORT_KEY_NAME_1][NULL | PARAMETER_1 | PARAMETERS_1][SHORT_KEY_NAME_2][NULL | PARAMETER_2 | PARAMETERS_2]
#### Long Key View
    [KEY_FLAG][KEY_FLAG][LONG_KEY_NAME][NULL | DELIMITER][NULL | PARAMETER | PARAMETERS]

#### Parse Tree View
    {
      key: {flag, name, delimiter, parameters: {par, par, par, ...}};
      key: {flag, name, delimiter, parameters: {par, par, par, ...}};
      key: {flag, name, delimiter, parameters: {par, par, par, ...}};
      key: {flag, name, delimiter, parameters: {par, par, par, ...}};
      key: {flag, name, delimiter, parameters: {par, par, par, ...}};
      key: {flag, name, delimiter, parameters: {par, par, par, ...}};
    }

### Parse Symbols
Cимвол початку ключа: [-].<br>
Ім'я ключа - текстовий символ: [a-zA-Z_].<br>
Роздільник імені ключа і параметрів: [=].<br>
Роздільник параметрів: [,].<br>
Параметр - числовий символ: [0-9.].<br>

### Syntax Errors
|  Code  |  Error  |
| :----: |  :---:  |
|0|IncorrectKeyFlag|
|1|ShortNameOfKeyIsNotGiven|
|2|UnknownSymbolInShortNameOfKey|
|3|UnknownShortNameOfKey|
|4|LongNameOfKeyIsNotGiven|
|5|UnknownSymbolInLongNameOfKey|
|6|UnknownLongNameOfKey|
|7|GivenParametersButNotGivenDelimiterInLongKey|
|8|GivenDelimiterButNotGivenParametersInLongKey|
|9|IncorrectNumberOfParameters|
|10|UnknownSymbolInShortKeyParameters|
|11|UnknownSymbolInLongKeyParameters|
|12|IncorrectTypeOfParameters|

### Key List
|  Short Key Name  |  Long Key Name  |  Parameter Count  |  Parameter Type | 
| :--------------: | :-------------: | :---------------: | :-------------: |
| h | help | 0 | null |
| v | version | 0 | null |
| V | value | 1 | all |
| L | list | 3 | all |
| i | integer_value | 1 | int |
| d | double_value | 1 | double |
| I | integer_list | 3 | int |
| D | double_list | 3 | double |
| c | clean_values | 0 | null |
| C | clean_lists | 0 | null |
| s | save_values | 0 | null |
| S | save_lists | 0 | null |
