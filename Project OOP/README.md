# Object-oriented-programming-OOP university cource Project

                                                   
                                                   FOR ENGLISH SCROLL  DOWN!
                                                    
Трябва да призная, че проектът не е напълно завършен. Това, което не е докрай разработено е работата с файловете, всичко свързано с полиморфизъм  е имплементирано. Това е финален проект в курса "Обектно ориентирано програмиране" в Софийски университет. 
Завършен е на 16.07.2016г. 


- Начин на работа

Вашата програма трябва да позволява на потребителя да отваря файлове (open), да извършва
върху тях някакви операции, след което да записва промените обратно в същия файл (save) или в
друг, който потребителят посочи (save as). Трябва да има и опция за затваряне на файла, без
записване на промените (close). За целта, когато програмата ви се стартира, тя трябва да позволява
на потребителя да въвежда команди и след това да ги изпълнява.
Когато отворите даден файл, неговото съдържание трябва да се зареди в паметта, след което
файлът се затваря. Всички промени, които потребителят направи след това трябва да се пазят в
паметта, но не трябва да се записват обратно, освен ако потребителят изрично не укаже това.
Във всеки от проектите има посочен конкретен файлове формат, с който приложението ви
трябва да работи. Това означава, че:
1. то трябва да може да чете произволен валиден файл от въпросния формат;
2. когато записва данните, то трябва да създава валидни файлове във въпросния формат.
Както казахме по-горе, потребителят трябва да може да въвежда команди, чрез които да
посочва какво трябва да се направи. Командите могат да имат нула, един или повече параметри,
които се изреждат един след друг, разделени с интервали.
Освен ако не е казано друго, всяка от командите извежда съобщение, от което да е ясно дали е
успяла и какво е било направено.

Дадените по-долу команди трябва да се поддържат от всеки от проектите (под всяка от
командите е даден пример за нейната работа):

- Open:
Зарежда съдържанието на даден файл. Ако такъв не съществува се създава нов с празно
съдържание.
Останалите команди могат да се изпълняват само ако има успешно зареден файл.

пример:

> open C:\Temp\file.xml
Successfully opened file.xml

- Close
Затваря текущо отворения файл.

пример:

> close
Successfully closed file.xml

- Save
Записва направените промени обратно в същия файл, от който са били прочетени данните.

пример: 

> save
Successfully saved file.xml

- Save As
Записва направените промени във файл, като позволява на потребителя да укаже неговия път.

пример:

> saveas "C:\Temp\another file.xml"
Successfully saved another file.xml

- Exit
Излиза от програмата

пример:

> exit

----------------------------------------------------------------------------------------------------------------------------------------

**Проект 1: Работа със SVG файлове**

В рамките на този проект трябва да се разработи приложение, което работи с SVG файлове.
Приложението трябва да може да зарежда фигури от файла, да извършва върху тях дадени
операции, след което да може да записва промените обратно на диска.
За улеснение, в рамките на проекта ще работим само с основните фигури (basic shapes) в SVG.
Приложението ви трябва да поддържа поне три от тях. Например можете да изберете да се
поддържат линия, кръг и правоъгълник. За повече информация за това кои са базовите фигури,
вижте https://www.w3.org/TR/SVG/shapes.html.
Също така, за улеснение считаме, че координатната система, в която работим е тази по
подразбиране: положителната ос X сочи надясно, а положителната ос Y сочи надолу.
Дизайнът на приложението трябва да е такъв, че да позволява при нужда лесно да можете да
добавите поддръжка на нови фигури.
Когато зареждате съдържанието на един SVG файл, трябва да прочетете само фигурите, които
приложението ви поддържа и можете да игнорирате всички останали SVG елементи.
След като заредите фигурите, потребителят трябва да може да изпълнява дадените в
следващия раздел команди, които добавят, изтриват или променят фигурите.
Когато записвате фигурите във файл, трябва да генерирате валиден SVG файл

**Операции върху съдържанието на файла**
*Print* Извежда на екрана всички фигури.
*Create* Създава нова фигура.
*Erase* Изтрива фигура
*Translate* Транслира една или всички фигури. Ако потребителят не посочи конкретна
фигура се транслират всички фигури; ако се посочи конкретна – променя се
само тя.
*Within* Извежда на екрана всички фигури, които попадат в даден регион.
Потребителят може да укаже какъв да бъде регионът – кръг или
правоъгълник

