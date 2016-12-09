# Creating and controlling an abstract army by one pointer

                                     
This is consonle application which is my fourth homework from the university course "Object oriented programming" in St. Kliment Ohridski university of Sofia.
The homework is all about inheritance. At the time I did it I didn't know what was polymorphism that's why I didn't use it.
It is finished by the date of 07.05.2016


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
 
