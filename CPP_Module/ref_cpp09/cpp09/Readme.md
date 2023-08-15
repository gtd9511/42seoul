# ✏️After finishing this module... <br>
## I can answer these questions below : <br>
1. Can you use STL library in C++?  <br>
   use [std::map](https://en.cppreference.com/w/cpp/container/map), [std::vector](https://en.cppreference.com/w/cpp/container/vector), [std::queue](https://en.cppreference.com/w/cpp/container/queue), [std::deque](https://en.cppreference.com/w/cpp/container/deque), and understand these containers and how it is implemented. <br>
2. Can you parse inputs as you want? (ex00) <br>
   (use internal database to calcuate the bitCoin exchange amount : by multiplying (exchange rate)<br>
   ```
   $> ./btc
   Error: could not open file.
   $> ./btc input.txt
   2011-01-03 => 3 = 0.9
   2011-01-03 => 2 = 0.6
   2011-01-03 => 1 = 0.3
   2011-01-03 => 1.2 = 0.36
   2011-01-09 => 1 = 0.32
   Error: not a positive number.
   Error: bad input => 2001-42-42
   2012-01-11 => 1 = 7.1
   Error: too large a number.
   $>
      ```
   
3. Do you know and understand Reverse Polish Notation? (ex01) <br>
4. Can you use STL libraries and make Reverse Poliish Notation works that you can calcualte? (ex01) <br>
   ```
   $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
   42
   $> ./RPN "7 7 * 7 -"
   42
   $> ./RPN "1 2 * 2 / 2 * 2 4 - +"
   0
   $> ./RPN "(1 + 1)"
   Error
   $>
   ```
5. Do you understand Merge-insertion sort? (ex02) <br>
6. When you do not know or understand something, do you have power to search and devote yourself to solve it?(ex02) <br>
   ```
   $> ./PmergeMe 3 5 9 7 4
   Before: 3 5 9 7 4
   After: 3 4 5 7 9
   Time to process a range of 5 elements with std::[..] : 0.00031 us
   Time to process a range of 5 elements with std::[..] : 0.00014 us
   $> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
   Before: 141 79 526 321 [...]
   After: 79 141 321 526 [...]
   Time to process a range of 3000 elements with std::[..] : 62.14389 us
   Time to process a range of 3000 elements with std::[..] : 69.27212 us
   $> ./PmergeMe "-1" "2"
   Error
   $> # For OSX USER:
   $> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
   [...]
   $>
   ```


## ✏️To complete this module, I collected the following knowledge:
1. std::string : [using std::string with member functions ](https://ebang.tistory.com/102) <br>
   
3. iterators in c++ : [c++ iterators](https://ebang.tistory.com/101) <br>
4. new algorithm : [merge-insertion sort]( https://ebang.tistory.com/104) <br>
