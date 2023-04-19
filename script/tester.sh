#alias t="bash ../script/tester.sh"
arg1="$1"
g++ $arg1 && ./a.out < ../script/entrada.txt > ../script/saida.txt &&
echo "--ENTRADA--" && cat ../script/entrada.txt &&
echo "---SAIDA---" && cat ../script/saida.txt &&
echo "--SAIDA ESPERADA--" && cat ../script/resposta.txt &&
DIFF=$(diff ../script/resposta.txt ../script/saida.txt) 
if [ "$DIFF" ]
then
  echo "--DIFF--" && 
  #echo $DIFF
  diff ../script/resposta.txt ../script/saida.txt
  echo "--FAILED--" &&
  echo "Program failed to pass all Tests." 
else
  echo "--SUCCESS--" &&
  echo "Program Passed all Tests!!"
fi
