#!/bin/bash

    gcc -Wall -ansi -pedantic -O2 InsertionSort.c -o InsertionSort
    gcc -Wall -ansi -pedantic -O2 quicksort.c -o quicksort 
    gcc -Wall -ansi -pedantic -O2 MergeSort.c -o MergeSort
    gcc -Wall -ansi -pedantic -O2 heapSort.c -o heapSort


let val=250
for i in {1..10};
do
./quicksort ${val} <output.txt >>output1.txt
echo ${val}
let val=val*2



done


let val=250
for i in {1..10};
do
./InsertionSort ${val} <output.txt >>output1.txt
echo ${val}
let val=val*2
done


let val=250
for i in {1..10};
do
./MergeSort ${val} <output.txt >>output1.txt
echo ${val}
let val=val*2
done

let val=250
for i in {1..10};
do
./heapSort ${val} <output.txt >>output1.txt
echo ${val}
let val=val*2
done
