Дз. Реализовать класс Gamble, который с помощью рандома загадывает простое число.
Класс реализует функцию MakePrediction(std::string userName, int prediction)
С консоли пользователи вводят свои предположения, для этого мы запрашиваем у пользователя его имя и 
число.
После ввода имени и числа создается поток, который вызывает MakePrediction.
MakePrediction добавляет предсказание в мембер класса Gamble (std::map).
Через 2 минуты после старта приложения, Gamble определяет победителя для этого находит ставку наиболее
близкую к загаданному числу и выводит на экран.

Доп задача: std::map нельзя использовать многопоточно, т.е. доступ к ней должен быть синхронизирован.
Попробуйте синхронизировать доступ используя CriticalSection из Winapi