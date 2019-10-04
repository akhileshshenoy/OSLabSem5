echo "Enter a:"
read a
echo "Enter b:"
read b
echo "Enter c:"
read c
d=`expr \( $b \* $b \) - \( 4 \* $a \* $c \)`
if [ $d -eq 0 ]
then echo "Real and equal roots"
root=`expr \( -1 \* $b \) \/ \( 2 \* $a \)`
echo $root
elif [ $d -lt 0 ]
then echo "Imaginary roots"
d=`expr -1 \* $d `
temp=$(echo "scale=3; sqrt($d)" | bc)
ia=`expr \( -1 \* $b \) \/ \( 2 \* $a \) `
ib=`expr $temp \/ \( 2 \* $a \) `
echo " $ia + i $ib"
echo " $ia - i $ib"
else
echo "Real and distinct roots"
temp=$(echo "sqrt($d)" | bc)
ra=`expr \( \( -1 \* $b \) + $temp \) \/ \( 2 \* $a \) `
rb=`expr \( \( -1 \* $b \) - $temp \) \/ \( 2 \* $a \) `
echo $ra
echo $rb
fi

