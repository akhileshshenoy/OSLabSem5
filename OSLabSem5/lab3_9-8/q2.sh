echo "Enter a number:"
read n
x=1
for((i=0;i<n;i++))
do
echo $x
x=`expr $x + 2`
done