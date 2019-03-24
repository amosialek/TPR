more +4 10e10.out | awk '{print $3 " " $2}' > time10e10.out
more +4 10e10_2.out | awk '{print $3  " " $2}' > time10e10_2.out
more +4 10e10_3.out | awk '{print $3  " " $2}' > time10e10_3.out
more +4 10e10_4.out | awk '{print $3  " " $2}' > time10e10_4.out
more +4 10e10_5.out | awk '{print $3  " " $2}' > time10e10_5.out
more +4 10e9.out | awk '{print $3  " " $2}' > time10e9.out
more +4 10e9_2.out | awk '{print $3  " " $2}' > time10e9_2.out
more +4 10e9_3.out | awk '{print $3  " " $2}' > time10e9_3.out
more +4 10e9_4.out | awk '{print $3  " " $2}' > time10e9_4.out
more +4 10e9_5.out | awk '{print $3  " " $2}' > time10e9_5.out
cat time10e10.out time10e10_2.out time10e10_3.out time10e10_4.out time10e10_5.out time10e9.out time10e9_2.out time10e9_3.out time10e9_4.out time10e9_5.out > time_merged.out
python3 process_outputs.py
