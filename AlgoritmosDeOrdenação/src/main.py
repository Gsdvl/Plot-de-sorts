import subprocess
import matplotlib as plt


#Variaveis Globais

n = 0 # Variavel que diz o tamanho do array
idx = 0
tam_lido = False # Booleano que verifica se o array ja foi lido
          
# Compila o arquivo C++
subprocess.run(['g++', 'src/SortAlgorithms.cpp', 'src/main.cpp', '-o', 'bin/ProgramaC++'], cwd='.')

# Executa o arquivo C++ como um processo
p = subprocess.Popen('bin/ProgramaC++', stdout=subprocess.PIPE)

# Lê as saídas do processo linha por linha
for linha in iter(p.stdout.readline, b''):
    #Verifica se o tamanho do array ja foi lido
    if tam_lido == False:
        n = int(linha)
        arr = [0] * n
        tam_lido = True
        print("Tamanho do Array: ", n)
    else:
        # Converte a linha de bytes para string e remove o caractere de quebra de linha
        arr[idx] = linha.decode().rstrip()
        idx += 1
        if idx == n:
            print(arr)
            idx = 0
    
    
    

# Espera o processo C++ terminar
p.wait()