import subprocess
import matplotlib.pyplot as plt
import time


# Variáveis Globais
n = 0  # Variável que diz o tamanho do array
idx = 0

# Valores Booleanos
tam_lido = False
grafico_criado = False

# *Pergunta ao usuário o tipo de sort e o tamanho da base de dados *
print("Digite o Tipo de sort Desejado\n1- Bubble\n2- Merge\n3- Quick\n")
sortType = int(input())
print("Agora digite o tamanho do array desejado (<100)\n")
dataSize = int(input())

# Compila o arquivo C++
subprocess.run(['g++','src/QuickSort.cpp', 'src/MergeSort.cpp', 'src/BubbleSort.cpp', 'src/main.cpp', '-o', 'bin/ProgramaC++'], cwd='.', bufsize=0)


# Executa o arquivo C++ como um processo
p = subprocess.Popen(['bin/ProgramaC++', str(sortType), str(dataSize)], stdout=subprocess.PIPE)

# Cria o gráfico inicial vazio
fig, ax = plt.subplots()

# Função que atualiza o gráfico com base nos dados do array
def update_graph(arr):
    ax.clear()
    ax.bar(range(len(arr)), arr)
    plt.xlabel('Index')
    plt.ylabel('Valor')
    plt.pause(0.01)

arr = [0] * dataSize
# Lê as saídas do processo linha por linha
for linha in iter(p.stdout.readline, b''):
    # Converte a linha de bytes para string e remove o caractere de quebra de linha
    arr[idx] = int(linha.decode().rstrip())
    idx += 1
    if idx == dataSize - 1:
        update_graph(arr)
        idx = 0
        time.sleep(0.5)

# Espera o processo C++ terminar
p.wait()

# Mantém o gráfico exibido após a conclusão do loop
plt.show()
