#!/bin/bash

TEMPO=$1
CAMINHO=$2
PORCENTAGEM=$3
TOKEN=$4
ID=$5
SOMA=0
CONTADOR=0
CONT_FORA_DO_AR=0


while [ 1 ]; do


    # Aqui é analisada porcentagem de uso da CPU e essa é comparada com àquela que foi inserida pelo usuário
    # Só vão ser impressas as demais informações caso a porcentagem atual seja menor que a inserida    
    PRCTG=$(top -n 1 | grep %Cpu | cut -d 'i' -f 2 | cut -d ' ' -f 2| tr '",' " .") 
    if [ $( echo  "$PRCTG<$PORCENTAGEM" | bc -l) -eq 1 ]; then

    # Aqui utiliza-se o grep e o CUT para  se analisar o IP do servidor 
    IP=$(netstat -anp 2>/dev/null | grep 45052 | grep ESTABLISHED |cut -f 16-17 -d ' ' | cut -d ':' -f 1 | uniq)
 

    # Datas 
    echo $(date +"%x %X")>>$CAMINHO
    echo $(date +"%x %X")

    echo "${IP}">>$CAMINHO
    if [ -n "${IP}" ]; then
     echo "${IP}"
    fi

    # Printa-se a % ociosa
    echo " Porcentagem da CPU ociosa: ${PRCTG} %"
    echo " Porcentagem da CPU ociosa: ${PRCTG} %">>$CAMINHO

    # Utiliza-se o grep para verificar se o servidor está fora do ar ou não
    VERIF_FORA_DO_AR=$(netstat -anp 2>/dev/null | grep 45052 | grep LISTEN)
    
    if [ -z "${VERIF_FORA_DO_AR}" ]; then
        echo "O Servidor está fora do ar">>$CAMINHO
        echo "O Servidor está fora do ar"
        curl -s --data "text= $(date +"%x %X") %0A O Servidor está fora do ar. %0A  Porcentagem da CPU ociosa: ${PRCTG} %" https://api.telegram.org/bot$TOKEN/sendMessage?chat_id=$ID 1>/dev/null 
    else curl -s --data "text=$(date +"%x %X") %0A ${IP} %0A  Porcentagem da CPU ociosa: ${PRCTG} %" https://api.telegram.org/bot$TOKEN/sendMessage?chat_id=$ID 1>/dev/null 
       
        # CONT_FORA_DO_AR é utilizado para saber o tempo em que o sistema ficou fora do ar
        let CONT_FORA_DO_AR=CONT_FORA_DO_AR+1
    fi 2>/dev/null



    let CONTADOR=CONTADOR+1
    


    # Abaixo estão as manipulações matemáticas para o calculo da média das 100 anteriores verificações
    if [ $( echo "$CONTADOR%100" |bc) -ne 0 ]; then
        SOMA=$(echo "$SOMA+$PRCTG" | bc -l)
    else
        SOMA=$(echo "$SOMA+$PRCTG" | bc -l)
        echo "Média das porcentagens: " >>$CAMINHO
        echo $(echo  "scale=2; $SOMA/100" | bc -l)>>$CAMINHO
        echo "Tempo fora do ar: "  $( echo "$TEMPO*$CONT_FORA_DO_AR" | bc -l)>>$CAMINHO
        SOMA=0
    fi

    fi

    sleep ${TEMPO}
    done

exit 0