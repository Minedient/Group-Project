# Group-Project

This is the source code for CCN2042 Class 103 Group 13's project
--------------------------------------------------------------------------------

Additional (optional) features:

change character used in blocks

cpu battle

->player and cpu take steps alternatively

->cpu picks random block and place on the board randomly

timer?

pc demo: auto with pause or manual?
--------------------------------------------------------------------------------

class chessboard

-placeblock function
 
-> refers to block objects for coordinates
  
-> checks for completed rows/columns every time

-checkclear function

-> checks for rows and columns separately

-> register if a row/column should be cleared in seperate array

-> add score and clear registered rows/columns after all rows/columns are checked

class block

-allows for multiple instances of the same block shape
 
-> with different index numbers
  
-display function
