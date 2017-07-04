low=1
high=500

shuf() { awk 'BEGIN {srand(); OFMT="%.17f"} {print rand(), $0}' "$@" |sort -k1,1n | cut -d ' ' -f2-; };

ARG="$(seq $low $high | shuf | tr '\n' ' ')"
echo $ARG
#./push_swap $ARG
./push_swap $ARG
RESULT="$(./push_swap $ARG | wc -l)"
echo push_swap returned with $RESULT instructions
echo testing with checker...
./push_swap $ARG | ./checker $ARG
