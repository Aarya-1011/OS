echo "Enter a number"
read n
rem=`expr $n % 2`
if [ $rem -eq 0 ]
then
	echo "$n is an even"
else
	echo "$n is odd"
fi
