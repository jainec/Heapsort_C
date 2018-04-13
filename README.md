# Heapsort_C

Esta é uma implementação do heapsort para resolver o problema abaixo:

> A empresa de telecomunicações Poxim Tech está construindo um sistema de comunicação, baseado no protocolo de datagrama do usuário (UDP) para transferência de pacotes em redes TCP/IP.

> Os dados são organizados em sequências de bytes de tamanho variável, mas limitados até o tamanho máximo de 512 bytes.

> Devido às características de roteamento de redes TCP/IP, os pacotes podem chegar ao seu destino desordenados, sendo necessária a ordenação dos pacotes para receber os dados corretamente.

> Para permitir o acesso rápido dos dados, é possível processar as informações recebidas desde que estejam parcialmente ordenadas, com os pacotes iniciais, sendo este processamento disparado por uma determinada quantidade de pacotes recebidas.

# Formato de arquivo de entrada

    [#n total de pacotes] [Quantidade de pacotes]
    [N úmero do pacote] [#m 1 Tamanho do pacote] [B1] · · · [B m 1 ]
    ···
    [N úmero do pacote] [#m n Tamanho do pacote] [B1] · · · [B m n ]
    
**Exemplo:**

      62
      0 3 01 02 03
      1 2 04 05
      2 4 06 07 08 09
      4 2 0F 10
      3 5 0A 0B 0C 0D 0E
      5 6 11 12 13 14 15 16

# Formato de arquivo de saída

> Quando uma quantidade determinada de pacotes é recebida, é feita a ordenação parcial dos pacotes para verificar se é possível exibir a parte inicial completa dos dados que já foram recebidos

**Exemplo:** 

    0: 01 02 03 04 05
    1: 01 02 03 04 05 06 07 08 09
    2: 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 10 11 12 13 14 15 16
