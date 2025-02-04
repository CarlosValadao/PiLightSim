# 🚦 PiLightSim

PiLightSim é um simulador de semáforo desenvolvido em linguagem C, utilizando o pico SDK na versão 2.1.0. Este projeto foi feito utilizando o VS Code com as extensões CMake, Raspberry Pi Pico e o compilador gcc-arm-eabi. O programa simula um semáforo com a utilização de um LED RGB na placa BitDogLab 6.3, controlando a alternância de cores do LED a cada 3 segundos, simulando as cores de um semáforo: vermelho → amarelo → verde.

## 📌 1. Como Funciona

O programa utiliza um temporizador periódico via software, que alterna as cores do LED RGB a cada 3000 milissegundos (3 segundos). As cores seguem a sequência padrão de semáforo:

🟥 **Vermelho (Red)** - Pare
🟨 **Amarelo (Yellow)** - Atenção
🟩 **Verde (Green)** - Siga

As cores são controladas via os pinos da placa BitDogLab conectados ao LED RGB, onde:

- **Pin 13** controla o LED Red 🔴,
- **Pin 12** controla o LED Blue 🔵,
- **Pin 11** controla o LED Green 🟢.

## 🛠 2. Requisitos

Antes de começar a usar o PiLightSim, certifique-se de que você tem as seguintes dependências instaladas:

✅ VS Code (ou outro editor de sua preferência)
✅ Extensões do VS Code:
   - CMake
   - Raspberry Pi Pico
✅ pico SDK 2.1.0
✅ gcc-arm-eabi (compilador)
✅ BitDogLab 6.3 para controle do LED RGB

https://github.com/user-attachments/assets/311af299-8a00-4249-a046-1a74d0bf2a58

## 🚀 3. Instalação e Execução

### 🔹 Passo 1: Clonando o Repositório

Clone o repositório para o seu ambiente local:

```bash
git clone https://github.com/CarlosValadao/PiLightSim.git
```

### 🔹 Passo 2: Configurando o Ambiente de Desenvolvimento

1. Abra o VS Code.
2. Instale as extensões necessárias:
   - CMake
   - Raspberry Pi Pico
3. Configuração do compilador:
   - Certifique-se de que o **gcc-arm-eabi** está instalado em seu sistema.
   - Se estiver usando o Windows, verifique as configurações do compilador no VS Code.

### 🔹 Passo 3: Importando o Projeto

1. No VS Code, abra o menu **Import Project** da extensão **Raspberry Pi Pico**.
2. Selecione o diretório do projeto **PiLightSim**.
3. Configure o CMake para compilar o projeto.

### 🔹 Passo 4: Construindo o Projeto

1. Construa o projeto usando o CMake.
2. Use a opção de "Build" do VS Code para compilar o código.

### 🔹 Passo 5: Carregando o Programa para o Raspberry Pi Pico

1. Conecte o Raspberry Pi Pico ao seu computador via USB.
2. Coloque o Pico no modo **BOOTSEL**.
3. Carregue o binário compilado para o Pico.

### 🔹 Passo 6: Executando o Programa

Depois de carregar o programa, o semáforo começará a simular as cores a cada 3 segundos, alternando entre **🟥 Vermelho → 🟨 Amarelo → 🟩 Verde**.

### 💻 Passo 7: Rodando o Código no Wokwi
Para rodar o código diretamente no Wokwi, siga os passos abaixo:

**1. Instale a Extensão Wokwi no VS Code:**

No VS Code, instale a extensão Wokwi. Isso pode ser feito diretamente no marketplace do VS Code, pesquisando por "Wokwi".

**2. Arquivo diagram.json Já Preenchido:**

O arquivo** _diagram.json_** já está configurado corretamente no projeto. Não é necessário fazer nenhuma modificação nele.

**3. Abra o Projeto no Wokwi:**

No VS Code, abra o arquivo diagram.json para carregar a simulação no Wokwi.

**4. Simule o Código:**

Clique em Start Simulation no Wokwi para iniciar a execução do código.
O semáforo começará a simular as cores a cada 3 segundos, alternando entre 🟥 Vermelho → 🟨 Amarelo → 🟩 Verde.

## 🤝 4. Contribuição

Sinta-se à vontade para contribuir com o projeto. Para isso, faça um fork deste repositório, crie suas melhorias ou correções e envie um **pull request**.
