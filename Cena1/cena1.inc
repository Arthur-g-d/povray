/*
  ****************************************************************************************
  ************************   MACRO ÁRVORE   **********************************************
  ****************************************************************************************
*/

#macro arvore()
        // folhas da árvore - uma esfera verde com textura irregular
        #local folhas = sphere {
          <0,0,0>
          0.4
          pigment {color Green}  // pigmento verde
          normal {
            bumps 1               // textura com relevo
            scale 0.1             // escala da textura
          }
        }

        // Galho da árvore - cilindro marrom com uma coroa no topo
        #local tronco = union {
                cylinder {
                  <0, -0.9, 0>
                  <0, 0.9, 0>
                  0.1
                  pigment {color Brown} // pigmento marrom (cor de madeira)
                }
                object {
                  folhas                // adiciona a coroa ao topo do galho
                  translate <0, 0.7, 0> // posiciona a coroa acima do cilindro
                } 
        }

        // Tronco da árvore com ramificações maiores e menores
        #local galho = union {
                cylinder {
                  <0, -1, 0>
                  <0, 1, 0>
                  0.4
                  pigment {color Brown} // pigmento marrom do tronco
                }
                // Extensões do tronco - galhos maiores
                object {
                  tronco
                  scale <1.5, 1.5, 1.5> // aumenta o tamanho do galho
                  translate <0, 1.5, 0> // posiciona mais acima no tronco
                  rotate <15, 0, 20>    // rotaciona o galho
                  translate <-0.2, 0.2, 0> // pequeno ajuste na posição
                }
                object {
                  tronco
                  scale <2, 1.7, 2>     // galho maior e mais largo
                  translate <0, 1.7, 0>
                  rotate <5, 0, -10>
                  translate <-0.2, 0.2, 0>
                }
                // Galhos menores
                object {
                  tronco
                  translate <0, 0.6, 0>
                  rotate <0, 0, 40>
                  rotate <0, 90, 0>     // comentado: possível rotação adicional
                  translate <-0.2, 0, 0>
                }
                object {
                  tronco
                  translate <0, 0.8, 0>
                  rotate <0, 0, 40>
                  rotate <0, 90, 0>      // rotação em Y para orientação lateral
                  translate <0, 0, -0.2>
                }
                object {
                  tronco
                  translate <0, 0.9, 0>
                  rotate <0, 0, -40>
                  translate <-0.2, 0.2, 0>
                }
                object {
                  tronco
                  translate <0, 0.9, 0>
                  rotate <0, 0, -40>
                  rotate <0, 40, 0>
                  translate <-0.2, 0.2, 0>
                }
        }

        // Desenha o tronco com seus galhos
        object {
          galho
        }
#end

