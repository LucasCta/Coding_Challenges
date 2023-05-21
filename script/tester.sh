#alias t="bash ../script/tester.sh"

program="$1"

if [[ $program == *.py ]]
then 
  python3 $program < ../script/entrada.txt > ../script/saida.txt
elif [[ $program == *.cpp ]]
then
  g++ -g $program && ./a.out < ../script/entrada.txt > ../script/saida.txt
else
  echo "ERROR: Invalid Language"
  exit 1
fi

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
