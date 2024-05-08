; Este programa lê um texto da entrada padrão e a depender do modo faz operações matemáticas específicas.
; O resultado é exibido na saida padrão em Linux NASM, 64-bits
; Obs.: o texto só pode ter caracteres ASCII (no mínimo 1 aracter para o modo, 1 caractere para o espaço, e entre 1 e 15 caracteres para o número desejado" ")


section .data

LF equ 0XA ; LINE FEED
NULL equ 0XD ; FINAL DA STRING
;EAX
SYS_SAIDA equ 60 ; CODIGO PARA FINALIZAR
SYS_WRITE equ 0x1 ; OPERAÇÃO DE ESCRITA
SYS_READ equ 0X0 ; OPERAÇÃO DE LEITURA
;EBX
RET_SAIDA equ 0x0
STD_OUT equ 0X1 ; SAIDA PADRÃO
STD_IN equ 0X0 ; ENTRADA PADRÃO
SPACE db 32 ;; referente ao caractere do espaço " "
msg db "Coloque o modo e um número", LF, NULL ;; mensagem a ser apresentada no começo do programa
tam equ $- msg ;; tamanho da mensagem acima.


section .bss


numero resb 15 ;; local onde o número a ser lido será armazenado
modo resb 2 ;; local ondo o modo e o caractere de espaço serão lidos
numero_print resb 15 ;;  utilizado para fazer os prints em uma string


section .text 




;; mensagem_de_inicio é um texto que é colocado para indicar ao usuário o que ele deve fazer para que o programa funcione
;; ou seja, que seja escrito primeiro o modo e, depois, o número.
mensagem_de_inicio: 
	mov rax, SYS_WRITE  ;;  número da syscall write
	mov rdi, STD_OUT   ;; o descritor do arquivo que será escrito
	mov rsi, msg ;;  o ponteiro para a mensagem que será escrita
	mov rdx, tam ;;  tamanho da mensagem 
	syscall ;; chamada ao SO
	ret




;; Essa função é responsável por printar um número primo que foi colocado no registrador r9 pela função *modo_0*
printar_0: 
	mov r14, r9 ;; no registrador r9 se localiza o número a ser transformado em string
	call transf_int_char ;; chamada da função para transformar em string e salvar em "numero_print"
	mov rax, SYS_WRITE ;;  número da syscall write
	mov rdi, STD_OUT ;; o descritor do arquivo que será escrito
	mov rsi, numero_print ;; o ponteiro para a mensagem que será escrita
	mov rdx, 15 ;; tamanho máximo de um número
	syscall ;; chamada ao SO
	ret ;; fim da função printar_0 após ter sido escrito o número ao usuário





;; Essa função é responsável por printar duas strings e um caracter de espaço entre elas
;; as duas string são referentes aos dois números que multiplicados resultam no número dado pelo usuário
printar_1:
	;; no *modo_1*, os números ficaram salvos nos registradores r10 e r15. 
	;; caso não existam dois primos que multiplicados resultam no número inserido o programa encerra sem
	;; sem printar nada ao usuário 
	mov r14, r10 ;; coloca o número em r14 para a realização do print poque a função transf_int_char 
	;; transforma o número do registrador r14 em string
	call transf_int_char ;; chamada da função para transformar em string e salvar em "numero_print"
	mov rax, SYS_WRITE ;;  número da syscall write
	mov rdi, STD_OUT ;; o descritor do arquivo que será escrito
	mov rsi, numero_print ;; o ponteiro para a mensagem que será escrita
	mov rdx, 15 ;; tamanho máximo de um número
	syscall ;; chamada ao SO

	mov rax, SYS_WRITE ;; essa sys printa um espaço " "
	mov rdi, STD_OUT ;; o descritor do arquivo que será escrito
	mov rsi, SPACE ;; número equivalente a espaço na tabela ascii
	mov rdx, 1 ;; tamanho de caracteres
	syscall ;; chamada ao SO

	mov r14, r15 ;; O segundo número a ser printado se encontra no registrador r15
	;; transforma o número do registrador r14 em string
	call transf_int_char ;; chamada da função para transformar em string e salvar em "numero_print"
	mov rax, SYS_WRITE ;;  número da syscall write
	mov rdi, STD_OUT ;; o descritor do arquivo que será escrito
	mov rsi, numero_print ;; o ponteiro para a mensagem que será escrita
	mov rdx, 15 ;; tamanho máximo de um número
	syscall ; chamada ao SO
	ret ;; fum da função após ter escrito os dois números separados por espaço para o usuário




