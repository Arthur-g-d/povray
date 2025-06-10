/*
  ****************************************************************************************
  ************************   MACRO ÁRVORE   **********************************************
  ****************************************************************************************
*/

#macro arvore()
        // Coroa da árvore - uma esfera verde com textura irregular
        #local coroa = sphere {
          <0,0,0>
          0.4
          pigment {color Green}  // pigmento verde
          normal {
            bumps 1               // textura com relevo (bumps)
            scale 0.1             // escala da textura
          }
        }

        // Galho da árvore - cilindro marrom com uma coroa no topo
        #local galho = union {
                cylinder {
                  <0, -0.9, 0>
                  <0, 0.9, 0>
                  0.1
                  pigment {color Brown} // pigmento marrom (cor de madeira)
                }
                object {
                  coroa                // adiciona a coroa ao topo do galho
                  translate <0, 0.7, 0> // posiciona a coroa acima do cilindro
                } 
        }

        // Tronco da árvore com ramificações maiores e menores
        #local tronco = union {
                cylinder {
                  <0, -1, 0>
                  <0, 1, 0>
                  0.4
                  pigment {color Brown} // pigmento marrom do tronco
                }
                // Extensões do tronco - galhos maiores
                object {
                  galho
                  scale <1.5, 1.5, 1.5> // aumenta o tamanho do galho
                  translate <0, 1.5, 0> // posiciona mais acima no tronco
                  rotate <15, 0, 20>    // rotaciona o galho
                  translate <-0.2, 0.2, 0> // pequeno ajuste na posição
                }
                object {
                  galho
                  scale <2, 1.7, 2>     // galho maior e mais largo
                  translate <0, 1.7, 0>
                  rotate <5, 0, -10>
                  translate <-0.2, 0.2, 0>
                }
                // Galhos menores
                object {
                  galho
                  translate <0, 0.6, 0>
                  rotate <0, 0, 40>
                  //rotate <0, 90, 0>     // comentado: possível rotação adicional
                  translate <-0.2, 0, 0>
                }
                object {
                  galho
                  translate <0, 0.8, 0>
                  rotate <0, 0, 40>
                  rotate <0, 90, 0>      // rotação em Y para orientação lateral
                  translate <0, 0, -0.2>
                }
                object {
                  galho
                  translate <0, 0.9, 0>
                  rotate <0, 0, -40>
                  translate <-0.2, 0.2, 0>
                }
                object {
                  galho
                  translate <0, 0.9, 0>
                  rotate <0, 0, -40>
                  rotate <0, 40, 0>
                  translate <-0.2, 0.2, 0>
                }
        }

        // Desenha o tronco com seus galhos
        object {
          tronco
        }
#end
/*
  ****************************************************************************************
  ************************   MACRO CADEIRA   *********************************************
  ****************************************************************************************
*/

#macro cadeira()
        // Cor met�lica azul para a cadeira
        #local cor_metal_azul = <0.2, 0.4, 0.8>;
        
        // Textura met�lica com acabamento brilhante
        #local textura_metal = texture {
            pigment { color cor_metal_azul }
            finish {
                ambient 0.1
                diffuse 0.6
                specular 0.8
                roughness 0.01
                metallic
                reflection 0.3
            }
        }
        
        // Cor met�lica para a cadeira
        #local cor_metal = <0.6, 0.6, 0.6>;
        
        // Textura met�lica com acabamento brilhante
        #local textura_metal2 = texture {
            pigment { color cor_metal }
            finish {
                ambient 0.1
                diffuse 0.6
                specular 0.8
                roughness 0.01
                metallic
                reflection 0.3
            }
        }
        
        // Assento da cadeira - placa retangular
        #local assento = box {
            <-0.25, -0.02, -0.25>
            <0.25, 0.02, 0.25>
            texture { textura_metal }
        }
        
        // Encosto da cadeira - placa vertical
        #local encosto = box {
            <-0.25, -0.01, -0.02>
            <0.25, 0.4, 0.02>
            texture { textura_metal }
        }
        
        // Pernas da cadeira
        #local perna_fe = cylinder {
            <0, -0.5, 0>, <0, 0, 0>, 0.02
            texture { textura_metal2 }
        }
        
        #local perna_fd = cylinder {
            <0, -0.5, 0>, <0, 0, 0>, 0.02
            texture { textura_metal2 }
        }
        
        #local perna_te = cylinder {
            <0, -0.5, 0>, <0, 0.4, 0>, 0.02
            texture { textura_metal2 }
        }
        
        #local perna_td = cylinder {
            <0, -0.5, 0>, <0, 0.4, 0>, 0.02
            texture { textura_metal2 }
        }
        
        // Barras de apoio
        #local apoio_lateral_esq = cylinder {
            <0, 0, -0.25>, <0, 0, 0.25>, 0.015
            texture { textura_metal2 }
        }
        
        #local apoio_lateral_dir = cylinder {
            <0, 0, -0.25>, <0, 0, 0.25>, 0.015
            texture { textura_metal2 }
        }
        
        #local apoio_frontal = cylinder {
            <-0.25, 0, 0>, <0.25, 0, 0>, 0.015
            texture { textura_metal2 }
        }
        
        #local apoio_traseiro = cylinder {
            <-0.25, 0, 0>, <0.25, 0, 0>, 0.015
            texture { textura_metal2 }
        }
        
        // Montagem completa da cadeira
        #local cadeira_completa = union {
            object { assento translate <0, 0, 0> }
            object { encosto translate <0, 0.2, 0.25> }
            object { perna_fe translate <-0.22, 0, -0.22> }
            object { perna_fd translate <0.22, 0, -0.22> }
            object { perna_te translate <-0.22, 0, 0.22> }
            object { perna_td translate <0.22, 0, 0.22> }
            object { apoio_frontal translate <0, -0.5, -0.22> }
            object { apoio_traseiro translate <0, -0.5, 0.22> }
        }
        
        object {
            cadeira_completa
            scale <2, 2, 2>
        }
#end

/*
  ****************************************************************************************
  ************************   MACRO SACO DE PANCADAS   ************************************
  ****************************************************************************************
*/
#macro sacoDePancadas()
union {
  // Saco principal (cilindro)
  cylinder {
    <0, 0, 0>, <0, 1.2, 0>, 0.25
    texture {
      pigment { color rgb <0.8, 0.1, 0.1> }
      finish { phong 0.3 }
    }
  }

  // Tampa superior (pequeno disco)
  torus {
    0.25, 0.02
    rotate <90, 0, 0>
    translate <0, 1.2, 0>
    texture {
      pigment { color rgb <0.4, 0.4, 0.4> }
      finish { phong 0.5 }
    }
  }

  // Corrente simples (3 elos pequenos)
  #declare EloAltura = 0.1;
  #declare EloRaio = 0.05;
  #declare i = 0;
  #while (i < 3)
    torus {
      EloRaio, 0.01
      rotate <90, 0, 0>
      translate <0, 1.25 + i * EloAltura, 0>
      texture {
        pigment { color rgb <0.6, 0.6, 0.6> }
        finish { phong 0.6 }
      }
    }
    #declare i = i + 1;
  #end

  // Suporte superior (barra horizontal com haste)
  union {
    // Barra horizontal
    cylinder {
      <-0.5, 1.6, 0>, <0.5, 1.6, 0>, 0.03
    }

    // Haste vertical do suporte até a corrente
    cylinder {
      <0, 1.6, 0>, <0, 1.55, 0>, 0.015
    }

    texture {
      pigment { color rgb <0.3, 0.3, 0.3> }
      finish { phong 0.4 }
    }
  }
}
#end



