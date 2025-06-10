/*
  ****************************************************************************************
  ************************   MACRO VACA **************************************************
  ****************************************************************************************
*/

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
                  translate <0.22,-0.8,0>
                }
                object {
                  perna
                  translate <-0.22,-0.8,0>
                }
                object {
                  braco
                  translate <0,-0.2,0>
                  rotate <0,-10,0>
                  rotate <0,0,30>
                  translate <0.3,0.8,0>
                }
                object {
                  braco
                  translate <0,-0.2,0>
                  rotate <0,10,0>
                  rotate <0,0,-30>
                  translate <-0.3,0.8,0>
                }
        }
        
        object {corpo}    // Desenha a vaca completa
    
#end

/*
  ****************************************************************************************
  ************************   MACRO VACA ANDANDO   ****************************************
  ****************************************************************************************
*/
#macro vaca_andando()
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

/*
  ****************************************************************************************
  ************************   MACRO VACA SENTADA   ***************************************
  ****************************************************************************************
*/
#macro vaca_sentada()
        // Olho da vaca
        #local olho = union {
                sphere {
                  <0,0,0>, 0.1
                  pigment {color White}
                }
                sphere {
                  <0,0,0>, 0.06
                  translate <0,0,-0.08>
                  pigment {color Black}
                }       
        }
        
        // Chifre da vaca
        #local chifre = union {
                blob {
                threshold 0.01
                cylinder {
                  <-0.2,0,0>, <0.2,0,0>, 0.1, 1
                  pigment {color White}
                }
                cylinder {
                  <0,-0.2,0>, <0,0.2,0>, 0.08, 1
                  translate <0.2,0.2,0>
                  pigment {color White}
                }
                }
        }
        
        // Focinho da vaca
        #local focinho = union {
                cylinder {
                  <0,0,-0.3>, <0,0,0.3>, 0.2
                  pigment {color rgb <0.9,0.8,0.8>}
                }
                sphere {
                  <0,0,-0.3>, 0.22
                  scale <1,1,0.8>
                  pigment {color rgb <0.9,0.8,0.8>}
                }
        }
        
        // Cabe�a da vaca 
        #local cabeca = union {
                sphere {
                  <0,0,0>, 0.4
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object { olho translate <-0.2,0.2,-0.35> }
                object { olho translate <0.2,0.2,-0.35> }
                object { focinho translate <0,0,-0.3> }
                object { chifre translate <0.3,0.2,0> }
                object { chifre rotate <0,180,0> translate <-0.3,0.2,0> }
        }
        
        // Pesco�o da vaca
        #local pescoco = union {
                cylinder {
                  <0,-0.2,0>, <0,0.2,0>, 0.2
                  texture { pigment{image_map { png "lata_krowy.png"}}} 
                }
                object { cabeca translate <0,0.35,0> }
        }
        
        // Teta da vaca
        #local teta = cylinder {
                  <0,0,-0.2>, <0,0,0.2>, 0.08
                  pigment {color rgb <0.9,0.8,0.8>}
        }
        
        // Conjunto de tetas
        #local mamas = union {
                sphere {
                  <0,0,0>, 0.4
                  pigment {color rgb <0.9,0.8,0.8>}
                }
                object { teta rotate <-5,10,0> translate <-0.15,0.15,-0.35> }
                object { teta rotate <-5,10,0> translate <-0.15,-0.15,-0.35> }
                object { teta rotate <-5,-10,0> translate <0.15,0.15,-0.35> }
                object { teta rotate <-5,-10,0> translate <0.15,-0.15,-0.35> }
        }
        
        // Casco/p� da vaca
        #local casco = box {
                  <-0.1,-0.12,-0.1>, <0.1,0.12,0.1>
                  pigment {color Black}
        }
        
        // Antebra�o da vaca
        #local antebraco = union {
                cylinder{
                  <0,-0.2,0>, <0,0.2,0>, 0.1
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                box {
                  <-0.1,-0.12,-0.1>,<0.1,0.12,0.1>
                  translate <0,-0.25,0>
                  pigment {color Black}     // Detalhe preto no antebra�o
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
        
        // Bra�o da vaca
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
        
        // Perna traseira modificada para posi��o sentada
        #local perna_traseira = union {
                // Coxa
                cylinder {
                  <0,0,0>, <0,-0.4,0>, 0.12
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                // Canela
                cylinder {
                  <0,-0.4,0>, <0,-0.7,0>, 0.1
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object { casco translate <0,-0.8,0> }
        }
        
        // Perna dianteira modificada para posi��o sentada (mais relaxada)
        #local perna_dianteira = union {
                // Bra�o
                cylinder {
                  <0,0,0>, <0,-0.3,0>, 0.11
                  pigment {color Yellow}
                }
                // Antebra�o
                cylinder {
                  <0,-0.3,0>, <0.05,-0.55,-0.1>, 0.09
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                  rotate <20,0,0>
                  translate <0,0,-0.05>
                }
                object { casco translate <0.05,-0.7,-0.1> }
        }
        
        // Corpo da vaca sentada
        #local corpo_sentado = union {
                // Torso mais vertical para posi��o sentada
                sphere {
                  <0,0,0>, 1
                  scale <0.5,0.8,0.6>
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                
                // Pesco�o e cabe�a
                object { 
                pescoco 
                rotate <-30, 0, 0> 
                translate <0, 0.7, -0.1> 
                }
                
                // Mamas
                object { mamas translate <0,-0.2,-0.4> }
                
                // Pernas traseiras em posi��o sentada
                object { 
                    perna_traseira 
                    rotate <-30,0,0>
                    translate <0.18,-0.4,-0.1>
                }
                object { 
                    perna_traseira 
                    rotate <-30,0,0>
                    translate <-0.18,-0.4,-0.1>
                }
                
                // Pernas dianteiras relaxadas
                object {
                    braco
                    translate <0,-0.2,0>
                    rotate <0,-10,0>
                    rotate <0,0,30>
                    translate <0.3,0.8,0>
                }
                object {
                    braco
                    translate <0,-0.2,0>
                    rotate <0,10,0>
                    rotate <0,0,-30>
                    translate <-0.3,0.8,0>
                }
        }
        
        object { corpo_sentado }
#end

/*
  ****************************************************************************************
  ************************   MACRO VACA BOXEADORA  ***************************************
  ****************************************************************************************
*/
#macro vaca_boxeadora()
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
                  <-0.2,-0.24,-0.2>,<0.2,0.24,0.2>
                  translate <0,-0.25,0>
                  pigment {color Red}     // Luva de boxe
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
                  translate <0.22,-0.8,0>
                }
                object {
                  perna
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

/*
  ****************************************************************************************
  ************************   MACRO VACA FALANDO  *****************************************
  ****************************************************************************************
*/
#macro vaca_falando()
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
                  translate <0.22,-0.8,0>
                }
                object {
                  perna
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

/*
  ****************************************************************************************
  ************************   MACRO VACA GOLPE ********************************************
  ****************************************************************************************
*/

#macro vaca_golpe()
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
                  rotate <0, 0, 40>
                  translate <0.22,-0.8,0>
                }
                object {
                  perna
                  rotate <0, 0, 40>
                  translate <-0.22,-0.8,0>
                }
                object {
                  braco
                  translate <0,-0.2,0>
                  rotate <0,-10,50>
                  rotate <0,0,30>
                  translate <0.3,0.8,0>
                }
                object {
                  braco
                  translate <0,-0.2,0>
                  rotate <0,10,0>
                  rotate <0,0,-30>
                  translate <-0.3,0.8,0>
                }
        }
        
        object {corpo}    // Desenha a vaca completa
    