;; essa função transforma um número em string
transf_int_char:
	;; Nesta função dividiremos o número por dez seguidamente para, então, transformá-lo e guardá-lo em string pela variável "numero_print"
	;;
	;; Utilizarei o r14 como registrador para realização dos printf's
	mov r8, r14 ;; em r8 ficarão os resultados das divisões do número por 10
	mov r13, 14 ;; esse é o tamanho máximo do número
	mov rcx, 10 ;; o rcx, nessa situação será tuilizado para a divisão do numero em rax por 10
	loop_do_print:
		mov rdx, 0 ;;essa ação é necessária para a realização da divisão
		mov rax, r8 ;; o número é colocado em rax para que a divisão ocorra pelo número atualizado
		cmp r8, 1 ;; verifica se o número é <1 para, parar de dividir e sair do loop
		jl saida_print ;; sai do loop
		div rcx ;; rax = num / 10
		mov r8, rax ;; o número/10 é atualizado para que o próximo caractere seja trnasformado em string 
		add rdx, 48 ;; em rdx se encontra o resto da divisão por 10, logo, o número desejado. Ao adicionar 48, transformamos o número em caractere pela tabela ascii
		mov [numero_print + r13], dl  ;; o caractere do número é adicionado na string
		dec r13 ;; diminui r13 (tamanho máximo do número)
		cmp r13, 0 ;; verifica se o tamanho foi estrapolado
		jg loop_do_print ;; continua o loop caso contrário
		saida_print: 
			ret




	
;; essa função le duas strings, uma com dois caracteres e outra com, no máximo 15
;; um deles é um número (0 ou 1) + o caracere de espaço " " 
;; o outro le um número  
ler:
	mov rax, SYS_READ ;; número da syscall read
	mov rdi, STD_IN  ;; o descritor de arquivo que será lido
	mov rsi, modo ;; o ponteiro para onde o conteúdo lido será armazenado
	mov rdx, 2 ;; tamanho da string a ser lida (quantidade de bytes)
	syscall ;; chamada para o SO

	mov rax, SYS_READ  ;;  número da syscall read
	mov rdi, STD_IN  ;; primeiro parâmetro é o descritor de arquivo que será lido
	mov rsi, numero ;; o ponteiro para onde o conteúdo lido será armazenado
	mov rdx, 15 ;; tamanho da string a ser lida (quantidade de bytes)
	syscall ;; chamada para o SO

;; nessa função, transofrma-se strings em números para a realização de operações matemáticas
transforma_int:

	;; a princípio com o modo (0 ou 1), primeiro caractere da string [modo]
	mov bl, [modo] ;; o primeiro caractere de modo é adicionado em bl, ou seja, o " " é ignorado
	sub bl, 48 ;; o caractere é transformado em inteiro nessa operação
	mov [modo], bl ;; o número agora volta para o endereço [modo]

	;; em seguida com o número
	mov r12, rax ;; passa o tamanho do número para o registrador r12
	mov rdi, 0 ;; será utilizado como a "soma" do número
	mov rcx, 1 ;;utilizado para multiplicar na potencia de dez
	mov r15, 10 ;; utilizado para fazer a potencia de dez
    dec r12 ;; r12-- 

	ler_loop:

		dec r12 ;; diminui o tamanho para transformmar caracteres em int
		cmp r12, 0 ;; verifica se é maior que zero
		jl fim_leitura ;; pula para o  "ret" caso o número seja menor que zero
		;; isso significaria que todo o número ja foi lido
		mov bl, [numero + r12] ;;move caracteres da string da variavel númer, um por um. 
		sub bl, 48 ;; pela tabela ascii, tal operação faz com que sejam convertidos em inteiros os números
		mov rax, rbx ;; em rbx se encontra o número e é passado a RAX para a operação abaixo de multiplicação
		mul rcx ;; (numero inteiro) * (potencia de dez)
		add rdi, rax;; soma o numero obtido com o calculado até agora

		mov rax, rcx ;; transfere o valor para realização da potencia de dez
		mul r15; faz rax = rax * 10
		mov rcx, rax ;; transfere o valor pra salvar a potencia de dez
		jmp ler_loop ;; continua o loop

	fim_leitura:

		ret ;; retorna para a _start



