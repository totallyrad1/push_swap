[en.subject.pdf](https://github.com/totallyrad1/push_swap/files/13797678/en.subject.4.pdf)

# usage :

**for_push_swap**
1. make at the root of your repository`\n`
2. execute ./push_swap <numbers_u_want_it_to_sort>`\n`
3. the program will display instruction used to sort the numbers.`\n`

**for_checker**
1. make bonus at the root of your repository
2. execute ./push_swap <numbers_u_want_it_to_sort> | ./checker <same_numbers_u_entered_in_pushswap>
3. the program will display ok if the instructions were enough to sort the numbers

# final grade : 
<img width="200" alt="image" src="https://github.com/totallyrad1/push_swap/assets/67210558/298cf344-a4b3-4df7-8db4-dc10c7eb48c8">

# sorting method explanation :

after u put the numbers in ur linked list theres 2 parts part1(pushing numbers to stack b) part2(sorting the numbers into stacka)
for this method we use indexs not the actual numbers so u gotta find a way to give ur numbers an index.

# **for Part 1**
imma try to explain using drawings
first u need function that sorts 3 numbers 4 numbers and 5 numbers thats easy !

then lets get the explanation
first we use 3 integeres lets call em **lastp1** and **p1** and **p2**
we initialize em like this
**lp1** = -1;.
**p1** = sizeofstacka / 3;.
**p2** = sizeofstack / 6;.

<img width="500" alt="image" src="https://github.com/totallyrad1/push_swap/assets/67210558/1e7d8436-6bfc-479e-9dda-c8d3c72e37d7">


keep in mind these arent the numbers these are the index of the numbers .
okay the first thing we do is that we keep pushing numbers into stack b **while size of stack a is greater than 3**.

it works like this 
if top a index is lesser than **p1**
  we **push the first number** into **stack b**
else
  we rotate a to get the second number.

like this since 0 is lesser than 3 i pushed that number into stack b

<img width="500" alt="image" src="https://github.com/totallyrad1/push_swap/assets/67210558/7a0d3b52-fe77-49ab-8a21-3e0dc4327564">

after that we check if the **size of stack b** is **greater than 1** and if the **top of b is greater or equal** than **lp1** and  **lesser or equal** to **p2**
  we **rotate b**
we keep doing the same thing until **the size of b reaches p1**
then we update pivots like this 
**lp1 = p1** ;
**p1 += sizea / 3**; 
**p2 = sizeb / 6 + lp1**;

this is the result after the first pivotes updating 
i kept doing the same process until **size of b reached p1**
<img width="500" alt="image" src="https://github.com/totallyrad1/push_swap/assets/67210558/e2c605a5-4059-4702-95a1-6626b724904f">

now we keep doing the same thing while **stack a size is greater than 3**
after that we **have 3 numbers in stack a** 
and the result is like this 

<img width="500" alt="image" src="https://github.com/totallyrad1/push_swap/assets/67210558/04afcf48-0a1f-45ee-aac5-34326a409c8d">

than we sort stack a with our **sort 3 numbers function**

<img width="500" alt="image" src="https://github.com/totallyrad1/push_swap/assets/67210558/9ba49cd9-d2ba-4bab-b9eb-dbd14cf1f272">

this is the result of part 1 
now we move into **part 2**

# **part 2**

now we stop using pivots but we use bottom of a **index since its always the biggest number**
we need 2 integeres
**biggestnumbervalue = bottoma index**; this is fix we never change it 
**bottomavalue = bottoma index**; we keep updating this on every move 

<img width="500" alt="image" src="https://github.com/totallyrad1/push_swap/assets/67210558/6f119e8a-2d54-46e3-ad18-8e65efca2ccc">

the part 2 works like this :

while **stack b still has numbers** we have a loop running 

in that loop we have another loop we keep pushing into a or rotating b depending on the statements 
if **botottoma_index** lesser than **topb_index** or **bottoma_index** equal to **biggestnumbervalue**
  we push the number into a 
  and we rotate
  and we update the **bottomavalue**
else
  we rotate b untill we find the numbers thats equal to **topa_index - 1**

here since bottom value is equal to the biggest number we **push into a** and **we rotate A** the result will be like this

<img width="500" alt="image" src="https://github.com/totallyrad1/push_swap/assets/67210558/84ba8f31-8851-4c1d-aac3-797454c04409">

we keep doing the same thing untill we find numbers thats equal to **topa_index - 1**

<img width="500" alt="image" src="https://github.com/totallyrad1/push_swap/assets/67210558/2622dfc2-b1ab-43a2-81a8-c1fcc1661796">

once we find it we push the number into **the top of stack a** like this

<img width="500" alt="image" src="https://github.com/totallyrad1/push_swap/assets/67210558/e02dc9a3-2d6b-4e34-9ad0-2c8ae6683bb0">

now we have another if statement if the index in the **bottom of stack a is equal to top a - 1**
here 2 is equal to 3 - 1

<img width="500" alt="image" src="https://github.com/totallyrad1/push_swap/assets/67210558/3d4f23a8-83fc-452b-8e1c-86c9629660a7">

we reverse rotate a like this 

<img width="500" alt="image" src="https://github.com/totallyrad1/push_swap/assets/67210558/8ad08878-6572-4378-a9e5-dc642a3e3304">

**!! dont forget to update the bottom index on every move !!**

we keep doing this process until stack b has no numbers

and this is **the result**

<img width="500" alt="image" src="https://github.com/totallyrad1/push_swap/assets/67210558/187dca25-143e-48a2-9743-cba0d8ed45b9">











