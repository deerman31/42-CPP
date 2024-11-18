#!/bin/fish

echo "test1 -> [8 9 * 9 - 9 - 9 - 4 - 1 +]"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo

echo "test2 -> [7 7 * 7 -]"
./RPN "7 7 * 7 -"
echo

echo "test3 -> [1 2 * 2 / 2 * 2 4 - +]"
./RPN "1 2 * 2 / 2 * 2 4 - +"
echo

echo "test4 -> [(1 + 1)]"
./RPN "(1 + 1)"
echo

echo "test5 -> [1 +]"
./RPN "1 +"
echo

echo "test6 -> [3 4 + 1 2 - *]"
./RPN "3 4 + 1 2 - *"
echo

echo "[5 6 - 1 3 * 2 + 5 2 - * - 4 5 * * 8 /]"
./RPN "5 6 - 1 3 * 2 + 5 2 - * - 4 5 * * 8 /"
echo

echo "[5  6 - 1 3 * - 4 5 * * 8 2 +]"
./RPN "5  6 - 1 3 * - 4 5 * * 8 2 +"
echo

echo "[9 0+]"
./RPN "9 0+"
echo

echo "[9 0  +]"
./RPN "9 0  +"
echo

echo "[9 0 /]"
./RPN "9 0 /"
echo

echo "[ 9 0 *]"
./RPN " 9 0 *"
echo

echo "[9 0 * ]"
./RPN "9 0 * "
echo

echo "[90 * ]"
./RPN "90 * "
echo

echo "overcheck"
./RPN "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"
echo

echo "undercheck"
#./RPN "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"
./RPN "1 8 - 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"
echo
