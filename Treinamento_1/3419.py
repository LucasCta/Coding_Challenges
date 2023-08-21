import functools

#SALVA OS CORREDORES NUM FORMATO DECENTE
N, V = input().split()
corredores = []
for i in range(int(N)):
    corredores.append(input().split())
def convert(corredor):
    total = [corredor[0]]
    for i in range(1, int(V) + 1):
        m, s, ms = corredor[i].split(':')
        m, s, ms = int(m), int(s), int(ms)
        total.append(m * 60000 + s * 1000 + ms)
    return total
corredores = list(map(convert,corredores))

#ENCONTRA A MELHOR VOLTA
def joinTimes(corredor1, corredor2):
    return corredor1 + corredor2[1:]
tempos = functools.reduce(joinTimes, corredores)
tempos.pop(0)
melhorVolta = min(tempos)

#ENCONTRA OS CORREDORES QUE TIVERAM A MELHOR VOLTA
def encontraMVoltas(corredor):
    if melhorVolta in corredor:
        return corredor.index(melhorVolta)
    else:
        return 999999
melhoresVoltas = list(map(encontraMVoltas, corredores))

#ENCONTRA O PRIMEIRO CORREDOR A ATINGIR A MENOR VOLTA
indexMelhorCorredor = melhoresVoltas.index(min(melhoresVoltas))

#ORDENA OS CORREDORES POR MELHORES TEMPOS TOTAIS
def totl(corredor):
    total = 0
    for i in range(1, int(V) + 1):
        total += corredor[i]
    return total
tempototal = list(map(totl, corredores))
tempototalordenado = list(map(totl, corredores))
tempototalordenado.sort()

achou = len(list(filter(lambda x: x == tempototal[indexMelhorCorredor], tempototalordenado[:10]))) > 0

if (not achou):
    print("NENHUM")
else:
    print(corredores[indexMelhorCorredor][0])

