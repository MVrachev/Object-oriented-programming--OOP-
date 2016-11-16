# Homework 4 - Object oriented programming course 

                                              FOR ENGLISH SCROLL  DOWN!

Това домашно е от курса по "Обектно ориентирано програмиране" към Софийски университет "Свети Климент Охридски".
Домашното е изцяло за наследяване. В момент когато го писах не знаех какво е полиморфизъм, за това и не съм го използвал.
Завършено е на: 04.07.2016г.

·      Да се реализира клас войник. 
Той трябва да съдържа информация за: име, години, ниво на бойните умения (цяло число) и заплата в златни монети.

·      Да се реализира клас сержант, който наследява войник, но като допълнение има описание на взвода (от войници), 
който командва и масив от всички войници в него.

·      Да се реализира клас заклинание, който съдържа неговото описание, 
тип и каква част от магическа мощ на магът, който го използва ,ще изисква.

·      Да се реализира клас магическа книга, която съдържа страници със заклинания,
всяко от които може да се използва точно веднъж (след това изчезва, заедно с цялата страница). 
Понеже книгата не е каква да е книга, а магическа – тя винаги има една празна страница накрая, 
давайки възможността на своя притежател да дописва ново заклинание.

·      Да се реализира клас маг, който наследява войник и като допълнение съдържа описание на батальона (от взводове), 
който командва, масив от всички сержанти на взводовете, които са в този батальон, магическата мощ,  която притежава и магическа книга.

·      Да се реализира клас главнокомандващ, който наследява войник, има описание на войската,
която предвожда и масив от магове които командват батальоните му.

·      Да се реализира програма, която дава възможност да се въведе информация за една войска 
и по указател към главнокомандващ да изчисли:

o      Средното и общото ниво на бойните умения на войската.

o      Средното и общото ниво на магическата мощ на войската.

o      Колко злато на месец ще му излиза поддръжката на тази войска.

 

**Бонус:**
Да се изчисли максималният брой заклинания, които могат да бъдат използвани от маговете в една войска (ако има такива). Взима се предвид, че всеки маг може да използва само своята магическа книга и при всяко използване на заклинание от книгата, магическата мощ на мага намалява със стойността, която заклинанието изисква за да бъде произнесено.


**Забележки :**

·      Описанията трябва да са текстове с произволна дължина.
·      В магическата книга страниците са колкото броя на заклинанията + 1 ( за празната страница ).
·      Един маг не може да използва заклинание, което изисква повече магическа мощ от неговата.
·      Всеки от командващите (сержант, маг и главнокомандващ) трябва има по-високо ниво на бойните умения 
от войниците (в частност това могат да са войници, сержанти и магове), които са под негово командване.
·      Ако при реализацията използвате някакви библиотеки, то трябва да можете на защитата да обясните точно какво правят, 
защо ги използвате, както и да реализирате на място функциите които са в тези библиотеки, спазвайки характеристиките на библиотеката.
Изключение се допуска за библиотеките за вход / изход (iostream, fstream), както и за cassert. 
За тях ще е нужно да обясните само каква е целта им и какви са добрите практики при използването им.
·      Имате право да дефинирате допълнителни полета в тези класове, и всякакви методи, които ще ви помогнат да решите по-добре задачата си. Също така можете да дефинирате допълнителни класове.



----------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------
                                                     English


This is a homework from the course "Object oriented programming" in St. Kliment Ohridski university of Sofia.
The homework is all about inheritance. At the time I did it I didn't know what was polymorphism that's why I didn't use it.
It is finished by the date of 04.07.2016


* Create a class soldier. 
  The class shoud have the following information for: name, years, level of the fighting skills (intiger) 
  and salary in golden coins.
* Create a class sergeant which inherits the soldier class, 
  In addition description of the platoon he is leading and and the sodliers which forms the platoon as an array.
* Create a class magic which has descrition, type of the magic and how much manna requires.
* Create a class magic book, which has pages of magics, every one of the magics can be used only once
  (after that it disappears with the whole page). Because the book isn't just a book, 
  but it's a magical book that's why she always has one empty page at the end giving the opportunity of it's owner
  to create a new magic.
* Create class magician which inherits the soldier class and in addition has descrition of the battalion he commands 
  (the battalion is made of platoons), an array of all sergeants in that battalion, manna and a magic book.
* Create class commander who inherits the soldier class and has a descrition of the army which he leads
  and an array of the magicians who controls his battalions.
  
* Implement a program which gives you the ability to create an army just by a pointer to the commander 
  and this program shoud calculate:
- The average and overall fighting skills of the army.
- The average and overall manna of the army.
- How much gold will much does  it cost to supports that army?


**A bonus :** 
- Calculate the maximum number of overall magics which the magicians can use in one army.
 Keep in mind that a magician can use only his book and when the magician use a magic his manna
 decrease by the manna the spell requires.
 
 
**A few important notes :**
 - The descriptions shoud be text with dynamic lenght.
 - In the magic book the amount of pages are as much as the magics + 1 (for the empty page).
 - One mage can't use a magic which requires more manna than he owns.
 - Everyone from the commanders (sergeant, magician, commander)  shoud have higher fighting skill than the soldiers that he commands.
- If you use any libaries you shoud be able to explain about them what they exactly do, 
because if you use them you shoud be able to implement some of the libraries functions when we want that.
An exception is using the libraries fstream and cassert. 
For them you shoud be albe just to explain what are the good practices when we use them.
 
