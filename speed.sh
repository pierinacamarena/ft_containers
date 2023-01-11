make compare
start=`date +%s.%N`
./ft_containers_tester > f
end=`date +%s.%N`

runtime=$( echo "$end - $start" | bc -l )
echo ft:
echo $runtime

start=`date +%s.%N`
./std_containers_tester > s
end=`date +%s.%N`

runtime=$( echo "$end - $start" | bc -l )
echo std
echo $runtime

rm -f f
rm -f s