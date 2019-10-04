echo "Enter a number:"
read n
x=1
for((i=2;i<=n;i++))
do
x=`expr $x \* $i`
done
echo $x