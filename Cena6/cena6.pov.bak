#include "shapes.inc"      // Inclusão de formas básicas do POV-Ray
#include "textures.inc"    // Inclusão de texturas básicas
#include "colors.inc"      // Inclusão das cores padrão
#include "woods.inc"       // Inclusão de texturas de madeira
#include "metals.inc"      // Inclusão de texturas metálicas
#include "../Base/base.inc"
#include "../Base/vaca.inc"
#include "../Base/vacaVelha.inc"

// Declaração de variável para deslocamento que varia com o tempo (clock)
#declare deslocamento = -clock*40;

// Céu esférico com gradiente e efeito de nuvens turbulentas
sky_sphere {
  pigment {
    gradient z   // Gradiente na direção z (vertical)
    color_map {
      [0.5 color <0, 0.74609375, 0.99609375>] // Azul claro no meio
      [1.0 color MidnightBlue]                 // Azul escuro no topo
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
  look_at <-60, 7, 30>      // Direção que a câmera está olhando
}

// ******  CENÁRIO  ******

// Instancia e posiciona a primeira árvore
object {
  arvore()
  scale <10, 10, 10>
  rotate <0, -70, 0>
  translate <-60, 6, 50>
}

// Instancia e posiciona a vaca
object {
  vaca_boxeadora()
  scale <3, 3, 3>
  rotate <0, 200, 0>
  translate <-65, 6, 40>  
}

// Vaca velha
object {
  vaca_velha()
  scale <3, 3, 3>
  rotate <0, 250, 0>
  translate <-78, 6, 30>  
}

// Saco de pancadas
union {
  object {
    sacoDePancadas()
    scale <4, 4, 4>
    translate <0, -6.2, 0> // Move o topo at� a origem antes de rotacionar
  }

  rotate <0, 0, sin(clock * 4 * pi) * 10> // Aplica a rota��o
  translate <-62, 5 + 6.2, 42.5> // Devolve para a posi��o final no mundo
}