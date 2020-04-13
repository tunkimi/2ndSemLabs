#!/bin/bash
fullname=$1
if [ -z $1 ]
then 
echo "Укажите входной файл"
exit 1
fi
suf=".${fullname#*.}"
find . -name "*$suf"| xargs -n1 diff -q -s in.suf > t.t
sed -e 's/идентичны/rm/g' -e 's/различаются/skip/g' -e 's/Файлы in.suf и //g' t.t |xargs -n2 >> t1.t
sort t1.t|grep "rm" >> t2.t
sed -e 's/ rm//g' t2.t| xargs -n1 >>t3.t
cat t3.t
for ussr in $(cat t3.t)
do
if [ "${ussr#./}" != "in.suf" ]
then
rm -rf ${ussr#./}
fi
done
rm -rf t.t
rm -rf t1.t
rm -rf t2.t
rm -rf t3.t