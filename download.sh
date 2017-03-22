#!/bin/bash
http://media.wiley.com/product_ancillary/50/11188580/DOWNLOAD/c01_code.zip
for i in 02 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 25 26 
do
    wget http://media.wiley.com/product_ancillary/50/11188580/DOWNLOAD/c${i}_code.zip && unzip c${i}_code.zip
    if [ $? != "0" ] ; then
        break;
    fi


done


