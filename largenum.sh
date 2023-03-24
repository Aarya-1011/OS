echo " Enter the limit"
read num
large=0
for i in $num
do
	if [ $i -gt $large ]
	then
		large=$i
	fi
done
echo "Largest number is $large"
