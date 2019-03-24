import pprint
def serialFraction(speedup, CPUsCount):
    #print("debug",speedup,CPUsCount)
    return (1/speedup - 1/CPUsCount)/(1-1/CPUsCount)

with(open("time_merged.out")) as f:
    data=[]
    for a in range(2):  #1e10/1e9
        data.append([])
        for i in range(5):
            data[a].append([])
            for j in range(2):
                data[a][i].append([])
                for k in range(12):
                    line = f.readline().split(" ")
                    data[a][i][j].append(line)
    #pprint.pprint(data)

    with(open("time10e10_avg_scale.out","+w")) as f:
        for k in range(12):
            sum=0
            for i in range(5):
                sum += float(data[0][i][0][k][1].strip())
            f.write(str(k+1)+' '+str(sum/5)+'\n')
    with(open("time10e10_avg.out","+w")) as f:
        for k in range(12):
            sum=0
            for i in range(5):
                sum += float(data[0][i][1][k][1].strip())
            f.write(str(k+1)+' '+str(sum/5)+'\n')
    with(open("time10e9_avg_scale.out","+w")) as f:
        for k in range(12):
            sum=0
            for i in range(5):
                sum += float(data[1][i][0][k][1].strip())
            f.write(str(k+1)+' '+str(sum/5)+'\n')
    with(open("time10e9_avg.out","+w")) as f:
        for k in range(12):
            sum=0
            for i in range(5):
                sum += float(data[1][i][1][k][1].strip())
            f.write(str(k+1)+' '+str(sum/5)+'\n')
    with(open("speedup10e10_avg_scale.out", "+w")) as f:
        sum0 = 0
        for k in range(12):
            sum = 0
            for i in range(5):
                sum += float(data[0][i][0][k][1].strip())
            if k == 0:
                sum0 = sum
            scale = float(data[0][i][0][k][0].strip())/float(data[0][i][0][0][0].strip())
            f.write(str(k+1) + ' ' + str(((k + 1) * (sum0 / 5)) / (sum / 5)) + '\n')
            #print(str(k + 1) + ' ' + str(((k + 1) * (sum0 / 5)) / (sum / 5))+ " "+str(sum / 5)+" "+str(sum0/5) )

    with(open("speedup10e10_avg.out", "+w")) as f:
        sum0=0
        for k in range(12):
            sum = 0
            for i in range(5):
                sum += float(data[0][i][1][k][1].strip())
            if k==0:
                sum0=sum
            scale = float(data[0][i][0][k][0].strip()) / float(data[0][i][0][0][0].strip())
            f.write(str(k+1) + ' ' + str((sum0/5)/(sum / 5)) + '\n')
            #print(str(k+1) + ' ' + str((sum0/5)/(sum / 5)) + " "+str(sum / 5)+" "+str(sum0/5))
    with(open("speedup10e9_avg_scale.out", "+w")) as f:
        sum0 = 0
        for k in range(12):
            sum = 0
            for i in range(5):
                sum += float(data[1][i][0][k][1].strip())
            if k == 0:
                sum0 = sum
            #scale = float(data[0][i][0][k][0].strip()) / float(data[0][i][0][0][0].strip())
            f.write(str(k+1) + ' ' + str(((k + 1) * (sum0 / 5)) / (sum / 5)) + '\n')
            #print(str(k + 1) + ' ' + str(((k + 1) * (sum0 / 5)) / (sum / 5))+ " "+str(sum / 5)+" "+str(sum0/5) )

    with(open("speedup10e9_avg.out", "+w")) as f:
        sum0 = 0
        for k in range(12):
            sum = 0
            for i in range(5):
                sum += float(data[1][i][1][k][1].strip())
            if k == 0:
                sum0 = sum
            scale = float(data[0][i][0][k][0].strip()) / float(data[0][i][0][0][0].strip())
            f.write(str(k+1) + ' ' + str((sum0/5)/(sum / 5)) + '\n')
            #print(str(k + 1) + ' ' + str((sum0 / 5) / ( sum / 5))+ " "+str(sum / 5)+" "+str(sum0/5) )

    with(open("efficiency10e10_avg_scale.out", "+w")) as f:
        sum0 = 0
        for k in range(12):
            sum = 0
            for i in range(5):
                sum += float(data[0][i][0][k][1].strip())
            if k == 0:
                sum0 = sum
            scale = float(data[0][i][0][k][0].strip()) / float(data[0][i][0][0][0].strip())
            f.write(str(k + 1) + ' ' + str((sum0/5)/(sum / 5)) + '\n')
            print(str(k + 1) + ' ' + str((sum0/5)/(sum / 5)) + " " + str(sum / 5) + " " + str(sum0 / 5))

    with(open("efficiency10e10_avg.out", "+w")) as f:
        sum0 = 0
        for k in range(12):
            sum = 0
            for i in range(5):
                sum += float(data[0][i][1][k][1].strip())
            if k == 0:
                sum0 = sum
            scale = float(data[0][i][0][k][0].strip()) / float(data[0][i][0][0][0].strip())
            f.write(str(k + 1) + ' ' + str(((sum0 / 5) / (sum / 5))/(k+1)) + '\n')
            print(str(k + 1) + ' ' + str(((sum0 / 5) / (sum / 5))/(k+1)) + " " + str(sum / 5) + " " + str(sum0 / 5))
    with(open("efficiency10e9_avg_scale.out", "+w")) as f:
        sum0 = 0
        for k in range(12):
            sum = 0
            for i in range(5):
                sum += float(data[1][i][0][k][1].strip())
            if k == 0:
                sum0 = sum
            # scale = float(data[0][i][0][k][0].strip()) / float(data[0][i][0][0][0].strip())
            f.write(str(k + 1) + ' ' + str((sum0/5)/(sum / 5)) + '\n')
            print(str(k + 1) + ' ' + str((sum0/5)/(sum / 5)) + " " + str(sum / 5) + " " + str(sum0 / 5))

    with(open("efficiency10e9_avg.out", "+w")) as f:
        sum0 = 0
        for k in range(12):
            sum = 0
            for i in range(5):
                sum += float(data[1][i][1][k][1].strip())
            if k == 0:
                sum0 = sum
            scale = float(data[0][i][0][k][0].strip()) / float(data[0][i][0][0][0].strip())
            f.write(str(k + 1) + ' ' + str(((sum0 / 5) / (sum / 5))/(k+1)) + '\n')
            print(str(k + 1) + ' ' + str(((sum0 / 5) / (sum / 5))/(k+1)) + " " + str(sum / 5) + " " + str(sum0 / 5))


    with(open("serialFrac10e10_avg_scale.out", "+w")) as f:
        sum0 = 0
        for i in range(5):
            sum0 += float(data[0][i][0][0][1].strip())
        for k in range(1,12):
            sum = 0
            for i in range(5):
                sum += float(data[0][i][0][k][1].strip())
            speedup = ((k + 1) * (sum0 / 5)) / (sum / 5)
            scale = float(data[0][i][0][k][0].strip())/float(data[0][i][0][0][0].strip())
            f.write(str(k+1) + ' ' + str(serialFraction(speedup,k+1)) + '\n')
            print(str(k+1) + ' ' + str(serialFraction(speedup,k+1)) )


    with(open("serialFrac10e10_avg.out", "+w")) as f:
        sum0=0
        for i in range(5):
            sum0 += float(data[0][i][1][0][1].strip())
        for k in range(1,12):
            sum = 0
            for i in range(5):
                sum += float(data[0][i][1][k][1].strip())
            scale = float(data[0][i][0][k][0].strip()) / float(data[0][i][0][0][0].strip())
            speedup = (sum0/5)/(sum / 5)
            f.write(str(k+1) + ' ' + str(serialFraction(speedup,k+1)) + '\n')
            print(str(k+1) + ' ' + str(serialFraction(speedup,k+1)) )
    with(open("serialFrac10e9_avg_scale.out", "+w")) as f:
        sum0 = 0
        for i in range(5):
            sum0 += float(data[1][i][0][0][1].strip())
        for k in range(1,12):
            sum = 0
            for i in range(5):
                sum += float(data[1][i][0][k][1].strip())
            speedup = ((k + 1) * (sum0 / 5)) / (sum / 5)
            #scale = float(data[0][i][0][k][0].strip()) / float(data[0][i][0][0][0].strip())
            f.write(str(k+1) + ' ' + str(serialFraction(speedup,k+1)) + '\n')
            print(str(k+1) + ' ' + str(serialFraction(speedup,k+1)) )

    with(open("serialFrac10e9_avg.out", "+w")) as f:
        sum0 = 0
        for i in range(5):
            sum0 += float(data[1][i][1][0][1].strip())
        for k in range(1,12):
            sum = 0
            for i in range(5):
                sum += float(data[1][i][1][k][1].strip())
            speedup = (sum0 / 5) / (sum / 5)
            scale = float(data[0][i][0][k][0].strip()) / float(data[0][i][0][0][0].strip())
            f.write(str(k+1) + ' ' + str(serialFraction(speedup,k+1)) + '\n')
            print(str(k+1) + ' ' + str(serialFraction(speedup,k+1)), speedup)
