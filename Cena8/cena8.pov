#include "shapes.inc"      // Inclus�o de formas b�sicas do POV-Ray
#include "textures.inc"    // Inclus�o de texturas b�sicas
#include "colors.inc"      // Inclus�o das cores padr�oAdd commentMore actions
#include "woods.inc"       // Inclus�o de texturas de madeira
#include "metals.inc"      // Inclus�o de texturas met�licas
#include "../Base/base.inc"     // Inclusão dos modelos bases do projeto
#include "../Base/vacaDourada.inc" // Inclusão do modelo da vaca dourada
#include "../Base/vaca.inc"

// Declaração de variável para deslocamento que varia com o tempo (clock)
#declare deslocamento = -clock*10;

// Céu esférico com gradiente e efeito de nuvens turbulentas
sky_sphere {
  pigment {
    gradient z   // Gradiente na direção z (vertical)
    color_map {
      [0.5 color <0.85, 0.48, 0.48>] //  <1, 0.52, 0>
      [1.0 color <1, 0.52, 0>] //<0.85, 0.48, 0.48>               
    }
    scale 2   
  }
  pigment {
    bozo                // Efeito de nuvem tipo "bozo"
    turbulence 0.9      // Turbulência para nuvens realistas
    omega 0.7           // Frequência de turbulência
    color_map {
      [0.0 color rgb <0.85, 0.85, 0.85>]     // Cinza claro na base
      [0.1 color rgb <0.75, 0.75, 0.75>]     // Cinza um pouco mais escuro
      [0.5 color rgbt <1,1,1,1>]              // Branco translúcido no meio
      [1.0 color rgbt <1,1,1,1>]              // Branco translúcido no topo
    }
    scale <0.6, 0.3, 0.3>                     // Escala do efeito turbulento
  }
}


// Plano horizontal verde representando o chão
plane {
  y, 0             // Plano no eixo Y, na altura 0 (chão)
  pigment {color Green}  // Cor verde para o chão
}


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
  location <-50, 7, 20>     // Posição da câmera
  look_at <-60 - deslocamento, 7, 30>      // Direção que a câmera está olhando
}


// ******  CENÁRIO  ******


object {
    vaca_dourada_ajoelhada()
    scale <4, 4, 4>       
    rotate <0, -40, 0>
    translate <-60, 5, 40>
}

//Vaca
object {
    vaca()
    scale <3, 3, 3>
    rotate <0, 150, 0>
    translate <-65, 5, 25>
}

//Vaca filho
object {
    vaca_acenando()
    scale <2, 2, 2>
    translate <-50, 4, 40>
}