// Macro para criar uma vaca
#macro vaca()
        // Olho da vaca
        #local olho = union {
                sphere {
                  <0,0,0>, 0.1
                  pigment {color White}      // Esclera branca
                }
                sphere {
                  <0,0,0>, 0.06
                  translate <0,0,-0.08>
                  pigment {color Black}      // Pupila preta
                }       
        }
        
        // Chifre da vaca
        #local chifre = union {
                blob {
                threshold 0.01
                cylinder {
                  <-0.2,0,0>
                  <0.2,0,0>
                  0.1, 1
                  pigment {color White}      // Cor branca para chifre
                }
                cylinder {
                  <0,-0.2,0>
                  <0,0.2,0>
                  0.08, 1
                  translate <0.2,0.2,0>
                  pigment {color White}
                }
                }
        }
        
        // Focinho da vaca
        #local focinho = union {
                cylinder {
                  <0,0,-0.3>
                  <0,0,0.3>
                  0.2
                  pigment {color rgb <0.9,0.8,0.8>}    // Cor rosada clara
                }
                sphere {
                  <0,0,-0.3>
                  0.22
                  scale <1,1,0.8>
                  pigment {color  rgb <0.9,0.8,0.8>}
                }
        }
        
        // Cabeça da vaca com textura de imagem
        #local cabeca = union {
                sphere {
                  <0,0,0>,0.4
                  texture { pigment{image_map { png "lata_krowy.png"}}}   // Textura da vaca
                }
                object {
                  olho
                  translate <-0.2,0.2,-0.35>   // Olho esquerdo
                }
                object {
                  olho
                  translate <0.2,0.2,-0.35>    // Olho direito
                }
                object {
                  focinho
                  translate <0,0,-0.3>          // Focinho
                }
                object {
                  chifre
                  translate <0.3,0.2,0>         // Chifre direito
                }
                object {
                  chifre
                  rotate <0,180,0>
                  translate <-0.3,0.2,0>        // Chifre esquerdo
                }
        }
        
        // Pescoço da vaca com textura da imagem
        #local pescoco = union {
                cylinder {
                  <0,-0.2,0>
                  <0,0.2,0>
                  0.2
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object {
                  cabeca
                  translate <0,0.35,0>
                }
        }
        
        // teta da vaca
        #local teta = union {
                cylinder {
                  <0,0,-0.2>
                  <0,0,0.2>
                  0.08
                  pigment {color  rgb <0.9,0.8,0.8>}   // Cor rosada clara
                } 
        }
        
        // Conjunto de tetas (quatro) posicionadas e rotacionadas
        #local mamas = union {
                sphere {
                  <0,0,0>,0.4
                  pigment {color  rgb <0.9,0.8,0.8>}
                }
                object {
                  teta
                  rotate <-5,10,0>
                  translate <-0.15,0.15,-0.35>
                }                     
                object {
                  teta
                  rotate <-5,10,0>
                  translate <-0.15,-0.15,-0.35>
                }
                object {
                  teta
                  rotate <-5,-10,0>
                  translate <0.15,0.15,-0.35>
                }
                object {
                  teta
                  rotate <-5,-10,0>
                  translate <0.15,-0.15,-0.35>
                }
        }
        
        // Parte inferior da perna (canela) com textura da imagem
        #local canela = union {
                cylinder {
                  <0,-0.25,0>,<0,0.25,0>,0.1
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                box {
                  <-0.1,-0.12,-0.1>,<0.1,0.12,0.1>
                  translate <0,-0.25,0>
                  pigment {color Black}       // Detalhe preto na canela
                }
        }
        
        // Joelho da vaca com textura
        #local joelho = union {
                sphere {
                  <0,0,0>, 0.11
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object {
                  canela
                  translate <0,-0.25,0>
                  rotate <-20,0,0>
                }
        }
        
        // Coxa da vaca
        #local coxa = union {
                cone {
                  <0,0.3,0>, 0.3
                  <0,-0.3,0> 0.1
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object {
                  joelho
                  translate <0,-0.3,0>
                }
        }
        
        // Perna completa
        #local perna = union {
                sphere {
                  <0,0,0>, 0.3
                  texture { pigment{image_map { png "lata_krowy.png"}}}                 
                }
                object {
                  coxa
                  translate <0,-0.3,0>
                }
        }
        
        // Antebraço da vaca
        #local antebraco = union {
                cylinder{
                  <0,-0.2,0>, <0,0.2,0>, 0.1
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                box {
                  <-0.1,-0.12,-0.1>,<0.1,0.12,0.1>
                  translate <0,-0.25,0>
                  pigment {color Black}     // Detalhe preto no antebraço
                }
        }
        
        // Cotovelo da vaca
        #local cotovelo = union {
                sphere {
                  <0,0,0>, 0.12
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object {
                  antebraco
                  translate <0,-0.2,0>
                  rotate <45,0,0>
                }
        }
        
        // Braço da vaca
        #local braco = union {
                cylinder{
                  <0,-0.3,0>, <0,0.3,0>, 0.1
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object {
                  cotovelo
                  translate <0,-0.3,0>
                }
        }
        
        // Corpo da vaca com todos os membros posicionados
        #local corpo = union {
                sphere {
                  <0,0,0>, 1
                  scale <0.5,1,0.7>
                  texture { pigment{image_map { png "lata_krowy.png"}}}    // Corpo texturizado
                }
                object {
                  pescoco
                  translate <0, 1 ,0>
                }
                object {
                  mamas
                  translate <0,-0.3,-0.5>
                }
                object {
                  perna
                  rotate <45*sin(clock*360),0,0>   // Movimento da perna sincronizado com o tempo
                  translate <0.22,-0.8,0>
                }
                object {
                  perna
                  rotate <-45*sin(clock*360),0,0>
                  translate <-0.22,-0.8,0>
                }
                object {
                  braco
                  translate <0,-0.2,0>
                  rotate <-45*sin(clock*360),0,0>
                  rotate <0,-10,0>
                  rotate <0,0,30>
                  translate <0.3,0.8,0>
                }
                object {
                  braco
                  translate <0,-0.2,0>
                  rotate <45*sin(clock*360),0,0>
                  rotate <0,10,0>
                  rotate <0,0,-30>
                  translate <-0.3,0.8,0>
                }
        }
        
        object {corpo}    // Desenha a vaca completa
    
#end