;; essa função verifica se o número presente no registrador (rdi) é primo
eh_primo:
	mov rcx, 1 ;; i (rcx) == 1 
	;; i é utilizado como contador e vão ser os números que serão verificados se dividem o número em rdi
	;; caso exista algum número que divida aquele presente no resgistrador (rdi), sabemos que não é primo
	primo_loop:
		inc rcx ;; i++
		mov rax, rcx ;; rax = i
		mul rcx ;; i*i
		cmp rax, rdi ;; compara i*i com numero
		jg ret1;; if (i*i < numero (rbx)) return 1; 
		mov rax, rdi;; utilizsdo p/ fazer a divisão
		mov rdx, 0 ;; essa operação é necessária para o DIV
		div rcx ;; num / i
		cmp rdx, 0 ;; verifica o resto da divisão
		jne primo_loop ;; continua o loop
		jmp ret0 ; if (num%i == 0 ) return 0;
	ret1:
		mov rdx, 1
		ret 
	ret0:
		mov rdx, 0
		ret


global _start

_start:

; TODO: delme

call mensagem_de_inicio ;; imprime a mensagem de início para o usuário

call ler ;; le o modo e o número

cmp byte [modo], 0 ;; verifica o modo e pula caso ele for 0
je loop_modo_0
jmp modo_1

loop_modo_0:
	inc rdi ;; numero +1
	call eh_primo ;; verifica se é primo
	cmp rdx, 0 ;; em rdc é colocado o return da função eh_primo, então é comparado 
	je loop_modo_0 ;; se for zero, pula para o loop_modo_0 em que será procurado o ppróximo primo
	mov r9, rdi ;; o próximo primo é colocado no registrador r9 para ser printado no terminal pela syscall
	call printar_0 ;; chama a função para printar
	jmp fim ;; encerra o programa

modo_1:
	mov rcx, 1 ;; contador (i)
	loop_modo_1: 
		inc rcx ;; i++
		mov rax, rcx ;; rax = i
		mul rcx ;; i*i
		cmp rax, rdi ;; compara i*i com numero
		jg ret1 ;;  PULAR PRA SAIR DO FOR 
		mov rax, rdi;; utilizsdo p/ fazer a divisão
		mov rdx, 0 ;; necessario para divisão
		div rcx ;; num / i
		cmp rdx, 0 ;; compara o resto da div
		jne loop_modo_1 ;; volta se o i não dividir o numero
		mov r10, rcx ;; salva o valor de i qe é obrigatoriamente primo
		mov rax, rdi ;; coloca o valor do numero em rax para divisão
		mov rdx, 0 ;; necessario para a divisão
		div r10 ;; divide o numero por i
		mov rdi, rax ;; coloca o resultado da divisão exta em rdi
		call eh_primo ;; verifica se esse número (j) é primo
		cmp rdx, 0 ;; compara se o numero é primo ou não
		je fim ;; se o numero não for primo, não há 2 numeros q multiplicados dão esse 3º numero
		mov r15, rdi ;; coloca o valor de j em r15 
		call printar_1
		jmp fim
		
	
		

	


; END TODO

;; finaliza o programa
fim:
	mov rax, SYS_SAIDA
	mov rdi, RET_SAIDA 
	syscall ;; chamada do SO

