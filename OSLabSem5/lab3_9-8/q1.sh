echo "Enter a number:"
read n
n=`expr $n \% 2`
if [ $n -eq 1 ]
then echo "odd"
else
echo "even"
fi