#include "shapes.inc"      // Inclusão de formas básicas do POV-Ray
#include "textures.inc"    // Inclusão de texturas básicas
#include "colors.inc"      // Inclusão das cores padrão
#include "woods.inc"       // Inclusão de texturas de madeira
#include "metals.inc"      // Inclusão de texturas metálicas
#include "../Base/base.inc"     // Inclusão dos modelos vaca e cadeira
#include "../Base/vaca.inc"

// Declaração de variável para deslocamento que varia com o tempo (clock)
#declare deslocamento = -clock*5;

#macro vaca_na_cadeira()
        union {
            // Cadeira
            cadeira()
            
            // Vaca sentada posicionada na cadeira
            object {
                vaca_sentada()
                scale <0.8, 0.8, 0.8>  // Reduz um pouco o tamanho da vaca
                translate <0, 0.4, -0.5>   // Eleva a vaca para ficar sobre o assento
            }
        }
#end

// Céu esférico
sky_sphere {
  pigment {
    gradient z   // Gradiente na direção z (vertical)
    color_map {
      [0.5 color <0, 0, 0>] // Preto
      [1.0 color MidnightBlue] // Azul escuro no topo
    }
    scale 2   
  }

}

// Plano horizontal roxo representando o chão
plane {
  y, -0.1
  texture {
    pigment {
      marble
      color_map {
        [0.0 rgb <0.3, 0.1, 0.4>]   // Roxo escuro
        [0.6 rgb <0.3, 0.1, 0.4>]   // Roxo m�dio
        [0.8 rgb <0.65, 0.32, 0.4>]   // Rosa
        [0.9 rgb <0.34, 0.29, 0.19>]   // Marrom
        [1.0 rgb <0.3, 0.1, 0.4>]   // Roxo muito escuro
      }
      turbulence 0.8
      scale 3
    }
    finish {
      ambient 0.2
      diffuse 0.6
      specular 0.1
      reflection 0.05
    }
  }
}

//pigment {color rgb <0.43, 0.21, 0.64>}  // Cor roxa para o chão

// Fonte de luz principal, área de luz
light_source {
  <0, 15, -45>         // Posição da luz
  color White          // Cor da luz branca
  area_light <30, 0, 0>, <0, 0, 30>, 2, 2   // Luz de área para sombras suaves
  adaptive 1           // Ajuste adaptativo para qualidade
  jitter               // Aleatoriza a luz para suavizar sombras
}

// Segunda fonte de luz mais distante e intensa
light_source {
  <0, 300, -500>       // Luz distante para iluminação geral
  color White
}


// câmera posicionada do lado esquerdo
camera {
  location <-54 + deslocamento, 9, 27 - (deslocamento*0.7)>     // Posição da câmera
  //location <-54, 9, 27>
  look_at <-62, 7, 41>      // Direção que a câmera está olhando
}

// ******  CENÁRIO  ******
// Instancia e posiciona o objeto 'casa' (casa)

// Instancia e posiciona a vaca
object {
  vaca_na_cadeira()
  scale <3, 3, 3>
  translate <-60, 6, 40>  // deslocamento da vaca no eixo Z
}
