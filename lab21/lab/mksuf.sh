num=$1
i=0
while [ $i -lt $num ]
do
echo "${i}f.suf"| xargs touch
i=$(( $i + 1 ))
done
echo "in.suf"| xargs touch