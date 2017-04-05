for i in $(eval echo {1..$1})
do
    fallocate -l 500M dummy_files/$i&
    nohup ./a.out $i&
    pids[${i}]=$!
done
#for pid in ${pids[*]}; do wait $pid; done;
#python3 find_mean.py nohup.out >> outputs4
#rm nohup.out