- Примерен SVG файл figures.svg

<?xml version="1.0" standalone="no"?>
<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN"
 "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">
<svg>
 <rect x="5" y="5" width="10" height="10" fill="green" />
 <circle cx="5" cy="5" r="10" fill="blue" />
 <rect x="100" y="60" width="10" height="10" fill="red" />
</svg>


**Пример за работа на програмата:**


*open figures.svg*

``Successsfully opened figures.svg``

*print*

``1. rectangle 5 5 10 10 green``
``2. circle 5 5 10 blue``
``3. rectangle 100 60 10 10 red``


*create rectangle -1000 -1000 10 20 yellow*

``Successfully created rectangle (4)``


*print*

``1. rectangle 1 1 10 20 green``
``2. circle 5 5 10 blue``
``3. rectangle 100 60 10 10 red``
``4. rectangle 1000 1000 10 20 yellow``

*within rectangle 0 0 30 30*

``1. rectangle 5 5 10 10 green``
``2. circle 5 5 10 blue``

*within circle 0 0 5*

``figures are located within circle 0 0 5``

*erase 2*

``Erased a circle (2)``

*erase 100*

``There is no figure number 100!``

*print*

``1. rectangle 5 5 10 10 green``
``2. rectangle 100 60 10 10 red``
``3. rectangle 1000 1000 10 20 yellow``

*translate vertical=10 horizontal=100*

``Translated all figures``

*print*

``1. rectangle 105 15 10 10 green``
``2. rectangle 200 70 10 10 red``
``3. rectangle 1100 1010 10 20 yellow``

*save*

``Successfully saved the changes to figures.svg``

*exit*

``Exit``



----------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------


                                                               **Enligsh**

I must admit that the project is not fully completed. The unfinished part of the project is mostly connected with files. The whole work with polymorphism  is finished. is a final project of my Object oriented programming university cours in St. Kliment Ohridski university of Sofia. It is start at 06.07.2016 and finished by the date of: 16.07.2016.


**The way your program shoud work**

Your program should allow the user with the ability to open files (open), to do some operations upon them and after that to save the
changes back on top of the same file (save) or on top of another which the user wil specify (save as). There should be an option for closing the file without saving the changes (close). For that purpose, after the program is started the user should be able to input
different commands after that to execute them.

When you open certain file it's content has to be loaded in the memory and after that the file is closed. All changes which the user
does after that should be kept in the memory, but they shouldn't be saved on top of the file content unless the user dont give a command for it.

Your program must:
1) be able to read a random file from the file format which is specified below;
2) be able when saving the changes to create again a valid file from the same format.

As we said above the user has to be able to input commands whereby to specify what exactly to be done. The commands shoud have
zero, one or more parameters, which are given one after another separated with spaces.

If it's not specified any command must display a message which shows if the operations is executed successfully or not.

The commands must be supported from every project (below every command there's an example):

- Open:
loads the content of a file. If the specified file doesnt exist, it creates new one with an empty content. 
The rest of the commands shoud be executed only if there's successfully loaded file.

example:

> open C:\Temp\file.xml
Successfully opened file.xml

- Close:
close the file.

example:

> close
Successfully closed file.xml

- Save:
save the changes on top of the same file from which the content is taken.

example: 

> save
Successfully saved file.xml

- Save As:
save the changes in a file, while giving the user the ability to specify its path.

example:

> saveas "C:\Temp\another file.xml"
successfully saved another file.xml

- Exit:
exits the program.

example:

> exit

----------------------------------------------------------------------------------------------------------------------------------------

**Project 1: SVG Files.**

You should create a console application which works with SVG files. The application must be able to load figures from the file, to do on them given operations and after that to save to all changes.

For ease the project should support only the basic shapes in SVG. Your application shoud support at least three of them. For example you coud choose to support line, circle and rectangle. For more information take a look at: https://www.w3.org/TR/SVG/shapes.html.

Also, for ease we consider that the coordinate system, upon which the program works is the same as the default one or the X coordinate pointing right and Y coordinate pointing down.

The design of the application should be created in  a way that if its needed new functionality to be added easily. 

While you are loading the content of an SVG file you can only read the shapes your program supports the rest of them SVG elements you can ignore.

After you load the file, the user should  be able to execute the commands specified below who adds, deletes or changes figures.

When you save the figures in a file you should create valid SVG file.