#end
/*
  ****************************************************************************************
  ************************   MACRO VACA ACENANDO *****************************************
  ****************************************************************************************
*/

#macro vaca_acenando()
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

        #local bracoEsquerdo = union {
                cylinder{
                  <0,-0.3,0>, <0,0.3,0>, 0.1
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object {
                  cotovelo
                  rotate <0 , 0+ sin(clock * 4 * pi) * 30, 0>
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
                  translate <0.22,-0.8,0>
                }
                object {
                  perna
                  translate <-0.22,-0.8,0>
                }
                object {
                  bracoEsquerdo
                  translate <0,-0.2,0>
                  rotate <0,-10,80>
                  rotate <0,0,30>
                  translate <0.3,0.8,0>
                }
                object {
                  braco
                  translate <0,-0.2,0>
                  rotate <0,10,0>
                  rotate <0,0,-30>
                  translate <-0.3,0.8,0>
                }
        }
        
        object {corpo}    // Desenha a vaca completa
    
#end

/*
  ****************************************************************************************
  ************************   MACRO VACA POSE *********************************************
  ****************************************************************************************
*/

#macro vaca_pose()
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
                  rotate <0, 0, 0 - sin(clock * 4 * pi) * 30>
                  translate <0, 1 ,0>
                }
                object {
                  mamas
                  translate <0,-0.3,-0.5>
                }
                object {
                  perna
                  translate <0.22,-0.8,0>
                }
                object {
                  perna
                  rotate <0, 0, -80>
                  translate <-0.22,-0.8,0>
                }
                object {
                  braco
                  translate <0,-0.2,0>
                  rotate <0,-10,50>
                  rotate <0,0,30>
                  translate <0.3,0.8,0>
                }
                object {
                  braco
                  translate <0,-0.2,0>
                  rotate <0,10,-80>
                  rotate <0,0,-30>
                  translate <-0.3,0.8,0>
                }
        }
        
        object {corpo}    // Desenha a vaca completa
    
#end