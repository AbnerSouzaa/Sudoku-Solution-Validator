# Use a imagem base do GCC para compilar o código C++
FROM gcc:latest

# Defina o diretório de trabalho dentro do container
WORKDIR /app

# Copie todos os arquivos do repositório para dentro do container
COPY . .

# Instale as dependências necessárias 
RUN apt-get update && apt-get install -y make

# Compile o código
RUN make

# Comando para rodar o validador de Sudoku quando o container for executado
CMD ["./sudoku_validator"]
