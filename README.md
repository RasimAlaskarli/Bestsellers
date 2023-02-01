# Bestsellers
The task is to develop a program that processes sales and analyzes best selling products.

Assume we register all products sold in our store. We are interested in the products that are selling the best. Our program is able to display the N best selling products, where N is given as a parameter to our program (the first input value).

Each product is identified by its unique name (a string). The name is at most 99 characters long and does not contain any whitespace. A sold product is given in the input as + product-name. Next, there are analytic commands in the input, in particular:

command # is designated to display the N best selling products. The listing is formatted according to the examples below. There is product name and the number of sold items for each product. The products are listed in an descending order (better selling products go first). Finally, there is a summary printed as the last line with the sum of the above sold items.
command ? displays the summary only.
The output of the program may be a bit confusing when there are products with equal number of sold items:

a simple case i presented in the first example run. There are eggs and flour in the listing, we sold 4 items of both. Therefore, these products share 2-nd and 3-rd place in the listing; the order is printed accordingly. Moreover, the relative position of flour/eggs is not given. The testing environment accepts all (here both) variants. Therefore, both listings would be accepted in this case:
   1. Milk, 5x
   
   2.-3. Eggs, 4x
   
   2.-3. Flour, 4x
   
   4. Beer, 3x
   
or:

   1. Milk, 5x
   
   2.-3. Flour, 4x
   
   2.-3. Eggs, 4x
   
   4. Beer, 3x
   
   
A more complex case is shown in the second example run. The program is to compute the top N=3 products. However, the listings are longer than 3 items in some cases, e.g.:


   1.-4. Black_tea, 1x
   
   1.-4. Caffeine, 1x
   
   1.-4. C/C++_for_dummies, 1x
   
   1.-4. Introduction_to_Algorithms, 1x
   
   
or:


   1.-2. Black_tea, 2x
   
   1.-2. Caffeine, 2x
   
   3.-5. C/C++_for_dummies, 1x
   
   3.-5. Energy_drink, 1x
   
   3.-5. Introduction_to_Algorithms, 1x
   
   
The listing is longer than N if there exist further products with sales equal to the sales of the displayed products.
The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below), and terminate. If displayed, the error message must be sent to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The following is considered invalid:

the value of N is not an integer, is negative, or zero,
the command is not recognized (valid commands are +, ? and #),
a product name is not valid (missing, 100 or more characters).
