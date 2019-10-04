echo "Enter the first operand:"
read a
echo "Enter the operator"
read op
echo "Enter the second operand"
read b
p='+'
if [ $op -eq p ]
then
echo `expr $a + $b`
fi 