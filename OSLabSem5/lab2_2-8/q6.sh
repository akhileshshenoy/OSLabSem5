format=$1
path=$2
x=$(ls *.$format)
cp $x "$path"